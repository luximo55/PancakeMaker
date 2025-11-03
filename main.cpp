#include <iostream>
#include <cmath>
#include <vector>


using namespace std;

//Pancakes class that defines different types of pancakes
class Pancakes{
    public:
        string name = "Regular";
        vector<string> ingredients;

    //Initializes main attributes for different types of pancakes
    Pancakes(int size, string type){
        ingredients.resize(size);
        if(type == "regular"){
            ingredients[0] = "Milk";
            ingredients[1] = "Flour";
            ingredients[2] = "Eggs";
        } else if(type == "oat"){

        }
    }
};


int ingredientCalc()
{
    /*The amount of pancakes is calculated with following amount (per 10 pancakes):
        Milk - 250ml
        Flour - 100g
        Eggs - 2
    */
    //These formulas could be shortened from 250*10 to 25(yes, this is correct, dw), but for readability it's kept as is
    //Amounts are being divided by amount of ingredients needed for 10 pancakes, and then multiplied by 10
    double milkAmt;
    double flourAmt;
    int eggAmt;
    int totalPancakes;
    //Milk
    cout << "How much milk do you have?" << endl;
    cin >> milkAmt;
    cout << "You have milk for " << floor(milkAmt / 250 * 10) << " pancakes." << endl;

    //Flour
    cout << "How much flour do you have?" << endl;
    cin >> flourAmt;
    cout << "You have flour for " << floor(flourAmt / 100 * 10) << " pancakes." << endl;

    //Eggs
    cout << "How many eggs do you have?" << endl;
    cin >> eggAmt;
    cout << "You have eggs for " << floor((double)eggAmt / 2 * 10) << " pancakes.\n" << endl;

    //Final calculation
    //The program finds the lowest amount of pancakes that can be made with provided ingredients
    totalPancakes = floor(fmin(fmin(milkAmt/250*10, flourAmt/100*10), (double)eggAmt/2*10));
    if(totalPancakes > 0){
        cout << "You can make " << totalPancakes << " pancakes!" << endl;
    } else if(totalPancakes == 0){
        cout << "You cannot make any pancakes. :(" << endl;
    }
    cout << "Press any key to continue...";
    cin.ignore();
    cin.get();
    system("cls");
    return totalPancakes;
}

void instructions(int numOfPancakes, string pancakeType)
{
    //instructions based of the number of pancakes we can make
    //calculate the amount of each ingredient
    switch (pancakeType)
    case "regular":
        double recipeMilk = (double)numOfPancakes / 10 * 250;
        double recipeFlour = (double)numOfPancakes / 10 * 100;
        int recipeEggs = (double)numOfPancakes / 10 * 2;
        cout << "To make " << numOfPancakes <<", you're going to need:\n" << recipeMilk << "ml of milk\n" << recipeFlour << "g, of flour\n" << recipeEggs << " eggs" << endl;
        cout << "Press any key to continue...";
        cin.ignore();
        cin.get();
        system("cls");
        //--Recipe instructions--
        break;
    case "oat":
        //--Ingredients--
        //--Recipe instructions--
        break;
}

int main()
{
    int usrChoice;
    int numOfPancakes;
    string pancakeChoice = "regular";
    Pancakes regular(3, "regular");
    Pancakes oat(3, "oat");

    cout << "Welcome to Pancake Maker: Cpp edition!\nThis program is made as a practice project for learning cpp" << endl;
    //The main menu we return to when we want to choose options
    menu:
    cout << "Choose what you'd like to do:\n1 Walk-through\n2 Ingredient calculator\n3 Ingredients (Additional recipes)\n4 Pancake type\n0 Quit" << endl;
    cin >> usrChoice;
    switch (usrChoice){
    //Walk-through
    //It runs the calculator and the recipe, linking the two together so that the recipe is adjusted for the amount
    case 1:
        system("cls");
        numOfPancakes = ingredientCalc();
        instructions(numOfPancakes, pancakeChoice);
        break;
    //Ingredient calculator
    //Runs the calculator to calculate how many pancakes can be made with provided ingredients
    case 2:
        system("cls");
        ingredientCalc();
        break;
    //Ingredietns
    //Runs a list of ingredients for other types of pancakes
    case 3:{
        system("cls");
        string pancakeChoice;
        cout << "Choose what type of pancakes you'd like to see ingredients of (1. Regular, 2. Oat): ";
        cin >> pancakeChoice;
        if(pancakeChoice == "Regular" || pancakeChoice == "regular"){
            for(int i = 0; i < size(regular.ingredients); i++){
                cout << regular.ingredients[i] << endl;
            }
        } else if(pancakeChoice == "Oat" || pancakeChoice == "oat"){
            for(int i = 0; i < size(regular.ingredients); i++){
                cout << oat.ingredients[i] << endl;
            }
        }
        cout << "Press any key to continue...";
        cin.ignore();
        cin.get();
        break;
    }
    case 4:
        system("cls");
        cout << "Current pancake type: " << pancakeChoice << endl;
        cout << "What would you like to do:\n1 Regular pancakes\n2 Oat pancakes\n0 Back to menu" << endl;
        cin >> usrChoice;
        switch (usrChoice)
        {
        case 1:
            pancakeChoice = "regular";
            system("cls");
            break;
        case 2:
            pancakeChoice = "oat";
            system("cls");
            break;
        case 0:
            system("cls");
            break;
        default:
            break;
        }
        break;
    //Quit
    case 0:
        system("cls");
        cout << "See you next time!";
        return 0;
    //Invalid input handler
    default:
        system("cls");
        cout << "Invalid choice." << endl;
    }
    //Return to menu when exiting from the switch (happens when finishing with the use of one of the tools)
    goto menu;
}

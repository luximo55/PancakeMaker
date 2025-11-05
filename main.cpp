#include <iostream>
#include <cmath>
#include <vector>


using namespace std;

/*  In many functions in else ifs and similar functions have comments only on the first instance of that type of calculation
    So a calculation in else if that is done in a same or a similar way as in its if part will not be explained due to ambiguity
*/
//Pancakes class that defines different types of pancakes
class Pancakes{
    public:
        string name = "Regular";
        vector<string> ingredients;
        vector<int> ingredientAmt;

    //Initializes main attributes for different types of pancakes
    Pancakes(int size, string type){
        ingredients.resize(size);
        ingredientAmt.resize(size);
        if(type == "regular"){
            ingredients[0] = "Milk";
            ingredientAmt[0] = 250;
            ingredients[1] = "Flour";
            ingredientAmt[1] = 100;
            ingredients[2] = "Eggs";
            ingredientAmt[2] = 2;
        } else if(type == "oat"){
            ingredients[0] = "Milk";
            ingredientAmt[0] = 500;
            ingredients[1] = "Oats";
            ingredientAmt[1] = 200;
            ingredients[2] = "Eggs";
            ingredientAmt[2] = 2;
            ingredients[3] = "Baking powder";
            ingredientAmt[3] = 12;
        }
    }
};


int ingredientCalc(string pancakeType)
{
    int totalPancakes;
    if(pancakeType == "regular"){
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
    }else if(pancakeType == "oat"){
        /*The amount of pancakes is calculated with following amount (per 10 pancakes):
            Milk - 500ml
            Oats - 200g
            Eggs - 2
            Baking powder - 12g
        */
        double milkAmt;
        double oatAmt;
        int eggAmt;
        double bakPowAmt;

        //Milk
        cout << "How much milk do you have?" << endl;
        cin >> milkAmt;
        cout << "You have milk for " << floor(milkAmt / 500 * 10) << " pancakes." << endl;

        //Flour
        cout << "How much oats do you have?" << endl;
        cin >> oatAmt;
        cout << "You have oats for " << floor(oatAmt / 200 * 10) << " pancakes." << endl;

        //Eggs
        cout << "How many eggs do you have?" << endl;
        cin >> eggAmt;
        cout << "You have eggs for " << floor((double)eggAmt / 2 * 10) << " pancakes." << endl;
        //Baking powder
        cout << "How much baking powder do you have?" << endl;
        cin >> bakPowAmt;
        cout << "You have baking powder for " << floor((double)bakPowAmt / 12 * 10) << " pancakes.\n" << endl;

        //Final calculation
        totalPancakes = floor(fmin(fmin(milkAmt/500*10, oatAmt/200*10), fmin((double)eggAmt/2*10, bakPowAmt/12*10)));
    }

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
    if (pancakeType == "regular"){
        double recipeMilk = (double)numOfPancakes / 10 * 250;
        double recipeFlour = (double)numOfPancakes / 10 * 100;
        int recipeEggs = (double)numOfPancakes / 10 * 2;
        cout << "To make " << numOfPancakes <<", you're going to need:\n" << recipeMilk << "ml of milk\n" << recipeFlour << "g of flour\n" << recipeEggs << " eggs" << endl;
        cout << "Press any key to continue...";
        cin.ignore();
        cin.get();
        system("cls");
        //--Recipe instructions--
    } else if(pancakeType == "oat"){
        double recipeMilk = (double)numOfPancakes / 10 * 500;
        double recipeOats = (double)numOfPancakes / 10 * 200;
        int recipeEggs = (double)numOfPancakes / 10 * 2;
        double recipeBakPow = (double)numOfPancakes / 10 * 12;
        cout << "To make " << numOfPancakes <<", you're going to need:\n" << recipeMilk << "ml of milk\n" << recipeOats << "g of oats\n" << recipeEggs << " eggs\n" << recipeBakPow << "g of baking powder" << endl;
        cout << "Press any key to continue...";
        cin.ignore();
        cin.get();
        system("cls");
        //--Recipe instructions--
    }
}

int main()
{
    int usrChoice;
    int numOfPancakes;
    string pancakeChoice = "regular";
    Pancakes regular(3, "regular");
    Pancakes oat(4, "oat");

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
        numOfPancakes = ingredientCalc(pancakeChoice);
        instructions(numOfPancakes, pancakeChoice);
        break;

    //Ingredient calculator
    //Runs the calculator to calculate how many pancakes can be made with provided ingredients
    case 2:
        system("cls");
        ingredientCalc(pancakeChoice);
        break;

    //Ingredietns
    //Runs a list of ingredients for a chosen pancake type
    case 3:{
        system("cls");
        pancakeChoice;
        int pancakeAmt;
        cout << "How many " << pancakeChoice << " pancakes would you like to make?" << endl;
        cin >> pancakeAmt;
        cout << "To make " << pancakeAmt << " " << pancakeChoice << " pancakes you're going to need:" << endl;
        if(pancakeChoice == "regular"){
            for(int i = 0; i < size(regular.ingredients); i++){
                cout << regular.ingredients[i] << " - ";
                switch (i){
                case 0:
                    cout << (double)pancakeAmt / 10 * 250 << "ml" << endl;
                    break;
                case 1:
                    cout << (double)pancakeAmt / 10 * 100 << "g" << endl;
                    break;
                case 2:
                    cout << (double)pancakeAmt / 10 * 2 << endl;
                    break;
                }
            }
        } else if(pancakeChoice == "oat"){
            for(int i = 0; i < size(oat.ingredients); i++){
                cout << oat.ingredients[i] << " - ";
                switch (i){
                case 0:
                    cout << (double)pancakeAmt / 10 * 500 << "ml" << endl;
                    break;
                case 1:
                    cout << (double)pancakeAmt / 10 * 200 << "g" << endl;
                    break;
                case 2:
                    cout << (double)pancakeAmt / 10 * 2 << endl;
                    break;
                case 3:
                    cout << (double)pancakeAmt / 10 * 12 << "g" << endl;
                    break;
                }
            }
        }
        cout << "Press any key to continue...";
        cin.ignore();
        cin.get();
        system("cls");
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

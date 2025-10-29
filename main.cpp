#include <iostream>
#include <cmath>
#include <vector>


using namespace std;

class Pancakes{
    public:
        string name = "Regular";
        vector<string> ingredients;

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
    totalPancakes = floor(fmin(fmin(milkAmt/200*10, flourAmt/200*10), (double)eggAmt/2*10));
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

void instructions(int numOfPancakes)
{
    //instructions based of the number of pancakes we can make
    //calculate the amount of each ingredient
    cout << numOfPancakes << "\ninstructions in works" << endl;
}

int main()
{
    int usrChoice;
    int numOfPancakes;
    Pancakes regular(3, "regular");
    Pancakes oat(3, "oat");

    cout << "Welcome to Pancake Maker: Cpp edition!\nThis program is made as a practice project for learning cpp" << endl;
    //The main menu we return to when we want to choose options
    menu:
    cout << "Choose what you'd like to do:\n1 Walk-through\n2 Ingredient calculator\n3 Ingredients (Additional recipes)\n0 Quit" << endl;
    cin >> usrChoice;
    switch (usrChoice){
    case 1:
        system("cls");
        numOfPancakes = ingredientCalc();
        instructions(numOfPancakes);
        break;
    case 2:
        system("cls");
        ingredientCalc();
        break;
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

        cout << "temp 3" << endl;
        cout << "Press any key to continue...";
        cin.ignore();
        cin.get();
        break;
    }
    case 0:
        system("cls");
        cout << "See you next time!";
        return 0;
    default:
        system("cls");
        cout << "Invalid choice." << endl;
    }
    goto menu;
}

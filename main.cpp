#include <iostream>
#include <cmath>

using namespace std;

int ingredientCalc()
{
    double milkAmt;
    double flourAmt;
    int eggAmt;
    int totalPancakes;
    //Milk
    cout << "How much milk do you have?" << endl;
    cin >> milkAmt;
    cout << "You have milk for " << floor(milkAmt / 200 * 10) << " pancakes." << endl;

    //Flour
    cout << "How much flour do you have?" << endl;
    cin >> flourAmt;
    cout << "You have flour for " << floor(flourAmt / 200 * 10) << " pancakes." << endl;

    //Eggs
    cout << "How many eggs do you have?" << endl;
    cin >> eggAmt;
    cout << "You have eggs for " << floor(eggAmt / 2 * 10) << " pancakes.\n" << endl;

    //Final calculation
    totalPancakes = floor(fmin(fmin(milkAmt/200*10, flourAmt/200*10), eggAmt/2*10));
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

    cout << "Welcome to Pancake Maker: Cpp edition!\nThis program is made as a practice project for learning cpp" << endl;
    //The main menu we return to when we want to choose options
    menu:
    cout << "Choose what you'd like to do:\n1 Walk-through\n2 Ingredient calculator\n3 Ingredients\n0 Quit" << endl;
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
    case 3:
        system("cls");
        cout << "temp 3" << endl;
        break;
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

#include <iostream>

using namespace std;

void ingredientCalc()
{
    double milkAmt;
    double flourAmt;
    int eggAmt;
    ///Milk
    cout << "How much milk do you have?" << endl;
    cin >> milkAmt;
    cout << "You have milk for " << milkAmt / 200 * 10 << " pancakes" << endl;
    ///Flour
    cout << "How much flour do you have?" << endl;
    cin >> flourAmt;
    cout << "You have flour for " << flourAmt / 200 * 10 << " pancakes" << endl;
    ///Eggs
    cout << "How many eggs do you have?" << endl;
    cin >> eggAmt;
    cout << "You have eggs for " << eggAmt / 2 * 10 << " pancakes" << endl;


}

int main()
{
    int usrChoice;

    cout << "Welcome to Pancake Maker: Cpp edition!\nThis program is made as a practice project for learning cpp" << endl;
    ///The main menu we return to when we want to choose options
    menu:
    cout << "Choose what you'd like to do:\n1 Walk-through\n2 Ingredient calculator\n3 Ingredients\n0 Quit" << endl;
    cin >> usrChoice;
    switch (usrChoice){
    case 1:
        system("cls");
        ingredientCalc();
        break;
    case 2:
        system("cls");
        cout << "temp 2" << endl;
        break;
    case 3:
        system("cls");
        cout << "temp 3" << endl;
            break;
    case 0:
        system("cls");
        return 0;
    default:
        system("cls");
        cout << "Invalid choice." << endl;
    }
    goto menu;
}

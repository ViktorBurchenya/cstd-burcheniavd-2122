
#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <cstring>
using namespace std;

const int NAME_SIZE = 12;
const int NUM_DRINKS = 5;


struct Drink
{
    char name[NAME_SIZE];
    double price;
    int num;
};


int getChoice(Drink[]);
void transaction(Drink[], int, double&);

int main()
{

    int choice;


    double earnings = 0;


    Drink machine[NUM_DRINKS] = {
                        {"Cola     ", 0.75, 20},
                        {"Root Beer", .75, 20},
                        {"Lemon-Lime", .75, 20},
                        {"Grape Soda", .80, 20},
                        {"Cream Soda", .80, 20} };


    cout << fixed << showpoint << setprecision(2);


    choice = getChoice(machine);
    while (choice != 5)
    {

        transaction(machine, choice, earnings);


        choice = getChoice(machine);
    }


    cout << "Total earnings: $" << earnings << endl;
    return 0;
}



int getChoice(Drink m[])
{

    int choice;

    cout << endl;



    for (int x = 0; x < NUM_DRINKS; x++)
    {
        cout << (x + 1) << ") " << m[x].name << "\t\t";
        cout << m[x].price << endl;
    }


    cout << (NUM_DRINKS + 1)
        << ") Leave the drink machine\n\n";


    cout << "Choose one: "; cin >> choice;


    while (choice < 1 || choice > 6)
    {
        cout << "Bad choice. Choose one: "; cin >> choice;
    }


    return choice - 1;
}



void transaction(Drink m[], int choice, double& earnings)
{

    double money;


    if (m[choice].num == 0)
    {
        cout << "Sorry, that selection is sold out.\n";
        return;
    }


    cout << "Enter an amount of money: "; cin >> money;


    while (money < m[choice].price || money > 1.0)
    {
        cout << "Enter at least " << m[choice].price;
        cout << " and not more than 1 dollar.\n"; cin >> money;
    }

    if (money >= m[choice].price)
    {

        cout << "\nhave a nice day!\n"
            << "Enjoy your beverage!\n\n";


        cout << "Change calculated: "
            << (money - m[choice].price)
            << endl;
        cout << "Your change, " << (money - m[choice].price)
            << " has just dropped into the Change Dispenser.\n\n";


        earnings += m[choice].price;


        m[choice].num--;


        cout << "There are " << m[choice].num
            << " drinks of that type left.\n";
    }
}
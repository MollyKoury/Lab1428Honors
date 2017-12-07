#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;
void betFunc(int &myMoney, int &bet, int &userDie, int &compDie, char &choice);
void getRolls (int &myMoney, int &bet, int &userDie, int &compDie, char &choice);
void results(int &myMoney, int &bet, int &userDie, int &compDie, char &choice);

int main()
{
    cout << "Gambling is an addiction..." << endl << endl;

    int myMoney = 1000, bet;
    int userDie, compDie;
    char choice;

    do
    {
        betFunc( myMoney, bet, userDie, compDie, choice);

        if( myMoney == 0)
            {
                choice = 'n';
                cout << endl << "hi" << endl;
            }

    }while(choice != 'n');

    if (myMoney == 0)
    {
        cout << "You ran out of money :(" << endl << endl;
    }
    else if (choice == 'n' || choice == 'N')
    {
        cout << "You chose to end the game" << endl << endl;
    }

    cout << "You ended with $" << myMoney << endl;

    return 0;
}

void betFunc(int &myMoney, int &bet, int &userDie, int &compDie, char &choice)
{
    cout << "You currently have $" << myMoney << endl << "How much do you bet?" <<  endl << "$";
    cin >> bet;

    if( bet < 0 || bet > myMoney)
    {
        cout << endl << "You do not have that amount of money available" << endl << endl;
        bet = 0;
    }
    else
    {
        getRolls( myMoney, bet, userDie, compDie, choice);
    }
}

void getRolls (int &myMoney, int &bet, int &userDie, int &compDie, char &choice)
{
    srand(time(NULL));
    userDie = rand() % 6 + 1;
    compDie = rand() % 6 + 1;

    cout << "You rolled a " << userDie << endl << "Your opponent rolled a " << compDie << endl;

    results( myMoney, bet, userDie, compDie, choice);
}

void results(int &myMoney, int &bet, int &userDie, int &compDie, char &choice)
{
    if( userDie > compDie)
    {
        cout << "You gain $" << bet << endl;
        myMoney += bet;
    }
    else if (userDie < compDie)
    {
        cout << "You lose $" << bet << endl;
        myMoney -= bet;
    }
    else if (userDie == compDie)
    {
        cout << "No money exchange" << endl;
    }

    if( myMoney != 0)
    {
        cout << endl << "Would you like to continue? ('y' or 'n')" << endl;
        cin >> choice;

        if(choice == 'N')
        {
            choice == 'n';
        }
    }
    else if (myMoney == 0)
    {
        choice == 'n';
    }
}

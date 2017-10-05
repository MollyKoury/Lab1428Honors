
#include <iostream>
#include <iomanip>

using namespace std;

int main ()
{

    double price, percent, tip;

    do
    {
        cout << endl << "Enter the price of the meal :: ";
        cin >> price;
        if(price < 0)
            cout << endl<< "Cannot enter a negative value" << endl;
    }while(price < 0);

    price = price / 100.00;

    do
    {
        cout << endl << "Enter percent amount you want to tip :: ";
        cin >> percent;
        if(percent < 0 || percent > 100)
            cout << endl<< "Cannot enter a percent less than 0 or greater than 100" << endl;
    }while(percent < 0 || percent > 100);

    tip = price * percent;

    cout << endl << "the tip is " << setprecision(2) << fixed << tip << endl;

    return 0;
}

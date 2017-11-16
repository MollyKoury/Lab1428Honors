
#include <iostream>

using namespace std;

int sumNumbers(int val);
int sumFib(int n);

int main()
{
    int val, n;

    cout << "Enter number for the sequence : ";
    cin >> val;
    n = val;

    val = sumNumbers(val);
    cout << endl << val << endl;

    n = sumFib(n);
    cout << endl << n << endl;

    return 0;
}

int sumNumbers(int val)
{
    if(val == 0)
    {
        return 1;
    }
    return val * sumNumbers(val - 1);
}

int sumFib(int n)
{
    if(n == 0)
    {
        return n;
    }
    if(n == 1)
    {
        return n;
    }
    return sumFib(n - 1) + sumFib(n - 2);
}


#include <iostream>

using namespace std;


const int size = 20;
int cycle[size];

bool IsPrime(int target);
bool IsHappy(int cycle[size], int target, int size, int index, int sum);
bool AddToCycle(int cycle[size], int target, int size, int index, int sum);
bool CycleContains(int cycle[size], int target, int size);
void SelectionSort(int cycle[size], int size);

int main()
{
    int target, index = 0;
    bool isPrime, isHappy;

    cin >> target;
    isPrime = IsPrime(target);
    isHappy = IsHappy(cycle, target, size, index, sum);

    if(isPrime && isHappy)
    {
        cout << target << " is a Happy Prime number." << endl;
    }
    else if(isPrime && !isHappy)
    {
        cout << target << " is only a Prime number." << endl;
    }
    else if(!isPrime && isHappy)
    {
        cout << target << " is only a Happy number." << endl;
    }
    else
    {
        cout << target << " is is neither a Happy nor a Prime number." << endl;
    }


    return 0;
}


bool IsPrime(int target)
{
    bool isPrime = true;

    for(int i = 2; i <= target / 2; ++i)
    {
        if(target % i == 0)
        {
            isPrime = false;
        }
    }
    if(isPrime)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool IsHappy(int cycle[size], int target, int size, int index, int sum)
{
    int digit, int sum = 0, int pos = 0;

    while(target != 1 && AddToCycle(cycle, target, size, index, sum))
    {
        sum = 0;
        while (target > 0)
        {
            digit = target % 10;
            target /=10;
            sum += digit * digit;
        }
        target = sum;
    }

    if(target == 1)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool AddToCycle(int cycle[size], int target, int size, int index, int sum)
{
    bool found = CycleContains(cycle, target, size);

    if(found)
    {
        return false;
    }
    else
    {
        index++;
        cycle[index] = sum;
        SelectionSort(cycle, size);

        return true;
    }
}

bool CycleContains(int cycle[size], int target, int size)
{
    for (int i = 0; i < size; i++)
    {
        if (cycle[i] == target)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
}

void SelectionSort(int cycle[size], int size)
{
    for (int i = 0; i < (size - 1); i++)
    {
        int min = i;
        for(int j = i + 1; j < size; j++)
        {
            if (cycle[j] < cycle[min])
            {
                min = j;
            }
        }
        if (min != i)
        {
            int temp = cycle[min];
            cycle[min] = cycle[i];
            cycle[i] = temp;
        }
    }
}

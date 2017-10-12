

#include <iostream>
#include <cstdlib>
#include <time.h>
using namespace std;

int main()
{
	//NUMBER OF ROWS AND COLUMNS
	const int ROWS = 10;
	const int COLS = 10;
	char life[ROWS][COLS];
	char hold[ROWS][COLS];

	int counter = 0, iteration =0, generation;

	//RANDOM NUMBER GENERATOR TO CREATE INITIAL GENERATION
	srand (time(NULL));
	int cell;

	for(int r=0; r<ROWS; r++)
	{
		for(int c =0; c<COLS;c++)
		{
			cell = rand() % 7;
			if(cell >= 5)
			{
				life[r][c] = '*';
			}
			else
			{
				life[r][c]=' ';
			}
		}
	}

	cout << "Enter the number of iterations ::   ";
	cin >> generation;

	do
    {
        cout << endl << "GEN " << iteration + 1 << endl;

        for(int r=0; r<ROWS; r++)       //Prints gen 1
        {
            for(int c =0; c<COLS;c++)
            {
                cout << life[r][c] << " ";
            }
            cout << endl;
        }

        for(int r=0; r<ROWS; r++)       // Determines dead or alive around
        {
            for(int c =0; c<COLS;c++)
            {
                counter = 0;

                if ( r-1 >= 0 && c-1 >= 0 && life[r-1][c-1] == '*')
                {
                    counter += 1;
                }
                if (r-1 >= 0 && life[r-1][c] == '*')
                {
                    counter += 1;
                }
                if (r-1 >= 0 && life[r-1][c+1] == '*')
                {
                    counter += 1;
                }
                if (c-1 >= 0 && life[r][c-1] == '*')
                {
                    counter += 1;
                }
                if (life[r][c+1] == '*')
                {
                    counter += 1;
                }
                if (c-1 >= 0 && life[r+1][c-1] == '*')
                {
                    counter += 1;
                }
                if (life[r+1][c] == '*')
                {
                    counter += 1;
                }
                if (life[r+1][c+1] == '*')
                {
                    counter += 1;
                }

                if (counter < 2)        // Determines life status
                {
                    hold[r][c] = ' ';
                }
                if (counter == 2)
                {
                    hold[r][c] = life[r][c];
                }
                if (counter == 3)
                {
                    hold[r][c] = '*';
                }
                if (counter > 3)
                {
                    hold[r][c] = ' ';
                }
            }
        }

        for(int r=0; r<ROWS; r++)       // Transfer data over
        {
            for(int c =0; c<COLS;c++)
            {
                life[r][c] = hold[r][c];
            }
        }

        iteration += 1;

    }while (iteration < generation);




	return 0;

}

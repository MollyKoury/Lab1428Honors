#include <iostream>
#include <fstream>
using namespace std;

void read();
int assembly();

// Declare our variables
	const int OP_ADD = 0;
	const int OP_SUB = 1;
	const int OP_MUL = 2;
	const int OP_DIV = 3;
	const int OP_EXP = 4;
	const int OP_RED = 5;
	const int OP_WRT = 6;
	const int OP_STR = 7;
	const int OP_JMP = 8;
	const int OP_CJP = 9;
	int memory[256];
	int instruction[512][4]={0};
	int counter = 0;

int main()
{
    read();
    assembly();

	return 0;
}


void read()
{
    ifstream fin;
	fin.open("sumRange.txt");
    while(!(fin.eof())&&counter < 512)
	{
		fin >> instruction[counter][0] >> instruction[counter][1] >> instruction[counter][2] >> instruction[counter][3];
		counter ++;
	}
}

int assembly()
{
    for(int i=0; i<counter; i++)
	{

		switch(instruction[i][0])
		{
			case OP_ADD:
				memory[instruction[i][1]] = memory[instruction[i][2]] + memory[instruction[i][3]];
				break;
			case OP_SUB:
				memory[instruction[i][1]] = memory[instruction[i][2]] - memory[instruction[i][3]];
				break;
			case OP_MUL:
				memory[instruction[i][1]] = memory[instruction[i][2]] * memory[instruction[i][3]];
				break;
			case OP_DIV:
				memory[instruction[i][1]] = memory[instruction[i][2]] / memory[instruction[i][3]];
				break;
			case OP_EXP:
				//IMPLEMENT HERE!
				break;
			case OP_RED:
				cout << "Enter a number:";
				cin >> memory[instruction[i][1]];
				break;
			case OP_WRT:
				cout << memory[instruction[i][1]] << endl;
				break;
			case OP_STR:
				memory[instruction[i][1]]=instruction[i][2];
				break;
			case OP_JMP:
                if (i + instruction[counter][1] < 0 || i + instruction[counter][1] > counter)       //Error handling
                {
                    cout << "Unable to make jump due to being out of range" << endl;
                }
                else
                {
                    i += instruction[counter][1];
                }
				break;
			case OP_CJP:
				if(instruction[i][2] == instruction[i][3])
                {
                    if (i + instruction[counter][1] < 0 || i + instruction[counter][1] > counter)       //Error handling
                    {
                        cout << "Unable to make jump due to being out of range" << endl;
                    }
                    else
                    {
                        i += instruction[counter][1];
                    }
                }
                else
                {
                    cout << "Unable to make jump due to numbers not being equal to each other" << endl;
                }
				break;
		}
	}
}


#include <iostream>

using namespace std;                //  NO CLUE IF ANY OF THIS WORKS

struct song
{
    string songTitle;
    string fileName;
    string genre;
    int trackNum;
    bool fav;
};

song TsuPod[100];
int numSongs = 0;

void menu();
void newSong(int numSongs);
void deleteSong(int numSongs);
void displaySongs(int numSongs);
void editSong(int numSongs);
void displayFavorites(int numSongs);

int main()
{
    int choice;

    do
    {
        menu();
        cin >> choice;

        switch (choice)
        {
            case 1 : newSong(numSongs);
                     break;
            case 2 : deleteSong(numSongs);
                     break;
            case 3 : displaySongs(numSongs);
                     break;
            case 4 : editSong(numSongs);
                     break;
            case 5 : displayFavorites(numSongs);
                     break;
            case 0 : cout << endl << "Exiting TsuPod..." << endl;
                     break;
            default : cout << "Invalid menu option..." << endl;
        }

    }while(choice != 0);

    return 0;
}

void menu()
{
    cout << ":: TsuPod ::" << endl << endl;
    cout << "1 :: Enter a new song" << endl;
    cout << "2 :: Delete an existing song" << endl;
    cout << "3 :: Display all existing songs" << endl;
    cout << "4 :: Edit a song" << endl;
    cout << "5 :: Print out favorites" << endl;
    cout << "0 :: Exit TsuPod" << endl;
}


void newSong(int numSongs)
{
    cout << "Enter parameters for new song" << endl;
    cout << "[Song Name - File Name - Genre - Track # - Favorite(0-No;1-Yes)]" <<endl;
    cout << "[Enter between each parameter]" << endl;

    numSongs++;

    if (numSongs > 100)
    {
        cout << "Memory is full" << endl;
        numSongs = 100;
    }
    else
    {
        cin >> TsuPod[numSongs].songTitle;
        cin >> TsuPod[numSongs].fileName;
        cin >> TsuPod[numSongs].genre;
        cin >> TsuPod[numSongs].trackNum;
        cin >> TsuPod[numSongs].fav;
    }
}

void deleteSong(int numSongs)
{
    int track;

    cout << "Enter song number to be deleted" << endl;
    cin >> track;

    if (track > numSongs || track < 0)
    {
        cout << "Song does not exist" << endl;
    }
    else
    {
        TsuPod[track].songTitle = "";
        TsuPod[track].fileName = "";
        TsuPod[track].genre = "";
        TsuPod[track].trackNum = 0000;
        TsuPod[track].fav = 0;
    }
}

void displaySongs(int numSongs)
{
    if (numSongs = 0)
    {
        cout << "TsuPod is empty" << endl;
    }
    else
    {
        for(int i = 0; i < numSongs; i++)
        {
            cout << TsuPod[i].songTitle << "    ";
            cout << TsuPod[i].fileName << "    ";
            cout << TsuPod[i].genre << "    ";
            cout << TsuPod[i].trackNum << "    ";
            cout << TsuPod[i].fav << endl;
        }
    }
}

void editSong(int numSongs)
{
    int track;

    cout << "Enter song number to edit" << endl;
    cin >> track;

    if (track > numSongs || track < 0)
    {
        cout << "Song does not exist" << endl;
    }
    else if (TsuPod[track].trackNum = 0000)
    {
        cout << "Song does not exist" << endl;
    }
    else
    {
        cout << "Enter parameters for new parameters" << endl;
        cout << "[Song Name - File Name - Genre - Track # - Favorite(0-No;1-Yes)]" <<endl;
        cout << "[Enter between each parameter]" << endl;

        cin >> TsuPod[track].songTitle;
        cin >> TsuPod[track].fileName;
        cin >> TsuPod[track].genre;
        cin >> TsuPod[track].trackNum;
        cin >> TsuPod[track].fav;
    }
}

void displayFavorites(int numSongs)
{
    for(int i = 0; i < numSongs; i++)
        {
            if (TsuPod[i].fav = 1)
            {
                cout << TsuPod[i].songTitle << "    ";
                cout << TsuPod[i].fileName << "    ";
                cout << TsuPod[i].genre << "    ";
                cout << TsuPod[i].trackNum << "    ";
                cout << TsuPod[i].fav << endl;
            }
        }
}

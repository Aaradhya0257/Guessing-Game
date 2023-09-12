#include <bits/stdc++.h>
#include <experimental/random>
#include <cstdlib>
#include <ctime>
using namespace std;

int randomNumber(int level)
{
    srand(time(0));
    int random = 1;
    switch (level)
    {
    case 1:
        random += rand() % 10;
        break;
    case 2:
        random += rand() % 50;
        break;
    case 3:
        random += rand() % 100;
        break;
    case 4:
        random += rand() % 1000;
        break;
    }
    return random;
}
void working(int hiddenNumber, int choice, string name)
{
    int i;
    switch (choice)
    {
    case 1:
        i = 3;
        break;
    case 2:
        i = 4;
        break;
    case 3:
        i = 7;
        break;
    case 4:
        i = 10;
        break;
    }
    int guess;
    cout << "You have " << i << " attempts.\n";
    cout << "Enter Your Guess:";
    for (int j = i; j > 0; j--)
    {
        cin >> guess;
        if (guess == hiddenNumber)
        {
            cout << "\nCongratulations, " << name << ", you Win !!" << endl;
            cout << "Score: " << j << endl;
            cout << "Do you want to play more:)??" << endl;
            return;
        }
        else
        {
            cout << "\nWrong guess!! ";
            if (i + 1 != j)
            {
                if (hiddenNumber > guess)
                {
                    cout << "(Hint: Go higher)" << endl;
                }
                else
                {
                    cout << "(Hint: Go lower)" << endl;
                }
                cout << "Attempts left: " << j - 1 << endl
                     << " Guess again: ";
            }
        }
    }
    cout << "You lost the Game, " << name << "!!" << endl;
    cout << "The answer was " << hiddenNumber << endl;
}
int main()
{
    cout << "--------------------------------------" << endl;
    cout << "Welcome to the Guessing Game!!\n"
         << endl;
    string name;
    cout << "Enter Your Name: ";
    cin >> name;
    cout << "\nGuess the number and win points!" << endl;
    cout << "Choose a level and start guessing...!"
         << endl;
    cout << "\nLevels-" << endl;
    cout << "1. Beginner (0 to 10)" << endl;
    cout << "2. Easy (0 to 50)" << endl;
    cout << "3. Medium (0 to 100)" << endl;
    cout << "4. Pro (0 to 1000)" << endl;
    cout << "\nChoose your level: ";
    int choice;
    cin >> choice;
    cout << endl;
    while (choice < 1 || choice > 4)
    {
        cout << "Wrong input! Enter again : ";
        cin >> choice;
    }
    int hiddenNumber = randomNumber(choice);
    working(hiddenNumber, choice, name);
    return 0;
}
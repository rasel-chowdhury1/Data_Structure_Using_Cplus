#include <bits/stdc++.h>
using namespace std;
int main()
{
    cout << "---Start your Guessing Game---\n";
    while (1)
    {
        int user, random;
        cout << "Guess the number between 1 to 5: ";
        cin >> user;
        random = 1 + rand() % 5;
        if (user == random)
        {
            cout << "CONGRATULATIONS!! YOU WON!!\n\n";
            cout << "Press any key if you want to continue to guessing or Press 0 for exit.\n";
            int x;
            cin >> x;
            if (x == 0)
            {
                cout << "You exit the Game.\n";
                break;
            }
            else
                cout << "---Start your Guessing Game---\n";
        }
        else
            cout << "Try again, Random number was " << random << "\n\n";
    }
}
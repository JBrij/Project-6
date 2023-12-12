/*
    Description: This program allows a user to enter a string consisting solely of letters and determines if it is a palindrome.
    Author: Justin Brijmohan
    Date: December 14, 2023
*/
#include <iostream>
#include <string>
#include <cctype>
#include <stdexcept>


using namespace std;

bool palindrome(const string& s)
{
    if (s.length() <= 1)
    {
        return true;
    }
    if (tolower(s[0]) != tolower(s[s.length() - 1]))
    {
        return false;
    }

    return palindrome(s.substr(1, s.length() - 2));
}

int main()
{
    char repeat;
    do {
        try
        {
            string word;
            cout << endl << "Enter a word: ";
            cin >> word;

            for (char letter : word)
            {
                if (!isalpha(letter))
                {
                    throw invalid_argument("Input should contain only letters.");
                }
            }


            if (palindrome(word)) {
                cout << endl <<"The entered word is a palindrome!" << endl << endl;
            }
            else
            {
                cout << endl << "The entered word is not a palindrome." << endl << endl;
            }

            cout << "Do you want to check another word? (y/n): ";
            cin >> repeat;

        } catch (const exception& e) {
            cerr << "Error: " << e.what() << endl;
        }
    } while (repeat == 'y' || repeat == 'Y');

    return 0;
}

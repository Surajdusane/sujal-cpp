
#include <iostream>
#include <string>
using namespace std;

int main()
{
    string s, rev = "";
    int choice, count = 0, start, end;
    char ch, newch;

    cout << "----- String Operations -----\n";
    cout << "1. Frequency of character\n";
    cout << "2. Extract substring\n";
    cout << "3. Remove character\n";
    cout << "4. Check palindrome\n";
    cout << "5. Replace character\n";

    cout << "Enter your choice: ";
    cin >> choice;

    cout << "Enter the string: ";
    cin >> s;

    switch(choice)
    {
        case 1:
            cout << "Enter character: ";
            cin >> ch;

            for(int i = 0; i < (int)s.length(); i++)
            {
                if(s[i] == ch)
                    count++;
            }

            cout << "Frequency = " << count;
            break;

        case 2:
            cout << "Enter start and end index: ";
            cin >> start >> end;

            if(start < 0 || end > (int)s.length() || start > end)
            {
                cout << "Invalid indices";
                break;
            }

            cout << "Substring: ";

            for(int i = start; i < end; i++)
                cout << s[i];

            break;

        case 3:
        {
            string result = "";

            cout << "Enter character to remove: ";
            cin >> ch;

            for(int i = 0; i < (int)s.length(); i++)
            {
                if(s[i] != ch)
                    result += s[i];
            }

            cout << "Remaining string: " << result;
            break;
        }

        case 4:
            for(int i = s.length()-1; i >= 0; i--)
                rev += s[i];

            if(s == rev)
                cout << "Palindrome";
            else
                cout << "Not Palindrome";

            break;

        case 5:
            cout << "Enter character to replace: ";
            cin >> ch;

            cout << "Enter new character: ";
            cin >> newch;

            for(int i = 0; i < (int)s.length(); i++)
            {
                if(s[i] == ch)
                    s[i] = newch;
            }

            cout << "Modified string: " << s;
            break;

        default:
            cout << "Invalid choice";
    }

    return 0;
}

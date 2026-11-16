
#include <iostream>
#include <string>
using namespace std;

class Student {
    string code[10], project[10], master[10], paper[10];
    int s1, s2, s3, s4;

    // Function to search a name in an array
    bool search(string a[], int n, string name) {
        for (int i = 0; i < n; i++) {
            if (a[i] == name)
                return true;
        }
        return false;
    }

public:

    // Input function
    void getdata() {
        cout << "Enter coding students count: ";
        cin >> s1;
        for (int i = 0; i < s1; i++)
            cin >> code[i];

        cout << "Enter project students count: ";
        cin >> s2;
        for (int i = 0; i < s2; i++)
            cin >> project[i];

        cout << "Enter mastermind students count: ";
        cin >> s3;
        for (int i = 0; i < s3; i++)
            cin >> master[i];

        cout << "Enter paper students count: ";
        cin >> s4;
        for (int i = 0; i < s4; i++)
            cin >> paper[i];
    }

    // 1. Coding AND Project
    void second() {
        cout << "Both Coding and Project: ";

        for (int i = 0; i < s1; i++) {
            if (search(project, s2, code[i]))
                cout << code[i] << " ";
        }
    }

    // 2. Coding OR Project
    void third() {
        cout << "Coding OR Project: ";

        for (int i = 0; i < s1; i++)
            cout << code[i] << " ";

        for (int i = 0; i < s2; i++) {
            if (!search(code, s1, project[i]))
                cout << project[i] << " ";
        }
    }

    // 3. Coding BUT NOT Mastermind
    void fourth() {
        cout << "Coding but NOT Mastermind: ";

        for (int i = 0; i < s1; i++) {
            if (!search(master, s3, code[i]))
                cout << code[i] << " ";
        }
    }

    // 4. Students in all four events
    void getall() {
        cout << "Students in all events: ";

        for (int i = 0; i < s1; i++) {
            if (search(project, s2, code[i]) &&
                search(master, s3, code[i]) &&
                search(paper, s4, code[i])) {
                cout << code[i] << " ";
            }
        }
    }
};

int main() {
    Student s;
    int choice;

    s.getdata();

    do {
        cout << "\n\n1. Both Coding and Project";
        cout << "\n2. Coding OR Project";
        cout << "\n3. Coding but NOT Mastermind";
        cout << "\n4. Students in all events";
        cout << "\n5. Exit";

        cout << "\nEnter choice: ";
        cin >> choice;

        switch (choice) {
            case 1: s.second(); break;
            case 2: s.third(); break;
            case 3: s.fourth(); break;
            case 4: s.getall(); break;
            case 5: cout << "Exiting..."; break;
            default: cout << "Invalid choice";
        }

    } while (choice != 5);

    return 0;
}

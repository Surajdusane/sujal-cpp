/*
Name:Aditya Patil
Roll No: 42

A Dictionary using Hash table: A Dictionary stores key and value pairs Data: Set of (key, value) pairs, Keys are mapped to values, Keys must be comparable, Keys must be unique.
Standard Operations: Insert(key, value), Find(key), Delete(key)
Write a menu driven C++ program to provide above standard operations on dictionaries
Write a menu driven C++ program to provide all the functions of a dictionary (ADT) using hashing and handle collisions using chaining.
*/
#include <iostream>
#include <list>
#include <string>
using namespace std;

class HashTable {
    int SIZE;
    list<pair<int, string>>* table;

    int hashFunction(int key) {
        return key % SIZE;
    }

public:
    HashTable(int size) {
        SIZE = size;
        table = new list<pair<int, string>>[SIZE];
    }

    void insert(int key, string value) {
        int index = hashFunction(key);
        for (auto &p : table[index]) {
            if (p.first == key) {
                p.second = value;
                cout << "Updated (" << key << ", " << value << ")\n";
                return;
            }
        }
        table[index].push_back({key, value});
        cout << "Inserted (" << key << ", " << value << ")\n";
    }

    void find(int key) {
        int index = hashFunction(key);
        for (auto &p : table[index]) {
            if (p.first == key) {
                cout << "Found (" << key << ", " << p.second << ")\n";
                return;
            }
        }
        cout << "Key not found!\n";
    }

    void remove(int key) {
        int index = hashFunction(key);
        for (auto it = table[index].begin(); it != table[index].end(); ++it) {
            if (it->first == key) {
                table[index].erase(it);
                cout << "Deleted key: " << key << endl;
                return;
            }
        }
        cout << "Key not found!\n";
    }

    void display() {
        cout << "\n--- Hash Table ---\n";
        for (int i = 0; i < SIZE; i++) {
            cout << "Bucket " << i << ": ";
            for (auto &p : table[i])
                cout << "(" << p.first << ", " << p.second << ") ";
            cout << endl;
        }
    }
};

int main() {
    int size;
    cout << "Enter size of hash table: ";
    cin >> size;

    HashTable dict(size);
    int choice, key;
    string value;

    do {
        cout << "\n1. Insert\n2. Find\n3. Delete\n4. Display\n5. Exit\nEnter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter key and value: ";
                cin >> key >> value;
                dict.insert(key, value);
                break;
            case 2:
                cout << "Enter key to find: ";
                cin >> key;
                dict.find(key);
                break;
            case 3:
                cout << "Enter key to delete: ";
                cin >> key;
                dict.remove(key);
                break;
            case 4:
                dict.display();
                break;
        }
    } while (choice != 5);

    return 0;
}

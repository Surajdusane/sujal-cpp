/*
Sorting: Write a C++ menu driven program to store the percentage of marks obtained by the students in an array. Write function for sorting array of floating point numbers in ascending order using
1. Selection Sort
2. Bubble sort
3. Insertion sort
4. Shell Sort
5. Quick sort
6. Radix sort
7. Display top five scores
Implement any 4 methods of sorting. Provide choice to user to take input from user or using random numbers.
Use Standard Template Library (STL) sort function
*/
#include <iostream>
#include <algorithm> 
#include <cstdlib>   
#include <ctime>     
using namespace std;

class Sorting {
public:
 
    void selectionSort(float arr[], int n) {
        for (int i = 0; i < n - 1; ++i) {
            int minIndex = i;
            for (int j = i + 1; j < n; ++j)
                if (arr[j] < arr[minIndex])
                    minIndex = j;
            swap(arr[i], arr[minIndex]);
        }
    }

    
    void bubbleSort(float arr[], int n) {
        for (int i = 0; i < n - 1; ++i)
            for (int j = 0; j < n - i - 1; ++j)
                if (arr[j] > arr[j + 1])
                    swap(arr[j], arr[j + 1]);
    }

 
    void insertionSort(float arr[], int n) {
        for (int i = 1; i < n; ++i) {
            float key = arr[i];
            int j = i - 1;
            while (j >= 0 && arr[j] > key) {
                arr[j + 1] = arr[j];
                j--;
            }
            arr[j + 1] = key;
        }
    }

  
    void shellSort(float arr[], int n) {
        for (int gap = n / 2; gap > 0; gap /= 2) {
            for (int i = gap; i < n; ++i) {
                float temp = arr[i];
                int j = i;
                while (j >= gap && arr[j - gap] > temp) {
                    arr[j] = arr[j - gap];
                    j -= gap;
                }
                arr[j] = temp;
            }
        }
    }

  
    int partition(float arr[], int low, int high) {
        float pivot = arr[high];
        int i = low - 1;
        for (int j = low; j < high; ++j)
            if (arr[j] < pivot)
                swap(arr[++i], arr[j]);
        swap(arr[i + 1], arr[high]);
        return i + 1;
    }

    void quickSort(float arr[], int low, int high) {
        if (low < high) {
            int pi = partition(arr, low, high);
            quickSort(arr, low, pi - 1);
            quickSort(arr, pi + 1, high);
        }
    }

   
    void displayTopFive(float arr[], int n) {
        cout << "\nTop 5 Scores: ";
        for (int i = n - 1; i >= max(0, n - 5); --i)
            cout << arr[i] << " ";
        cout << endl;
    }
};

int main() {
    Sorting s;
    int n, choice;
    srand((unsigned)time(0));

    cout << "Enter number of students: ";
    cin >> n;

    if (n < 1 || n > 100) {
        cout << "Invalid number of students! Enter a value between 1 and 100.\n";
        return 0;
    }

    float arr[100];

    cout << "1. Manual Input\n2. Random Data\nEnter choice: ";
    cin >> choice;

    if (choice == 1) {
        cout << "Enter percentages:\n";
        for (int i = 0; i < n; ++i)
            cin >> arr[i];
    } else {
        for (int i = 0; i < n; ++i)
            arr[i] = rand() % 101;  // 0-100 random %
    }

    cout << "\nChoose Sorting Algorithm:\n";
    cout << "1. Selection Sort\n2. Bubble Sort\n3. Insertion Sort\n4. Shell Sort\n";
    cout << "5. Quick Sort\n6. STL Sort\nEnter your choice: ";
    cin >> choice;

    switch (choice) {
        case 1: s.selectionSort(arr, n); break;
        case 2: s.bubbleSort(arr, n); break;
        case 3: s.insertionSort(arr, n); break;
        case 4: s.shellSort(arr, n); break;
        case 5: s.quickSort(arr, 0, n - 1); break;
        case 6: sort(arr, arr + n); break;
        default: cout << "Invalid choice!\n"; return 0;
    }

    cout << "\nSorted Marks: ";
    for (int i = 0; i < n; ++i)
        cout << arr[i] << " ";

    s.displayTopFive(arr, n);
    return 0;
}

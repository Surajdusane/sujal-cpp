#include <iostream>
using namespace std;

int main()
{
    int a[20][3], t[20][3];
    int r, c, n, k = 1;

    cout << "Enter rows and columns: ";
    cin >> r >> c;

    cout << "Enter number of non-zero elements: ";
    cin >> n;

    if (n < 0 || n > 19)
    {
        cout << "Invalid number of non-zero elements (0-19)";
        return 0;
    }

    // Header row of original triplet matrix
    a[0][0] = r;
    a[0][1] = c;
    a[0][2] = n;

    cout << "Enter row, column and value:\n";

    for (int i = 1; i <= n; i++)
    {
        cin >> a[i][0] >> a[i][1] >> a[i][2];
    }

    // Display original triplet matrix
    cout << "\nOriginal Triplet Matrix:\n";

    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }

    // Header row of transpose
    t[0][0] = c;
    t[0][1] = r;
    t[0][2] = n;

    // Simple transpose
    for (int col = 0; col < c; col++)
    {
        for (int i = 1; i <= n; i++)
        {
            if (a[i][1] == col)
            {
                t[k][0] = a[i][1];
                t[k][1] = a[i][0];
                t[k][2] = a[i][2];
                k++;
            }
        }
    }

    // Display transpose
    cout << "\nTranspose Triplet Matrix:\n";

    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cout << t[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
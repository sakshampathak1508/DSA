#include <iostream>
#include <stdio.h>
using namespace std;

// dynamic allocation of 2-D arrays

int main()
{
    int m, n;
    cout << "Enter Row: ";
    cin >> m;
    cout << "Enter Coloumn: ";
    cin >> n;
    int **arr = new int *[m];
    cout << "Enter the array elements: \n";
    for (int i = 0; i < m; i++)
    {
        arr[i] = new int[n];
        for (int j = 0; j < n; j++)
        {
            cin >> arr[i][j];
        }
    }
    cout << "The array elements are: \n";
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << "\n";
    }

    return 0;
}

#include <iostream>
#include <stdio.h>
using namespace std;

void display(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << "\n";
}

int findMax(int arr[],int n){
    int max = INT_MIN;
    for(int i=0;i<n;i++){
        if(max < arr[i]){
            max = arr[i];
        }
    }
    return max;
}

void count_sort(int arr[],int n){
    int max = findMax(arr,n);
    int n_arr[max+1] = {0};
    for(int i=0;i<n;i++){
        n_arr[arr[i]] += 1;
    }
    int i=0,j=0;
    while(i<=max){
        if(n_arr[i]!=0){
            arr[j] = i;
            n_arr[i] -= 1;
            j++;
        }
        else{
            i++;
        }
    }
}

int main()
{
    int arr[] = {2, 4, 3, 9, 1, 4, 8, 7, 5, 6};
    int n = sizeof(arr) / sizeof(arr[0]);
    display(arr, n);
    count_sort(arr,n);
    display(arr, n);
    return 0;
}

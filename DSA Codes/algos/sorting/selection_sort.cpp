#include <iostream>
#include <stdio.h>
using namespace std;

void display(int *arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << "\n";
}

void selection_sort(int arr[],int n){
    for(int i=0;i<n-1;i++){
        int minIndex = i;
        for(int j=i+1;j<n;j++){
            if(arr[j] < arr[minIndex]){
                minIndex = j;
            }            
        }
        int temp = arr[i];
        arr[i] = arr[minIndex];
        arr[minIndex] = temp;
    }
}

int main(){
    int arr[7] = {2, 45, 3, 15, 1, 7, 8};
    display(arr, 7);
    selection_sort(arr,7);
    display(arr, 7);
    return 0;
}

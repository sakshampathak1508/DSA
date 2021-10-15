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

void swap(int& a,int &b){
    int temp = a;
    a = b;
    b = temp;
}

int partition(int arr[],int low,int high){
    int pivot = arr[low];
    int i=low+1;
    int j=high;
    do
    {
        while(arr[i] <= pivot ){
            i++;
        }
        while(arr[j] > pivot ){
            j--;
        }
        if(i<j){
            swap(arr[i],arr[j]);
        }
    }while (i<j);
    swap(arr[low],arr[j]);
    return j;
}

void quick_sort(int arr[],int low,int high){
    int p_index;
    if(low<high){
        p_index = partition(arr,low,high);
        quick_sort(arr,low,p_index-1);
        quick_sort(arr,p_index+1,high);
    }
}


int main()
{
    int arr[] = {2,4,3,9,1,4,8,7,5,6};
    int n = sizeof(arr)/sizeof(arr[0]);
    display(arr, n);
    quick_sort(arr,0,n-1);
    display(arr, n);
    return 0;
}

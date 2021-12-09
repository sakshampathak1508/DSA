#include <iostream>
#include <stdio.h>
using namespace std;

void display(int arr[],int n){
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<"\n";
}

void merge(int arr[], int low, int mid, int high){
    int *sorted_arr = new int[high+1];
    int i,j,k;
    i=low;
    j=mid+1;
    k=low;
    while(i<=mid and j<=high){
        if(arr[i] < arr[j]){
            sorted_arr[k] = arr[i];
            i++;
            k++;
        }
        else{
            sorted_arr[k] = arr[j];
            j++;
            k++;
        }
    }
    while(i<=mid){
        sorted_arr[k] = arr[i];
        i++;
        k++;
    }
    while(j<=high){
        sorted_arr[k] = arr[j];
        j++;
        k++;
    }
    for(int i=low;i<=high;i++){
        arr[i] = sorted_arr[i];
    }
}

void merge_sort(int arr[],int low,int high){
    if(low<high){
        int mid = low+ (high-low)/2;
        merge_sort(arr,low,mid);
        merge_sort(arr,mid+1,high);
        merge(arr,low,mid,high);
    }
}

int main()
{
    int arr[] = {2, 4, 3, 9, 1, 4, 8, 7, 5, 6};
    int n = sizeof(arr) / sizeof(arr[0]);
    display(arr, n);
    merge_sort(arr,0,n-1);
    display(arr, n);
    return 0;
}

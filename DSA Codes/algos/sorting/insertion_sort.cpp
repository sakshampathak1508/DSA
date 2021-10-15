#include <iostream>
#include <stdio.h>
using namespace std;

void display(int arr[],int n){
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<"\n";
}

void insertion_sort(int arr[],int n){
    for(int i=1;i<=n-1;i++){
        int key,j;
        j = i-1;
        key = arr[i];
        while(j>=0 and key < arr[j]){
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = key;
    }
}

int main(){
    int n = 5;
    int arr[n] = {7,2,91,77,3};    
    display(arr,n);
    insertion_sort(arr,n);
    display(arr,n);
    return 0;
}

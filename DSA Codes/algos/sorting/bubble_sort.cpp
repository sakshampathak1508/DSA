#include <iostream>
#include <stdio.h>
using namespace std;

void display(int * arr,int n){
    cout<<"Array : "<<endl;
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

void bubble_sort(int * arr,int n){
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-i-1;j++){
            if(arr[j] > arr[j+1]){
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

void bubble_sort_adaptive(int * arr,int n){
    for(int i=0;i<n-1;i++){
        bool is_sorted = true;
        for(int j=0;j<n-i-1;j++){
            if(arr[j]>arr[j+1]){
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
                is_sorted = false;
            }
        }
        if(is_sorted){
            return;
        }
    }
}

int main(){
    int n;
    cout<<"Enter the size of the array : ";
    cin>>n;
    int *arr = new int[n];
    cout<<"Enter the array Elements: \n";
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    display(arr,n);
    // bubble_sort(arr,n);
    bubble_sort_adaptive(arr,n);
    display(arr,n);
    return 0;
}

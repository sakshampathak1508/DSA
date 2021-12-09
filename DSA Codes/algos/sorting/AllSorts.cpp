#include <iostream>
#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;

void display(int arr[],int n){
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<"\n";
}

void swap(int &a,int &b){
    int temp = a;
    a = b;
    b = temp;
}

void bubble_sort(int arr[],int n){
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-i-1;j++){
            if(arr[j]>arr[j+1]){
                swap(arr[j],arr[j+1]);
            }
        }
    }
}

void insertion_sort(int arr[],int n){
    for(int i=1;i<n;i++){
        int j = i-1;
        int temp = arr[i];
        while(j>=0 and temp<arr[j]){
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = temp;
    }
}

void selection_sort(int arr[],int n){
    for(int i=0;i<n-1;i++){
        int min_index = i;
        for(int j=i+1;j<n;j++){
            if(arr[j]<arr[min_index]){
                min_index = j;
            }
        }
        swap(arr[i],arr[min_index]);
    }
}

void merge(int arr[],int n,int start,int mid,int end){
    int i = start;
    int k = start;
    int j = mid+1;
    int *new_arr = new int[end+1];
    while(i<=mid and j<=end){
        if(arr[i]<arr[j]){
            new_arr[k] = arr[i];
            i++;
            k++;
        }
        else{
            new_arr[k] = arr[j];
            j++;
            k++;
        }
    }
    while(i<=mid){
        new_arr[k] = arr[i];
        i++;
        k++;
    }
    while(j<=end){
        new_arr[k] = arr[j];
        j++;
        k++;
    }
    for(int i=start;i<=end;i++){
        arr[i] = new_arr[i];
    }
}

void merge_sort(int arr[],int n,int start,int end){
    if(start<end){
        int mid = start+(end-start)/2;
        merge_sort(arr,n,start,mid);
        merge_sort(arr,n,mid+1,end);
        merge(arr,n,start,mid,end);
    }
}

void quick_sort(int arr[],int n,int start,int end){
    if(start>=end){
        return;
    }
    int low = start;
    int high = end;
    int mid = low+(high-low)/2;
    int pivot = arr[mid];
    while(low<=high){
        while(arr[low]<pivot){
            low++;
        }
        while(arr[high]>pivot){
            high--;
        }
        if(low<=high){
            swap(arr[low],arr[high]);
            low++;
            high--;
        }
    }
    quick_sort(arr,n,start,high);
    quick_sort(arr,n,low,end); 
}


void cyclic_sort(int arr[],int n){
    int i=0;
    while(i<n){
        int temp = arr[i]-1;
        if(arr[i]!=arr[temp]){
            swap(arr[i],arr[temp]);
        }
        else{
            i++;
        }
    }
}

int main(){
    int arr[] = {7, 2, 9, 1, 11, 4, 2};
    int n = sizeof(arr)/sizeof(arr[0]);
    
    int nums[5] = {3,5,2,1,4};

    // display(nums, 5);
    // cyclic_sort(nums,5);
    // display(nums, 5);
    display(arr, n);
    merge_sort(arr,n,0,n-1);
    display(arr, n);
    return 0;
}

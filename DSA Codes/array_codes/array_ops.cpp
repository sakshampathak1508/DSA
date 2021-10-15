#include <iostream>
#include <stdio.h>
#include <vector>
using namespace std;

void init(int *arr,int n){
    cout << "Enter the array Elements: \n";
    for (int i = 0; i < n; i++)
    {
        cout << "Enter element " << i << " : ";
        cin >> arr[i];
    }
}
void display(int *arr,int n){
    cout << "Array Elements: ";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i]<<" ";
    }
    cout << endl;
}

void insert(int *arr,int val,int index,int &n)
{
    for(int i=n;i>=index;i--){
        arr[i+1] = arr[i];
    }
    arr[index] = val;
    n++;
}

void del(int *arr, int index, int &n)
{
    for (int i = index; i < n; i++)
    {
        arr[i] = arr[i+1];
    }
    n--;
}

int lsearch(int *arr, int val, int n)
{
    for(int i=0;i<n;i++){
        if(arr[i]==val){
            return i;
        }
    }
    return -1;
}

int bsearch(int *arr, int val, int n)
{
    int l=0;
    int h=n-1;
    int m;
    while(l<h){
        m = (l+h)/2;
        if(arr[m]==val){
            return m;
        }
        else if(arr[m]>val){
            h = m-1;
        }
        else{
            l = m+1;
        }
    }
    return -1;   
}

int main()
{
    int *arr;
    int n;
    cout<<"Enter the size of the array to initialize it with: ";
    cin>>n;
    arr = new int[n];
    init(arr,n);
    display(arr,n);
    insert(arr,34,4,n);
    display(arr,n);
    cout<<"Binary Search: "<<lsearch(arr,34,n)<<"\n";
    del(arr,4,n);
    display(arr,n);
    cout<<"Linear Search: "<<lsearch(arr,34,n)<<"\n";
    cout<<"Binary Search: "<<bsearch(arr,1,n)<<"\n";
    return 0;
}

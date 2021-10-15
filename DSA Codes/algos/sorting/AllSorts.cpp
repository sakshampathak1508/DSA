#include <iostream>
#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;

void display(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void swap(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}

void bubble_sort(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}

void insertion_sort(int arr[], int n)
{
    for (int i = 1; i <= n - 1; i++)
    {
        int key = arr[i];
        int j = i - 1;
        while (key < arr[j] and j >= 0)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

void selection_sort(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int minIndex = i;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[minIndex])
            {
                minIndex = j;
            }
        }
        swap(arr[minIndex], arr[i]);
    }
}

int partition(int arr[], int low, int high)
{
    int pivot = arr[low];
    int i = low + 1;
    int j = high;
    do
    {
        while (arr[i] <= pivot)
        {
            i++;
        }
        while (arr[j] > pivot)
        {
            j--;
        }
        if (i < j)
        {
            swap(arr[i], arr[j]);
        }
    } while (i < j);
    swap(arr[low], arr[j]);
    return j;
}

void quick_sort(int arr[], int low, int high)
{
    if (low < high)
    {
        int index = partition(arr, low, high);
        quick_sort(arr, low, index - 1);
        quick_sort(arr, index + 1, high);
    }
}

void merge(int arr[], int n, int low, int mid, int high)
{
    int i = low, j = mid + 1, k = low;
    int *sorted_arr = new int[n];
    while (i <= mid and j <= high)
    {
        if (arr[i] < arr[j])
        {
            sorted_arr[k] = arr[i];
            i++;
            k++;
        }
        else
        {
            sorted_arr[k] = arr[j];
            j++;
            k++;
        }
    }
    while (i <= mid)
    {
        sorted_arr[k] = arr[i];
        i++;
        k++;
    }
    while (j <= high)
    {
        sorted_arr[k] = arr[j];
        j++;
        k++;
    }
    for (int i = low; i <= high; i++)
    {
        arr[i] = sorted_arr[i];
    }
}

void merge_sort(int arr[], int n, int low, int high)
{
    if (low < high)
    {
        int mid = (low + high) / 2;
        merge_sort(arr, n, low, mid);
        merge_sort(arr, n, mid + 1, high);
        merge(arr, n, low, mid, high);
    }
}

void count_sort(int arr[], int n)
{
    int max = *max_element(arr, arr + n);
    int new_arr[max + 1] = {0};
    for (int i = 0; i < n; i++)
    {
        new_arr[arr[i]] += 1;
    }
    int i = 0, j = 0;
    while (i <= max)
    {
        if (new_arr[i] != 0)
        {
            arr[j] = i;
            new_arr[i] -= 1;
            j++;
        }
        else
        {
            i++;
        }
    }
}

int main()
{
    int n = 7;
    int arr[n] = {7, 2, 9, 1, 11, 4, 2};
    display(arr, n);
    // selection_sort(arr,n);
    // merge_sort(arr,n, 0, n - 1);
    // quick_sort(arr,0,n-1);
    // merge_sort(arr,n,0,n-1);
    count_sort(arr, n);
    display(arr, n);
    return 0;
}

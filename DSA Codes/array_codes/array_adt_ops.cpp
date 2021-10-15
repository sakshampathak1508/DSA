#include <iostream>
#include <stdio.h>
#include <vector>
using namespace std;

class MyArray{
    int t_size;
    int u_size;
    int* arr;
    public:
        MyArray(){
            cout<<"Enter the Total size for the array: ";
            cin>>t_size;
            cout<<"Enter the size you want to initialize the array with: ";
            cin>>u_size;
            if(t_size<u_size){
                cout<<"The Total Size can't be Smaller than the Used Size\n";
                exit(1);
            }
            arr = new int[u_size];
            cout<<"Enter the array Elements: \n";
            for(int i=0;i<u_size;i++){
                cout<<"Enter the element "<<i<<" : ";
                cin>>arr[i];
            }
        }
        void insert(MyArray*, int,int);
        void del(MyArray *,int);
        void display(MyArray *);
};

void MyArray::display(MyArray* ptr){
    for(int i=0;i<ptr->u_size;i++){
        cout<<ptr->arr[i]<<" ";
    }
    cout<<"\n";
}

void MyArray::insert(MyArray *ptr, int index, int value)
{
    ptr->u_size++;
    for(int i=ptr->u_size;i>=index;i--){
        ptr->arr[i+1] = ptr->arr[i]; 
    }
    ptr->arr[index] = value;
}

void MyArray::del(MyArray *ptr, int index)
{
    for(int i=index;i<ptr->u_size;i++){
        ptr->arr[i] = ptr->arr[i+1];
    }
    ptr->u_size--;
}

int main(){
    MyArray *ptr = new MyArray();
    ptr->display(ptr);
    ptr->insert(ptr,3,45);
    ptr->display(ptr);
    ptr->del(ptr,3);
    ptr->display(ptr);

    return 0;
}

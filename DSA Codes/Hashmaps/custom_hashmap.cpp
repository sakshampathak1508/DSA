#include <iostream>
#include <stdio.h>
#include <string>
using namespace std;

template <typename T>
class node{
    public:
        string key;
        T value;
        node<T>* next;

        node(string key,T value){
            this->key = key;
            this->value = value;
            this->next = NULL;
        }
};

template <typename T>
class my_map{
    public:
        int count;
        int bucket_size;
        node<T>** bucket;

        my_map(){
            count = 0;
            bucket_size = 20;
            bucket = new node<T>*[bucket_size];
            for(int i=0;i<bucket_size;i++){
                bucket[i] = NULL;
            }
        }

        int size(){
            return count;
        }

        int hash(string key){
            int h = 0;
            int coff =1;
            for(int i=key.length()-1;i>=0;i--){
                h+=(key[i]*coff)%bucket_size;
                coff*=37;
            }
            // cout<<h%bucket_size;
            return h%bucket_size;
        }

        void insert(string key,T value){
            int bucket_index = hash(key);
            node<T>* head = bucket[bucket_index];
            while(head!=NULL){
                if(head->key==key){
                    head->value = value;
                    return;
                }
                head=head->next;
            }
            head = bucket[bucket_index];
            node<T> *new_node = new node<T>(key,value);
            new_node->next = head;
            bucket[bucket_index] = new_node;
            count++;
        }

        T getValue(string key){
            int bucket_index = hash(key);
            node<T>* head = bucket[bucket_index];
            while(head!=NULL){
                if(head->key==key){
                    return head->value;
                }
                head=head->next;
            }
            return 0;
        }

        T remove(string key){
            int bucket_index = hash(key);
            node<T>* head = bucket[bucket_index];
            node<T>* prev = NULL;
            while(head!=NULL){
                if(head->key == key){
                    if(prev==NULL){
                        bucket[bucket_index] = head->next;
                    }
                    else{
                        prev->next = head->next;
                    }
                    T v = head->value;
                    head->next = NULL;
                    delete head;
                    count--;
                    return v;
                }
                prev = head;
                head = head->next;
            }
            return 0;
        }


};

int main(){
    
    my_map<int> Mymap = my_map<int>(); 
    Mymap.insert("abc",5);
    Mymap.insert("def",10);
    Mymap.insert("ghi",15);
    cout<<Mymap.getValue("abc")<<"\n";
    Mymap.remove("abc");
    cout<<Mymap.getValue("def")<<"\n";
    cout<<Mymap.size()<<"\n";
    return 0;
}

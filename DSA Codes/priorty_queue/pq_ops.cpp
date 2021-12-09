#include <iostream>
#include <stdio.h>
#include <vector>
using namespace std;

class priorty_queue{
    vector<int> pq;
    public:
        priorty_queue(){

        }

        bool isempty(){
            if(pq.size()==0){
                return true;
            }
            return false;
        }

        int get_size(){
            return pq.size();
        }

        int get_min(){
            if(!isempty()){
                return pq[0];
            }
            return 0;
        }
        void insert(int val){
            pq.push_back(val);
            int child_index = pq.size()-1;
            while(child_index > 0){
                int parent_index = (child_index-1)/2;
                if(pq[parent_index] > pq[child_index]){
                    int temp = pq[child_index];
                    pq[child_index] = pq[parent_index];
                    pq[parent_index] = temp;
                }
                else{
                    return;
                }
                child_index = parent_index;
            }
        }

        int removemin(){
            if(isempty()){
                return 0;
            }
            int ans = pq[0];
            pq[0] = pq[pq.size()-1];
            pq.pop_back();
            
            int parent_index = 0;
            int left_index = 2*parent_index+1;
            int right_index = 2*parent_index+2;

            while(left_index< pq.size()){
                int min_index = parent_index;
                if(pq[min_index] > pq[left_index]){
                    min_index = left_index;
                }
                if(right_index<pq.size() and  pq[min_index] > pq[right_index]){
                    min_index = right_index;
                }
                if(min_index==parent_index){
                    break;
                }
                int temp = pq[min_index];
                pq[min_index] = pq[parent_index];
                pq[parent_index] = temp;

                parent_index = min_index;
                left_index = 2 * parent_index + 1;
                right_index = 2 * parent_index + 2;
            }
            return ans;
        }
};


int main(){
    priorty_queue pq;
    pq.insert(100);
    pq.insert(10);
    pq.insert(15);
    pq.insert(4);
    pq.insert(17);
    pq.insert(21);
    pq.insert(67);

    while(!pq.isempty()){
        cout<<pq.removemin()<<" ";
    }
    return 0;
}

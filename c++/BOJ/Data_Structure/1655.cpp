
#include <iostream>
#include <cstring>
#include <vector>
#include <queue>
using namespace std;

#define MAX 100001

int arr[MAX];

int main(void){   
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n;
    cin>>n;

    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    priority_queue<int> max_pq;
    priority_queue<int> min_pq;

    for(int i=0; i<n; i++){
        if(max_pq.size()>min_pq.size()){
            min_pq.push(-arr[i]);
        }
        else{
            max_pq.push(arr[i]);
        }

        if(!max_pq.empty()&&!min_pq.empty()){
            if(max_pq.top()>-min_pq.top()){
                int max_val=max_pq.top();
                int min_val=-min_pq.top();

                max_pq.pop();
                min_pq.pop();

                max_pq.push(min_val);
                min_pq.push(-max_val);
            }
        }
        cout<<max_pq.top()<<"\n";
    }
    return 0;

}

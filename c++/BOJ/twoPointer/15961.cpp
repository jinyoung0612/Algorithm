#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <deque>
using namespace std;

#define MAX 3000001
int arr[MAX];
int check[MAX];
int main(void){
    
    ios::sync_with_stdio(false);
    cin.tie(0);
    int N,d,k,c;
    cin>>N>>d>>k>>c;
    int answer=0;
    
    for(int i=0; i<N; i++){
        cin>>arr[i];
    }
    
    int cnt=0;
    deque<int> dq;
    for(int i=0; i<k; i++){
        dq.push_back(arr[i]);
        if(!check[arr[i]]++){
            cnt++;
        }  
        answer=max(answer,cnt); 
    }

    for(int i=0; i<N; i++){
        dq.pop_front();
        
        if(!(--check[arr[i]])){
            cnt--;
        }

        dq.push_back(arr[(i+k)%N]);

        if(!(check[arr[(i+k)%N]]++)){
            cnt++;
        }

        if(!check[c]){
            answer=max(answer,cnt+1);
        }
        else{
            answer=max(answer,cnt);
        }

    }


    cout<<answer;
    return 0;
} 
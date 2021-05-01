#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <stack>
using namespace std;

#define MAX 1000001

int arr[MAX];
int main(void){
    
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int N;
    cin>>N;
    stack<int> s;
    vector<int> answer(N,0);
    for(int i=0; i<N; i++){
        cin>>arr[i];
    }

    for(int i=N-1; i>=0; i--){
        while(!s.empty()&&arr[s.top()]<arr[i]){
            answer[s.top()]=i+1;
            s.pop();
        }
        s.push(i);
    }
    for(int i=0; i<N; i++){
       cout<<answer[i]<<" ";
    }

    return 0;
} 
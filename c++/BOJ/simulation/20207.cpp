#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <cmath>
using namespace std;

#define MAX 1001

int arr[MAX];
int main(void){
    
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N;
    cin>>N;
    int start,end;
    for(int i=0; i<N; i++){
        cin>>start>>end;
        arr[start]++;
        arr[end+1]--;
    }
    int max_val=0;
    int answer=0;
    int idx=-1;

    for(int i=1; i<=366; i++){
        arr[i]+=arr[i-1];
        max_val=max(max_val,arr[i]);
        if(!arr[i]){
            answer+=(i-idx)*max_val;
            max_val=0;
            idx=-1;
        }
        else if(idx==-1){
            idx=i;
        }
       
    }
    cout<<answer;
    

    return 0;
} 
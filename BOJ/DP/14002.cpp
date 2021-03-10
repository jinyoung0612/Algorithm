#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

#define MAX 1001
int dp[MAX];
int arr[MAX];
int parent[MAX];
int main(void){

    int n;
    cin>>n;

    for(int i=0; i<n; i++){
        cin>>arr[i];
    }

    dp[0]=1;
    
    for(int i=0; i<n; i++){
        int temp=0;
        for(int j=0; j<i; j++){
            if(arr[i]>arr[j]){
                if(dp[j]>temp){
                    temp=dp[j];
                    parent[i]=j;
                }
            }
            dp[i]=temp+1;
        }
    }

    // for(int i=0; i<n; i++){
    //     dp[i]=1;
    //     for(int j=0; j<i; j++){
    //         if(arr[i]>arr[j]&&dp[j]+1>dp[i]) dp[i]=dp[j]+1;
    //     }
    // }

    int answer=0;
    int pos=0;
    for(int i=0; i<n; i++){
       if(answer<dp[i]){
           answer=dp[i];
           pos=i;
       }
    }    
    vector<int> v;

    cout<<answer<<"\n";

    while(v.size()!=answer){
        v.push_back(arr[pos]);
        pos=parent[pos];
    }
   
    for(int i=v.size()-1; i>=0; i--){
        cout<<v[i]<<" ";
    }
    

    return 0;
}
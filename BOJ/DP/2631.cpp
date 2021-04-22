#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <cmath>
using namespace std;

#define MAX 201
int arr[MAX];
int dp[MAX];

int main(void){
    
    ios::sync_with_stdio(false);
    cin.tie(0);
    int N;
    cin>>N;
    
    for(int i=1; i<=N; i++){
        cin>>arr[i];
    }
    int max_val=0;
    for(int i=1; i<=N; i++){
        dp[i]=1;
        for(int j=0; j<i; j++){
            if(arr[j]<arr[i]&&dp[j]+1>dp[i]){
                dp[i]=dp[j]+1;
            }
        }
        max_val=max(max_val,dp[i]);
    }
    cout<<N-max_val;
    return 0;
} 
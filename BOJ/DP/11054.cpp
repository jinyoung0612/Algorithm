#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

#define MAX 1001
int arr[MAX];
int dp[MAX];
int rdp[MAX];

int main(void){
    
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin>>n;

    for(int i=0; i<n; i++){
        cin>>arr[i];
    }

    for(int i=0; i<n; i++){
        dp[i]=1;
        for(int j=0; j<i; j++){
            if(arr[j]<arr[i]){
                dp[i]=max(dp[i],dp[j]+1);
            }
        }
    }

    for(int i=n-1; i>=0; i--){
        rdp[i]=1;
        for(int j=n-1; j>i; j--){
            if(arr[j]<arr[i]){
                rdp[i]=max(rdp[i],rdp[j]+1);
            }
        }
    }
  
    int answer=0;
    
    for(int i=0; i<n; i++){
       answer=max(answer,dp[i]+rdp[i]-1);
    }
    cout<<answer;
    return 0;
} 
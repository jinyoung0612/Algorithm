#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

#define MAX 301

int arr[MAX];
// int dp[MAX];
int dp[MAX][2]; // 0: 밟은경우 1: 밟지 않은 경우

int main(void){
    int n;
   
    cin>>n;
    // for(int i=3; i<n+3; i++){
    //     cin>>arr[i];
    // }
    // for(int i=3; i<n+3; i++){
    //     dp[i]=max(dp[i-3]+arr[i-1]+arr[i],dp[i-2]+arr[i]);
        
    // }
 
    //    cout<<dp[n+2];

    for(int i=1; i<=n; i++){
        cin>>arr[i];
    }

    dp[1][0]=dp[1][1]=arr[1];
    
    for(int i=2; i<=n; i++){
        dp[i][0]=dp[i-1][1]+arr[i];
        dp[i][1]=max(dp[i-2][0],dp[i-2][1])+arr[i];
    }
    cout<<max(dp[n][0],dp[n][1]);
   
   

    return 0;
}
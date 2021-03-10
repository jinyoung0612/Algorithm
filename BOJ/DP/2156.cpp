#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

#define MAX 10003
int arr[MAX];
int dp[MAX];
int main(void){
    int n;
   
    cin>>n;
    for(int i=3; i<n+3; i++){
        cin>>arr[i];
    }
    for(int i=3; i<n+3; i++){
        dp[i]=max(dp[i-3]+arr[i-1]+arr[i],dp[i-2]+arr[i]);
        dp[i]=max(dp[i-1],dp[i]);
    }
   
   cout<<dp[n+2];
   

    return 0;
}
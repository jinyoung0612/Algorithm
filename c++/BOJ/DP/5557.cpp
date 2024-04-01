#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <cmath>
using namespace std;

#define MAX 101

int arr[MAX];
long long dp[MAX][21]; 

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int N;
    cin>>N;
    
    for(int i=1; i<=N; i++){
        cin>>arr[i];
    }

    dp[1][arr[1]]+=1;

    for(int i=2; i<N; i++){
        for(int j=0; j<=20; j++){
            if(dp[i-1][j]){
                if(j+arr[i]<=20) dp[i][j+arr[i]]+=dp[i-1][j];
                if(j-arr[i]>=0) dp[i][j-arr[i]]+=dp[i-1][j];
            }
        }
    }
    cout<<dp[N-1][arr[N]];
    return 0;
} 
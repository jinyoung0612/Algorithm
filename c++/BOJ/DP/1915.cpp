#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <cmath>
using namespace std;

#define MAX 1001
char arr[MAX][MAX];
int dp[MAX][MAX];
int main(void){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n,m;
    cin>>n>>m;
    
    for(int i=1; i<=n; i++){
       for(int j=1; j<=m; j++){
           cin>>arr[i][j];
           if(arr[i][j]=='1'){
               dp[i][j]=1;
           }
       }
    }

    int answer=0;
     
    for(int i=1; i<=n; i++){
       for(int j=1; j<=m; j++){
           if(arr[i][j]=='1'){
               if(dp[i-1][j]!=0 &&dp[i-1][j-1]!=0 &&dp[i][j-1]!=0){
                   if(dp[i-1][j]!=1&&dp[i-1][j-1]&&dp[i][j-1]!=1){
                       int size=min(min(dp[i-1][j],dp[i-1][j-1]),dp[i][j-1]);
                       dp[i][j]=pow(sqrt(size)+1,2);
                   }
                   else{
                       dp[i][j]=4;
                   }
               }
           }
           answer=max(answer,dp[i][j]);
       }
    }
    cout<<answer;


    return 0;
}
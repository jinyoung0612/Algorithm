#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

#define MAX 501
int triangle[MAX][MAX];
int dp[MAX][MAX];

int main(void){
    
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin>>n;
    int num;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=i; j++){
            cin>>num;
            triangle[i][j]=num;
        }
    }

    dp[1][1]=triangle[1][1];
    
     for(int i=2; i<=n; i++){
        for(int j=1; j<=i; j++){
            if(j==1){
                dp[i][j]=dp[i-1][j]+triangle[i][j];
            }
            else if(j==i){
                dp[i][j]=dp[i-1][j-1]+triangle[i][j];
            }
            else{
                dp[i][j]=max(dp[i-1][j-1],dp[i-1][j])+triangle[i][j];
            }
        }
    }

    int answer=0;
    for(int i=1; i<=n; i++){
        answer=max(answer,dp[n][i]);
    }
    
    cout<<answer;
    
   
    return 0;
} 
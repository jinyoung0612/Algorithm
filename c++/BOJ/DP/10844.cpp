#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

#define MAX 101

int main(void){
    int n;
    int dp[MAX][10];
    cin>>n;
    
    dp[1][0]=0;
    for(int i=1; i<10; i++){
        dp[1][i]=1;
    }

    for(int i=2; i<=n; i++){
        for(int j=0; j<10; j++){
            if(j==0){
                dp[i][j]=(dp[i-1][j+1])%1000000000;
            }
            else if(j==9){
                dp[i][j]=(dp[i-1][j-1])%1000000000;
            }
            else {
                dp[i][j]=(dp[i-1][j-1]+dp[i-1][j+1])%1000000000;
            }
        }
    }

    int result=0;
    
    for(int i=0; i<10; i++){
        result=(result+dp[n][i])%1000000000;
    }
    cout<<result;




}
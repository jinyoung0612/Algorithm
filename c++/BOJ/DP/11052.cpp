#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

#define MAX 1001

int main(void){
    int n;
    int p[MAX];
    int dp[MAX];

    cin>>n;
    
    for(int i=1; i<=n; i++){
        cin>>p[i];
    }

    dp[1]=p[1];

    for(int i=2; i<=n; i++){
        dp[i]=p[i];
        for(int j=1; j<=i; j++){
            dp[i]=min(dp[i],dp[i-j]+p[j]);
        }
    }
    cout<<dp[n];

   
    return 0;
}
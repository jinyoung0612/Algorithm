#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

#define MAX 101

long long dp[MAX];
int main(void){
    
    ios::sync_with_stdio(false);
    cin.tie(0);
    
   int T;
   int n;
    dp[1]=1;
    dp[2]=1;
    dp[3]=1;
    for(int i=4; i<=100; i++){
        dp[i]=dp[i-2]+dp[i-3];
    }
    cin>>T;
   while(T--){
       cin>>n;
       cout<<dp[n]<<"\n";
   }
   
    return 0;
} 
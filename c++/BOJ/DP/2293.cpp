#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define MAX 10001

long long coin[101];
long long dp[MAX];

int main(void){
  
   int n,k;
   cin>>n>>k;
   for(int i=0; i<n; i++){
       cin>>coin[i];
   }
   sort(coin,coin+n);
   dp[0]=1;
   for(int i=0; i<n; i++){
       for(int j=coin[i]; j<=k; j++){
            dp[j]+=dp[j-coin[i]];
           
       }
   } 

   cout<<dp[k];

    return 0;
}
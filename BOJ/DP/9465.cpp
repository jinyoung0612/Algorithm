#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

#define MAX 100001

int dp[2][MAX];
int arr[2][MAX];

int main(void){
   int t,n;
   cin>>t;
   for(int i=0; i<t; i++){
       cin>>n;
       for(int j=0; j<2; j++){
           for(int k=1; k<=n; k++){
               cin>>arr[j][k];
           }
       }

  
       dp[0][1]=arr[0][1];
       dp[1][1]=arr[1][1];

      
        for(int k=2; k<=n; k++){
            dp[0][k]=arr[0][k]+max(dp[1][k-1],dp[1][k-2]);
            dp[1][k]=arr[1][k]+max(dp[0][k-1],dp[0][k-2]);   
        }
       
       cout<<max(dp[0][n],dp[1][n])<<"\n";

       
   }
    return 0;
}
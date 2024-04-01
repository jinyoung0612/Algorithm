
#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

#define MAX 501
int arr[MAX];
int result[MAX];
int dp[MAX][MAX];

int main(void){   
  int T;
  cin>>T;
  int K;
  
  while(T--){
        cin>>K;

        for(int i=1; i<=K; i++){
            cin>>arr[i];
            result[i]=result[i-1]+arr[i];
        }

        for(int i=1; i<K; i++){
            for(int j=1; i+j<=K; j++){
                int k=i+j;
                dp[j][k]=987654321;
                for(int mid=j; mid<k; mid++){
                    dp[j][k]=min(dp[j][k],dp[j][mid]+dp[mid+1][k]+result[k]-result[j-1]);
                }
            }
        }
        cout<<dp[1][K]<<"\n";
  }

  return 0;  
}

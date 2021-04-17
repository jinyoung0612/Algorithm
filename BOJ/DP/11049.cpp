
#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

#define MAX 501
#define INF pow(2,31)-1

int N;
int arr[MAX][2];
int dp[MAX][MAX];

int minCal(int left, int right){
    if(left==right) return 0;

    int &result=dp[left][right];
    
    if(result!=-1){
        return result;
    }

    result=INF;
    for(int i=left; i<right; i++){
        result=min(result,minCal(left,i)+minCal(i+1,right)+
        arr[left][0]*arr[i][1]*arr[right][1]);
    }
    return result;
}

int main(void){   
  
    cin>>N;

    // 1. Top-Down 160ms
    // for(int i=0; i<N; i++){
    //     cin>>arr[i][0]>>arr[i][1];
    // }

    // memset(dp,-1,sizeof(dp));

    // cout<<minCal(0,N-1);

    // 2. Bottom-Up 40ms

    for(int i=1; i<=N; i++){
        cin>>arr[i][0]>>arr[i][1];
    }
    for(int i=1; i<N; i++){
            for(int j=1; i+j<=N; j++){
                int k=i+j;
                dp[j][k]=INF;
                for(int mid=j; mid<=k; mid++){
                    dp[j][k]=min(dp[j][k],dp[j][mid]+dp[mid+1][k]+arr[j][0]*arr[mid][1]*arr[k][1]);
                }
            }
        }
    cout<<dp[1][N];
    
  return 0;  
}

#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

int arr[101][2]; // 무게, 가치
int dp[101][100001]; // i개의 물건, 최대 무게가 j일 때의 최고가치
int main(void){
    
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N;
    int K;
    cin>>N>>K;
    int W;
    int V;
    for(int i=1; i<=N; i++){
        cin>>W>>V;
        arr[i][0]=W;
        arr[i][1]=V;
    }

    for(int i=1; i<=N; i++){
        for(int j=1; j<=K; j++){
            if(j>=arr[i][0]) dp[i][j]=max(dp[i-1][j],dp[i-1][j-arr[i][0]]+arr[i][1]);
            else dp[i][j]=dp[i-1][j];
        }
    }
    cout<<dp[N][K];
    
    return 0;
} 
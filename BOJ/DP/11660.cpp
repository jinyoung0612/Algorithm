#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;
#define MAX 1025

int arr[MAX][MAX];
int dp[MAX][MAX];
int main(void){
    
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int N,M;
    cin>>N>>M;

    for(int i=1; i<=N; i++){
        for(int j=1; j<=N; j++){
            cin>>arr[i][j];
        }
    }

    for(int i=1; i<=N; i++){
        for(int j=1; j<=N; j++){
           dp[i][j]=dp[i-1][j]+dp[i][j-1]-dp[i-1][j-1]+arr[i][j];
        }
    }

    int x1,y1,x2,y2;
    for(int i=0; i<M; i++){
        cin>>x1>>y1>>x2>>y2;
        cout<<dp[x2][y2]-dp[x1-1][y2]-dp[x2][y1-1]+dp[x1-1][y1-1]<<"\n";
    }
    return 0;
} 
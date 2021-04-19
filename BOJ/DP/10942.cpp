#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define MAX 2001
int arr[MAX];
int dp[MAX][MAX];
int N,M;

// 1. Top-Down
int palindrome(int start, int end){
    if(start>=end){
        return 1;
    }
    // result는 dp[start][end] 주소를 참조함: result값이 바뀌면 dp[start][end] 값도 바뀜
    int &result=dp[start][end];
    if(result!=-1) return result;

    if(arr[start]!=arr[end]) return result=0;
    
    return result=palindrome(start+1,end-1);
}
int main(void){
    
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    cin>>N;

    for(int i=1;i<=N; i++){
        cin>>arr[i];
    }

    // 1. Top-Down
    for(int i=1; i<=N; i++){
        for(int j=1; j<=N; j++){
            dp[i][j]=-1;
        }
    }
    
    cin>>M;
    int a,b;
    for(int i=0; i<M; i++){
        cin>>a>>b;
        cout<<palindrome(a,b)<<"\n";
    }

    // 2. Bottom-Up
    // for(int i=1; i<=N; i++){
    //     dp[i][i]=1;
    // }
    // for(int i=1; i<N; i++){
    //     if(arr[i]==arr[i+1]){
    //         dp[i][i+1]=1;
    //     }
    // }
    // for(int i=2; i<N; i++){
    //     for(int j=1; j<=N; j++){
    //         if(arr[j]==arr[j+i]&&dp[j+1][j+i-1]){
    //             dp[j][j+i]=1;
    //         }
    //     }
    // }

    // cin>>M;
    // int a,b;
    // for(int i=0; i<M; i++){
    //     cin>>a>>b;
    //     cout<<dp[a][b]<<"\n";
    // }

    
    return 0;
}
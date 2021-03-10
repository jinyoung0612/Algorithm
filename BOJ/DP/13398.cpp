#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define MAX 100001

int arr[MAX];
int dp[MAX][2]; // 0: 제거 안함 1: 한번 제거 

void dfs(){

}
int main(void){
    int n;
    cin>>n;

    for(int i=1; i<=n; i++){
        cin>>arr[i];
    }

    dp[1][0]=dp[1][1]=arr[1];

    for(int i=2; i<=n; i++){
        
        dp[i][0]=max(dp[i-1][0]+arr[i],arr[i]);
        dp[i][1]=max(dp[i-1][0],dp[i-1][1]+arr[i]); 
        /*
            i 번째를 삭제하는 경우는 i-1에서 삭제하지 않은 경우의 연속합을 가져온다.
            i 이전에 삭제가 이루어진 경우, dp[i]-1+arr[i] 현재 값을 더해서 연속합을 가져온다.
        */
    
    }


    int answer=-1001;
    for(int i=1; i<=n; i++){
        answer=max(answer,max(dp[i][0],dp[i][1]));
    }
    
    cout<<answer;
    return 0;
}
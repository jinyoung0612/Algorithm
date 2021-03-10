#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define MAX 100001

int arr[MAX];
int dp[MAX];
int main(void){
    int n;
    cin>>n;

    for(int i=1; i<=n; i++){
        cin>>arr[i];
    }
    dp[1]=arr[1];
    for(int i=2; i<=n; i++){
        dp[i]=max(dp[i-1]+arr[i],arr[i]);
    }

    int answer=-1001;
    for(int i=1; i<=n; i++){
        answer=max(answer,dp[i]);
    }
    cout<<answer;
    return 0;
}
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

#define MAX 501

int arr[MAX];
int dp[MAX];
int main(void){
    
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin>>n;
    int a,b;
    for(int i=0; i<n; i++){
        cin>>a>>b;
        arr[a]=b;
    }

    for(int i=1; i<=500; i++){
        dp[i]=1;
        if(arr[i]!=0){
            for(int j=1; j<i; j++){
                if(arr[j]<arr[i]&&arr[j]!=0){
                    dp[i]=max(dp[i],dp[j]+1);
                }
            }
        }
        
    }
    int answer=0;
    for(int i=1; i<=500; i++){
        answer=max(dp[i],answer);
    }

    cout<<n-answer;
    
    return 0;
} 
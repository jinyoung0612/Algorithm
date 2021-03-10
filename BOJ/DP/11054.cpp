#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

#define MAX 1001
int dp[MAX];
int rdp[MAX];
int arr[MAX];
int main(void){

    int n;
    cin>>n;

    for(int i=0; i<n; i++){
        cin>>arr[i];
    }

    dp[0]=1;
    rdp[n-1]=1;
    
    for(int i=0; i<n; i++){
        int temp=0;
        for(int j=0; j<i; j++){
            if(arr[i]>arr[j]){
                temp=max(dp[j],temp);
            }
            dp[i]=temp+1;
        }
    }

    for(int i=n-1; i!=0; i--){
        int temp=0;
        for(int j=n-1; j>i; j--){
            if(arr[i]>arr[j]){
                temp=max(rdp[j],temp);
            }
            rdp[i]=temp+1;
        }
    }
  
    int answer=0;

    for(int i=0; i<n; i++){
        answer=max(answer,dp[i]+rdp[i]-1);
    }
  
    cout<<answer;
    

    return 0;
}
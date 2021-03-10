#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

#define MAX 1001
int dp[MAX];
int arr[MAX];
int main(void){

    int n;
    cin>>n;

    for(int i=0; i<n; i++){
        cin>>arr[i];
    }

    dp[0]=1;
    
    for(int i=0; i<n; i++){
        int temp=0;
        for(int j=0; j<i; j++){
            if(arr[i]<arr[j]){
                temp=max(dp[j],temp);
            }
            dp[i]=temp+1;
        }
    }
  
    int answer=0;
    for(int i=0; i<n; i++){
        answer=max(answer,dp[i]);
    }
    
    cout<<answer;
    

    return 0;
}
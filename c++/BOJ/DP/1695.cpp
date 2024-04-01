#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <cmath>
using namespace std;

#define MAX 5001
int arr[MAX];
int dp[MAX][MAX];
int palindrome(int start, int end){
    if(start>end){
        return 0;
    }
    int &result=dp[start][end];
    if(result!=-1) return result;
    if(arr[start]==arr[end]){
        result=palindrome(start+1,end-1);
    }
    else{
        result=min(palindrome(start+1,end),palindrome(start,end-1))+1;
    }
    return result;
}
int main(void){
    
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int N;
    cin>>N;
    
    for(int i=1; i<=N; i++){
        cin>>arr[i];
    }
   memset(dp,-1,sizeof(dp));
   cout<<palindrome(1,N);
    return 0;
} 
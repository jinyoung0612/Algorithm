#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <cmath>
using namespace std;

#define MAX 101
int arr[9]={0,0,1,7,4,2,0,8,10};
long long dp[MAX];
void calcMin(){
    for(int i=1; i<9; i++){
        dp[i]=arr[i];
    }
    dp[6]=6;

    for(int i=9; i<MAX; i++){
        dp[i]=dp[i-2]*10+arr[2];
        for(int j=3; j<8; j++){
            dp[i]=min(dp[i],dp[i-j]*10+arr[j]);
        }

    }
}


int main(void){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    calcMin();
    int T;
    cin>>T;
    int num;
    
    while(T--){
        cin>>num;
        cout<<dp[num]<<" ";
        
        while(num){
            if(num%2!=0){
                cout<<7;
                num-=3;
            }
            else{
                cout<<1;
                num-=2;
            }
        }

        cout<<"\n";

    }
  
    return 0;
} 
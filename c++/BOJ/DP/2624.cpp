#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <cmath>
using namespace std;

#define MAX 10001

int T,K;
int dp[MAX][101];
vector<pair<int, int> > coin;

int NumOfCoins(int cash, int idx){
    if(cash==0) return 1;
    if(idx>=K) return 0;

    int &result=dp[cash][idx];

    if(result!=-1) return result;
    
    result=0;
    for(int i=0; i<=coin[idx].second; i++){
        if(cash-(coin[idx].first*i)>=0){
            result+=NumOfCoins(cash-(coin[idx].first*i),idx+1);
        }
    }
    return result;
}

int main(void){
    
    ios::sync_with_stdio(false);
    cin.tie(0);


    cin>>T>>K;
    
    int p,n;
    for(int i=0; i<K; i++){
        cin>>p>>n;
        coin.push_back(make_pair(p,n));
    }
    memset(dp,-1,sizeof(dp));
    cout<<NumOfCoins(T,0);
    return 0;
} 
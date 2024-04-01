#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

#define MAX 1001
string s1,s2;
int dp[MAX][MAX];
// 시간초과
int LCS(int i, int j){
    if(s1[i]=='\0'||s2[j]=='\0') return 0;
    else if(s1[i]==s2[j]) return 1+LCS(i+1,j+1);
    else return max(LCS(i+1,j),LCS(i,j+1));
}

int main(void){
    
    cin>>s1>>s2;
    // cout<<LCS(0,0);
    
    for(int i=1; i<=s1.size(); i++){
        for(int j=1; j<=s2.size(); j++){
            if(s1[i-1]==s2[j-1]) dp[i][j]=dp[i-1][j-1]+1;
            else{
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }
    }
    cout<<dp[s1.size()][s2.size()];


    return 0;
}
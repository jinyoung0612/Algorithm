#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

#define MAX 10

int N;
char S[MAX][MAX];
int Select[10];

bool check(int depth){
   int sum=0;
   for(int i=depth; i>=0; i--){
       sum+=Select[i];
       if(S[i][depth]=='+'&&sum<=0) return false;
       if(S[i][depth]=='-'&&sum>=0) return false;
       if(S[i][depth]=='0'&&sum!=0) return false;
   }
   return true;
}

void dfs(int depth){

    if(depth==N){
        for(int i=0; i<N; i++){
            cout<<Select[i]<<" ";
        }
        exit(0);
    }
    
    for(int i=-10; i<=10; i++){
        Select[depth]=i;
        if(check(depth)){
            dfs(depth+1);
        }
    }
}
int main(void){
    
    cin>>N;
    for(int i=0; i<N; i++){
        for(int j=i; j<N; j++){
            cin>>S[i][j];
        }
    }
    dfs(0);
    return 0;
}

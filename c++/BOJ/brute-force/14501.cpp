#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

#define MAX 21
int n;
int day[MAX];
int times[MAX];
int pay[MAX];
int check[MAX];
int answer=-1;

void dfs(int depth, int sum){

    if(depth==n+1){
        answer=max(answer,sum);
        return;
    }

    if(!check[depth]){
        for(int i=depth; i<=depth+times[depth]-1; i++){
           check[i]=1;
        }
        if(times[depth]+depth-1<=n){
             dfs(depth+1,sum+pay[depth]);
        }
        for(int i=depth; i<=depth+times[depth]-1; i++){
           check[i]=0;
        }    
    }
    dfs(depth+1,sum);

}

int main(void){

    cin>>n;

    for(int i=1; i<=n; i++){
        cin>>times[i]>>pay[i];
    }
    // for(int i=1; i<=n; i++){
    //     dfs(i,0);
    // }
    // cout<<answer;

    for(int i=n; i>=1; i--){
        if(i+times[i]>n+1) pay[i]=pay[i+1];
        else{
            pay[i]=max(pay[i+1],pay[i]+pay[i+times[i]]);
        }
    }
    cout<<pay[1];  
    return 0;
}
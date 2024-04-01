#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

#define MAX 21
int seq[MAX];
int sub_seq[MAX];
int n,s;
int result;

void dfs(int start, int depth ,int end){
    if(depth==end){
        int sum=0;
        for(int i=0; i<end; i++){
            sum+=sub_seq[i];
        }
        if(sum==s) result+=1;
        return;
    }
    
    for(int i=start; i<n; i++){
        sub_seq[depth]=seq[i];
        dfs(i+1,depth+1,end);
    }
}

int sum;

void dfs2(int depth, int sum){
    if(depth==n) return;
    if(sum==s+seq[depth]) result++;

    dfs2(depth+1, sum);
    dfs2(depth+1,sum+seq[depth]);
}

int main(void){
    cin>>n>>s;

    for(int i=0; i<n; i++){
        cin>>seq[i];
    }
    // for(int i=1; i<=n; i++){
    //     dfs(0,0,i);
    //     memset(sub_seq,0,sizeof(n));
    // }
    dfs2(0,0);
    cout<<result;

    return 0;
}
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 2. DFS 사용
int n, cost[11][11], visit[11], Min=98765432, cnt=0;

void dfs(int first, int a, int sum){
    if(cnt==n&&first==a){
        if(Min>sum){
            Min=sum;
        }
        return;
    }

    for(int i=0; i<n; i++){
        if(visit[i]==0&&cost[a][i]!=0){
            visit[i]=1;
            sum+=cost[a][i];
            cnt+=1;
            dfs(first,i,sum);
            visit[i]=0;
            sum-=cost[a][i];
            cnt-=1;
        }
    }
}
int main(void){
    cin>>n;
    for(int i=0;i<n; i++){
        for(int j=0; j<n; j++){
            cin>>cost[i][j];
        }
        visit[i]=0;
    }
    for (int i = 0; i < n; i++) {
        dfs(i,i,0);
    }
    cout<<Min<<endl;
    return 0;
}
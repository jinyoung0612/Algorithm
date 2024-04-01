#include <iostream>
#include <vector>
#include <cmath>
#include <cstring>
using namespace std;

#define MAX 21
int n;
int arr[MAX][MAX];
int result[MAX];
int team[MAX];
int answer=10000;
void dfs(int start, int depth, int end){

    if(depth==end){
        int sum=0;
        memset(team,0,sizeof(team));
        for(int i=0; i<n; i++){
            team[result[i]]=1;
        }
        int team1=0;
        int team2=0;
        for(int i=1; i<=n; i++){
            for(int j=i+1; j<=n; j++){
                if(team[i]==1&&team[j]==1){
                    team1+=arr[i][j];
                    team1+=arr[j][i];
                }
                else if(team[i]==0&&team[j]==0){
                    team2+=arr[i][j];
                    team2+=arr[j][i];
                }
               
            }
        }
        answer=min(answer,abs(team1-team2));
        return;
    }

    for(int i=start; i<=n; i++){
        result[depth]=i;
        dfs(i+1,depth+1,end);
    }
}

int main(void){
  
    cin>>n;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            cin>>arr[i][j];
        }
    }
    for(int i=1; i<=n/2; i++){
        dfs(1,0,i);
    }
    cout<<answer;
    return 0;
}
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
        int link=0;
        int start=0;
        for(int i=1; i<=n; i++){
            for(int j=i+1; j<=n; j++){
                if(team[i]==1&&team[j]==1){
                    link+=arr[i][j];
                    link+=arr[j][i];
                }
                else if(team[i]==0&&team[j]==0){
                    start+=arr[i][j];
                    start+=arr[j][i];
                }
            }
        }
        answer=min(answer,abs(link-start));
        return;
    }

    for(int i=start; i<=n; i++){
        team[i]=1;
        dfs(i+1,depth+1,end);
        team[i]=0;
    }
}

int main(void){
  
    cin>>n;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            cin>>arr[i][j];
        }
    }

    dfs(1,0,n/2);
 
    cout<<answer;
    return 0;
}
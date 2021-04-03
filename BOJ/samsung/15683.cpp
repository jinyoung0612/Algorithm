#include <iostream>
#include <cstring>
#include <string>
#include <vector>
using namespace std;
#define MAX  8

int N,M;
int arr[MAX][MAX];
bool visited[MAX][MAX];
int dx[4]={-1,0,1,0};
int dy[4]={0,1,0,-1};
int rotation[6]={0,4,2,4,4,1};
int answer=987654321;
vector< pair< pair<int,int>, int> > v;

void update(int dir, pair<int,int> p){
    dir%=4;

    if(dir==0){
        for(int i=p.first-1; i>=0; i--){
            if(arr[i][p.second]==6) break;
            arr[i][p.second]=-1;
        }
    }
    else if(dir==1){
        for(int i=p.second+1; i<M; i++){
            if(arr[p.first][i]==6) break;
            arr[p.first][i]=-1;
        }
    }
    else if(dir==2){
        for(int i=p.first+1; i<N; i++){
            if(arr[i][p.second]==6) break;
            arr[i][p.second]=-1;
        }
    }
    else if(dir==3){
        for(int i=p.second-1; i>=0; i--){
            if(arr[p.first][i]==6) break;
            arr[p.first][i]=-1;
        }
    }
}
void dfs(int depth){
   
    if(depth==v.size()){
        int sum=0;
        for(int i=0; i<N; i++){
            for(int j=0; j<M; j++){
                if(arr[i][j]==0){
                    sum++;
                }
            }
        }
        answer=min(answer,sum);
        return;
    }
    
    int temp[MAX][MAX];

    for(int i=0; i<rotation[v[depth].second]; i++){
        
        for(int j=0; j<N; j++){
            for(int k=0; k<M; k++){
                temp[j][k]=arr[j][k];
            }
        }

        switch(v[depth].second){
            case(1): update(i,v[depth].first); break;
            case(2): update(i,v[depth].first); update(i+2,v[depth].first); break;
            case(3): update(i,v[depth].first); update(i+1,v[depth].first); break;
            case(4): update(i,v[depth].first); update(i+1,v[depth].first); update(i+2,v[depth].first); break;
            case(5): update(i,v[depth].first); update(i+1,v[depth].first); update(i+2,v[depth].first);
            update(i+3,v[depth].first); break;
        }
        dfs(depth+1);

        for(int j=0; j<N; j++){
            for(int k=0; k<M; k++){
                arr[j][k]=temp[j][k];
            }
        }
    }

}
int main(void) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin>>N>>M;

    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            cin>>arr[i][j];
            if(1<=arr[i][j]&&arr[i][j]<=5){
                v.push_back(make_pair(make_pair(i,j),arr[i][j]));
            }
        }
    }
  
    dfs(0);
    cout<<answer;   
    
    return 0;
}
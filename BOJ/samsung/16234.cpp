#include <iostream>
#include <cstring>
#include <string>
#include <vector>
#include <cmath>
using namespace std;
#define MAX  50
int N,L,R;
int arr[MAX][MAX];
int visited[MAX][MAX];
int people,num;
int dx[4]={1,-1,0,0};
int dy[4]={0,0,-1,1};

vector< pair<int,int> > v;
void dfs(int x, int y){
    for(int i=0; i<4; i++){
        int nx=x+dx[i];
        int ny=y+dy[i];

        if(0<=nx&&nx<N&&0<=ny&&ny<N){
            int diff=abs(arr[x][y]-arr[nx][ny]);

            if(L<=diff&&diff<=R &&!visited[nx][ny]){
                visited[nx][ny]=1;
                v.push_back(make_pair(nx,ny));
                people+=arr[nx][ny];
                num++;
                dfs(nx,ny);
            }
        }
        
    }
}
int main(void) {

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>N>>L>>R;
    int answer=0;
    
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            cin>>arr[i][j];
        }
    }

    while(1){
        memset(visited,false,sizeof(visited));

        bool flag=false;
        for(int i=0; i<N; i++){
            for(int j=0; j<N; j++){
                if(visited[i][j]) continue;

                visited[i][j]=1;
                people=arr[i][j];
                num=1;

                v.clear();
                v.push_back(make_pair(i,j));
                dfs(i,j);

                if(num>=2){
                    flag=true;
                    for(int i=0; i<v.size(); i++){
                        arr[v[i].first][v[i].second]=people/num;
                    }
                }
            }
        }

        if(flag){
            answer++;
        }
        else{
            break;
        }
    }


    cout<<answer;

  
    return 0;
}
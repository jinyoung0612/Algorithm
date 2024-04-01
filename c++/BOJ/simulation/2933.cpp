#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

#define MAX 101
int R,C;
char cave[MAX][MAX];
vector<int> stick;
bool visited[MAX][MAX];
int dx[4]={1,-1,0,0};
int dy[4]={0,0,1,-1};
queue< pair<int,int> > q;

void throw_stick(int idx,int turn){
    int row=R-idx+1;
    //왼쪽에서 던질 때
    if(turn%2==0){
        for(int i=0; i<C; i++){
            if(cave[row][i]=='x'){
                cave[row][i]='.';
                break;
            }
        }
    }
    else{
        for(int i=C-1; i>=0; i--){
            if(cave[row][i]=='x'){
                cave[row][i]='.';
                break;
            }
        }
    }
}
void dfs(int x, int y){

    visited[x][y]=1;

    for(int i=0; i<4; i++){
        int nx=x+dx[i];
        int ny=y+dy[i];

        if(1<=nx&&nx<=R&&0<=ny&&ny<C){
            if(!visited[nx][ny]&&cave[nx][ny]=='x'){
                dfs(nx,ny);
            }
        }
    }
}

void check_clusters(){
    
    for(int j=0; j<C; j++){
        if(cave[R][j]=='x'&&!visited[R][j]){
            dfs(R,j);
        }
    }
}


void find_floatingClusters(){
    
    vector< pair<int,int> > cluster;

     for(int i=1; i<=R; i++){
        for(int j=0; j<C; j++){
            if(!visited[i][j]&&cave[i][j]=='x'){
                cave[i][j]='.';
                cluster.push_back(make_pair(i,j));
            }
        }
    }

    if(cluster.empty()){
        return;
    }
    else{
        bool down=true;
        while(down){
            for(int i=0; i<cluster.size(); i++){
                int nx=cluster[i].first+1;
                int ny=cluster[i].second;

                if(nx==R+1 || cave[nx][ny]=='x'){
                    down=false;
                    break;
                }
            }
            if(down){
                for(int i=0; i<cluster.size(); i++){
                    cluster[i].first++;
                }
            }
        }

        for(int i=0; i<cluster.size(); i++){
            cave[cluster[i].first][cluster[i].second]='x';
        }
       
    }

}

int main(void){
    
    int N;
 
    cin>>R>>C;

    for(int i=1; i<=R; i++){
       cin>>cave[i];
    }
    cin>>N;
    int s;
    for(int i=0; i<N; i++){
        cin>>s;
        stick.push_back(s);
    }

    for(int i=0; i<N; i++){
       
        throw_stick(stick[i],i);
        memset(visited,false,sizeof(visited));
        check_clusters();
        find_floatingClusters();

    }

    for(int i=1; i<=R; i++){
        for(int j=0; j<C; j++){
            cout<<cave[i][j];
        }
        cout<<"\n";
    }
    
    return 0;
}

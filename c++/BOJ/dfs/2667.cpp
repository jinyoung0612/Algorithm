#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define MAX 26

int N;
bool visited[MAX][MAX];
char map[MAX][MAX];
int dx[4]={1,-1,0,0};
int dy[4]={0,0,1,-1};
int sum_a;

void DFS(int x, int y){

    visited[x][y]=1;
    sum_a++;

    for(int i=0; i<4; i++){
        int next_x=x+dx[i];
        int next_y=y+dy[i];

        if(next_x>=0&&next_x<N&&next_y>=0&&next_y<N){
            if(map[next_x][next_y]=='1'&&!visited[next_x][next_y]){
                DFS(next_x,next_y);
            }
        }
    }
}

int main(void){
    cin>>N;
    vector<int> sum_list;
    for(int i=0; i<N; i++){
        cin>>map[i];
    }

    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            if(!visited[i][j]&&map[i][j]=='1'){
                sum_a=0;
                DFS(i,j);
                sum_list.push_back(sum_a);

            }
        }
    }
    cout<<sum_list.size()<<endl;
    sort(sum_list.begin(),sum_list.end());
    for(int i=0; i<sum_list.size(); i++){
        cout<<sum_list.at(i)<<'\n';
    }
    return 0;
}
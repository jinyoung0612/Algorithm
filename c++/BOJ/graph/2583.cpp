
#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

#define MAX 101
 
int M,N,K;
int arr[MAX][MAX];
bool visited[MAX][MAX];
int dx[4]={1,-1,0,0};
int dy[4]={0,0,1,-1};
int area;
void dfs(int x, int y){
    
    for(int i=0; i<4; i++){
        int nx=x+dx[i];
        int ny=y+dy[i];

        if(nx<0 || nx>=M || ny<0 || ny>=N) continue;
        if(!visited[nx][ny]&&arr[nx][ny]==0){
            visited[nx][ny]=1;
            area+=1;
            dfs(nx,ny);
        }
    }
    
}
int main(void){   
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    
    cin>>M>>N>>K;
    int x1,y1,x2,y2;
    vector<int> answer;
    for(int k=0; k<K; k++){
        cin>>x1>>y1>>x2>>y2;
        for(int i=x1; i<x2; i++){
            for(int j=y1; j<y2; j++){
                arr[j][i]=1;
            }
        }
    }

    for(int i=0; i<M; i++){
        for(int j=0; j<N; j++){
            if(!visited[i][j]&&arr[i][j]==0){
                visited[i][j]=1;
                area=1;
                dfs(i,j);
                answer.push_back(area);

            }
        }
    }
   
   sort(answer.begin(),answer.end());

    cout<<answer.size()<<"\n";
   for(int i=0; i<answer.size(); i++){
       cout<<answer[i]<<" ";
   }
    
    return 0;

}

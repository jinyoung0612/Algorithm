#include <iostream>
#include <cstring>
#include <vector>
#include <cmath>
using namespace std;

#define MAX 51
int N,M;
int arr[MAX][MAX];
int result[14];
vector< pair<int,int> > chicken;
vector< pair<int, int> > home;
int answer=987654321;

int calDistance(int x1, int y1, int x2, int y2){
    return abs(x1-x2)+abs(y1-y2);
}
void dfs(int depth, int start){
    if(depth==M){
        int sum=0;

        for(int i=0; i<home.size(); i++){
            int min_dist=987654321;
            int dist=0;
            
            for(int j=0; j<depth; j++){

                dist=calDistance(home[i].first,home[i].second,chicken[result[j]].first,chicken[result[j]].second);
                min_dist=min(min_dist,dist);
            }

            sum+=min_dist;
        
        }
        answer=min(answer,sum);
        return;
    }

    for(int i=start; i<chicken.size(); i++){
        result[depth]=i;
        dfs(depth+1,i+1);
    }
}
int main(void){
    
    cin>>N>>M;

    for(int i=1; i<=N; i++){
        for(int j=1; j<=N; j++){
            cin>>arr[i][j];
            if(arr[i][j]==2){
                chicken.push_back(make_pair(i,j));
            }
            else if(arr[i][j]==1){
                home.push_back(make_pair(i,j));
            }
        }
    }
    
    dfs(0,0);
    cout<<answer;

    return 0;
}
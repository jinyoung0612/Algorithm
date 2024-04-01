#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

#define MAX 101

int N,M,K;
int arr[MAX][MAX];
int A[MAX][MAX];
vector<int> v[MAX][MAX];
int dx[8]={-1,-1,-1,0,0,1,1,1};
int dy[8]={-1,0,1,-1,1,-1,0,1};

void spring_and_summer(){

    for(int i=1; i<=N; i++){
        for(int j=1; j<=N; j++){
          
           if(v[i][j].size()>0){
                int energy=0;
                vector<int> temp;

               sort(v[i][j].begin(),v[i][j].end());

               for(int k=0; k<v[i][j].size(); k++){

                    if(v[i][j][k]<=arr[i][j]){
                        arr[i][j]-=v[i][j][k];
                        temp.push_back(v[i][j][k]+1);
                    }
                    else{
                        energy+=(v[i][j][k]/2);   
                    }

               }
               v[i][j].clear();
               arr[i][j]+=energy;
               for(int k=0; k<temp.size(); k++){
                   v[i][j].push_back(temp[k]);
               }

           }
        }
    }
}

void add_tree(int x, int y){
    for(int i=0; i<8; i++){
        int nx=x+dx[i];
        int ny=y+dy[i];

        if(1<=nx&&nx<=N&&1<=ny&&ny<=N){
            v[nx][ny].push_back(1);
        }
    }
}
void fall(){
    
    for(int i=1; i<=N; i++){
        for(int j=1; j<=N; j++){
           if(v[i][j].size()>0){
              for(int k=0; k<v[i][j].size(); k++){
                if(v[i][j][k]%5==0){
                    add_tree(i,j);
                }
              }
           }
        }
    }
}
void winter(){
    for(int i=1; i<=N; i++){
        for(int j=1; j<=N; j++){
            arr[i][j]+=A[i][j];
        }
    }
}

int main(void){
    cin>>N>>M>>K;

    for(int i=1; i<=N; i++){
        for(int j=1; j<=N; j++){
            arr[i][j]=5;
        }
    }
    
    for(int i=1; i<=N; i++){
        for(int j=1; j<=N; j++){
            cin>>A[i][j];
        }
    }
    int x,y,age;
    for(int i=0; i<M; i++){
        cin>>x>>y>>age;
        v[x][y].push_back(age);
    }

    for(int i=0; i<K; i++){
        spring_and_summer();
        fall();
        winter();
    }

    int  answer=0;
     for(int i=1; i<=N; i++){
        for(int j=1; j<=N; j++){
            answer+=v[i][j].size();
        }
    }
    cout<<answer;


    return 0;
}
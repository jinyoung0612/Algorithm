#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstring>
using namespace std;

#define MAX 101

int N,L;
int arr[MAX][MAX];
bool visited[MAX];
int answer;

void sero(int y){
    int cur=arr[0][y];

    for(int i=0; i<N; i++){
        
        //높이 다를 때
        if(arr[i][y]!=cur){

            // 차이가 1 이상일때
            if(abs(cur-arr[i][y])>1) return;
             
            //내리막길
            if(arr[i][y]<cur){
                int h=-1;
                for(int j=i; j<i+L; j++){
                    if(j<N && !visited[j]){
                        visited[j]=1;
                        if(h==-1){
                            h=arr[j][y];
                        }
                        else if(h!=-1 && arr[j][y]!=h){
                            return;
                        }
                    }
                    else return;
                }
                i+=L-1;
            }
            else{
                int h=-1;
                for(int j=i-1; j>i-1-L; j--){
                    if(j>=0&&!visited[j]){
                        visited[j]=1;
                        if(h==-1){
                            h=arr[j][y];
                        }
                        else if(h!=-1&&arr[j][y]!=h){
                            return;
                        }
                    }
                    else return;
                }
            }
            cur=arr[i][y];
        }
    }
    answer++;
}

void garo(int x){
     int cur=arr[x][0];

    for(int i=0; i<N; i++){
        //높이 다를 때
        if(arr[x][i]!=cur){
            // 차이가 1 이상일때
            if(abs(cur-arr[x][i])>1) return;

            //내리막길
            if(arr[x][i]<cur){
                int h=-1;
                for(int j=i; j<i+L; j++){
                    if(j<N&&!visited[j]){
                        visited[j]=1;
                        if(h==-1){
                            h=arr[x][j];
                        }
                        else if(h!=-1 && arr[x][j]!=h){
                            return;
                        }
                    }
                    else return;
                }
                i+=L-1;
            }
            else{
                int h=-1;
                for(int j=i-1; j>i-1-L; j--){
                    if(j>=0&&!visited[j]){
                        visited[j]=1;
                        if(h==-1){
                            h=arr[x][j];
                        }
                        else if(h!=-1&&arr[x][j]!=h){
                            return;
                        }
                    }
                    else return;
                }
            }
            cur=arr[x][i];
        }
    }
    answer++;
}
int main(void){
    cin>>N>>L;

    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            cin>>arr[i][j];
        }
    }
    
    for(int i=0; i<N; i++){
        memset(visited,0,sizeof(visited));
        sero(i);
        memset(visited,0,sizeof(visited));
        garo(i);

    }
    cout<<answer;

    return 0;
}
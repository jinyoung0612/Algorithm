#include <string>
#include <vector>
#include <iostream>
#include <cstring>
using namespace std;

bool visited[31][31];

int solution(int m, int n, vector<string> board) {
    int answer = 0;
    
    while(1){
        bool flag=true;
        memset(visited,false,sizeof(visited));
        for(int i=0; i<m-1; i++){
            for(int j=0; j<n-1; j++){
                if(board[i][j]=='.') continue;
                if((board[i][j]==board[i][j+1])&&(board[i][j]==board[i+1][j])&&board[i][j]==board[i+1][j+1]){
                    visited[i][j]=1;
                    visited[i][j+1]=1;
                    visited[i+1][j]=1;
                    visited[i+1][j+1]=1;
                    flag=false;
                }
            }
        }
        if(flag) break;
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(visited[i][j]){
                    answer+=1;
                    for(int k=i; k>0; k--){
                        board[k][j]=board[k-1][j];
                    }
                    board[0][j]='.';
                }
            }
        }
    }
    for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                cout<<board[i][j];
            }
            cout<<"\n";
        }
    return answer;
}

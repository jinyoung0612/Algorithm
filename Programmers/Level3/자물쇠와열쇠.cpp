#include <string>
#include <vector>
#include <iostream>
using namespace std;
int M,N;
vector<vector<int> > board;
bool check(vector<vector<int> >& key, int y, int x){
    
    bool flag=true;
    
    for(int i=y; i<y+M; i++){
        for(int j=x; j<x+M; j++){
            board[i][j]+=key[i-y][j-x];
        }
    }
    
    for(int i=M; i<M+N; i++){
        for(int j=M; j<M+N; j++){
            if(board[i][j]!=1){
                flag=false;
                break;
            }
        }
        if(!flag) break;
    }
    
    for(int i=y; i<y+M; i++){
        for(int j=x; j<x+M; j++){
            board[i][j]-=key[i-y][j-x];
        }
    }
    return flag;
}
void rotate(vector<vector<int> >& key){
    vector<vector<int> > temp(M,vector<int>(M));
    for(int i=0; i<M; i++){
        for(int j=0; j<M; j++){
            temp[i][j]=key[j][M-i-1];
        }
    }
    
    for(int i=0; i<M; i++){
        for(int j=0; j<M; j++){
            key[i][j]=temp[i][j];
        }
    }
}
bool solution(vector<vector<int> > key, vector<vector<int> > lock) {
    bool answer = false;
    M=key.size();
    N=lock.size();
    
    board=vector<vector<int> >(2*M+N,vector<int>(2*M+N));
    for(int i=M; i<M+N; i++){
        for(int j=M; j<M+N; j++){
            board[i][j]=lock[i-M][j-M];
        }
    }
    for(int i=0; i<N+M; i++){
        for(int j=0; j<N+M; j++){
            for(int k=0; k<4; k++){
                rotate(key);
                if(check(key,i,j)){
                    return true;
                }
            }
        }
    }
    return false;
}
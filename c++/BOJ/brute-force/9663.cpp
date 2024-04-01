#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

#define MAX 16
int N;
int board[MAX];
int answer=0;

bool promising(int i){
    int k=1;
    bool flag=true;

    while(k<i&&flag){
        if(board[i]==board[k] || abs(board[i]-board[k])==i-k){
            flag=false;
        }
        k++;
    }
    return flag;
}
void nQueens(int depth){
    
    if(promising(depth)){

        if(depth==N){
            answer++;
        }
        else{
            for(int i=1; i<=N; i++){
                board[depth+1]=i;
                nQueens(depth+1);
            }
        }
    }
    
}

int main(void){
    cin>>N;
    nQueens(0);
    cout<<answer;
    return 0;
}
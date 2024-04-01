#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

#define MAX 51
int N,M;
char board[MAX][MAX];

int main(void){
   
   cin>>N>>M;

    for(int i=0; i<N; i++){
        cin>>board[i];
    } 

    int min_val=64;
    for(int i=0; i<N-7; i++){
        for(int j=0; j<M-7; j++){
            int cntB=0;
            int cntW=0;
            for(int k=i; k<i+8; k++){
                for(int l=j; l<j+8; l++){
                    if((k+l)%2==0){
                        if(board[k][l]=='B') cntW++;
                        else cntB++;
                    }
                    else{
                        if(board[k][l]=='B') cntB++;
                        else cntW++;
                    }
                }
            }
            min_val=min(min(min_val,cntB),cntW);
          

        }
    }

    cout<<min_val;

    
    return 0;
}
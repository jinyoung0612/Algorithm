#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;
#define MAX 101

int arr[MAX][MAX];
int main(void){
    
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N,M;
    cin>>N>>M;
    int a,b;
    for(int i=0; i<M; i++){
        cin>>a>>b;
        arr[a][b]=1;       
    }
    for(int k=1; k<=N; k++){
        for(int i=1; i<=N; i++){
            for(int j=1; j<=N; j++){
                if(arr[i][k]&&arr[k][j]){
                    arr[i][j]=1; 
                }
            }
        }
    }

     for(int i=1; i<=N; i++){
        for(int j=1; j<=N; j++){
            if(arr[i][j]) arr[j][i]=1;
        }
    }

    for(int i=1; i<=N; i++){
        int cnt=0;
        for(int j=1; j<=N; j++){
            if(arr[i][j]) cnt++;
        }
        cout<<N-1-cnt<<"\n";
    }

    return 0;
} 
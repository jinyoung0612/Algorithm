#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

#define MAX 10
int N,M;
int arr[MAX];
bool check[MAX];
int res[MAX];

void permutation(int depth){
    if(depth==M){
        for(int i=0; i<M; i++){
            cout<<res[i]<<" ";
        }
        cout<<"\n";
        return;
    }

    for(int i=0; i<N; i++){
      
        res[depth]=arr[i];
        permutation(depth+1);
        
    }
}

void combination(int idx, int depth){
    if(depth==M){
        for(int i=0; i<M; i++){
            cout<<res[i]<<" ";
        }

        cout<<"\n";
        return;
    }

    for(int i=idx; i<N; i++){
        res[depth]=arr[i];
        combination(i+1, depth+1);
    }
}
int main(void){   
    cin.tie(NULL);
    ios::sync_with_stdio(false);

   
    cin>>N>>M;

    for(int i=0; i<N; i++){
        arr[i]=i+1;
    }

    permutation(0);
    // combination(0,0);


   
    return 0;

}

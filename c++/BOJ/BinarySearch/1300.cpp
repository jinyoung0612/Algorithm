
#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

#define MAX 101
 

int main(void){   
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    
    int N,k;
    cin>>N>>k;

    int left=0;
    int right=N*N;
    vector<int> B;
    for(int i=1; i<=N; i++){
        for(int j=1; j<=N; j++){
            B.push_back(i*j);
        }
    }
    
    while(left<=right){
        int mid=(left+right)/2;

    }

    
    return 0;

}

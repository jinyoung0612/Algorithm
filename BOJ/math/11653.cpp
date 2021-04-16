
#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

#define MAX 10000001
int arr[MAX];
int main(void){   

    int N;
    cin>>N;

    // 1. 에라토스테네스의 체 600ms
    // vector<int> v;
    // for(int i=2; i*i<=N; i++){
    //     for(int j=i*i; j<=N; j+=i){
    //         arr[j]=1;
    //     }
    // }

    // for(int i=2; i<=N; i++){
    //     if(arr[i]==0) v.push_back(i);
    // }

    // int idx=0;
    // while(N!=1){
    //     if(N%v[idx]==0){
    //         cout<<v[idx]<<"\n";
    //         N/=v[idx];
    //     }
    //     else{
    //         idx+=1;
    //     }
    // }

    // 2. 반복문 0ms

    for(int i=2; i<=sqrt(N); i++){
        
        while(N%i==0){
            cout<<i<<"\n";
            N/=i;
        }
    }
    if(N!=1) cout<<N<<"\n";
    
    return 0;

}

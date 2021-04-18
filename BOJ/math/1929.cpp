#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

#define MAX 1000001
bool arr[MAX];
int main(void){
    int M,N;
    
    cin>>M>>N;
    arr[1]=1;
    for(int i=2; i<sqrt(N); i++){
        for(int j=i*i; j<=N; j+=i){
            if(arr[j]==0){
                arr[j]=1;
            }
        }
    }
    for(int i=M; i<=N; i++){
        if(arr[i]==0){
            cout<<i<<"\n";
        }
    }
    
    return 0;
}
#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

#define MAX 1000001

int arr[MAX];

int main(void){
    int N;
    int B,C;
    
    cin>>N;
    for(int i=0; i<N; i++){
       cin>>arr[i];
    }
    cin>>B>>C;
    
    long long result=0;

    for(int i=0; i<N; i++){
        int st=arr[i];
        st-=B;
        result++;
        if(st>0){
            if(st<C){
                result++;
            }
            else if(st%C==0){
                result=result+(st/C);
            }
            else{
                result=result+(st/C)+1;
            }  
        }
    }
    cout<<result;

    return 0;
}

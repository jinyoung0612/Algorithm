#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

#define MAX 1000001

int main(void){
    int t,n;
    
    long long arr[MAX];
    arr[1]=1;
    arr[2]=2;
    arr[3]=4;
    cin>>t;
    for(int i=0; i<t; i++){
        cin>>n;
         for(int i=4; i<=n;i++){
            arr[i]=(arr[i-3]+arr[i-2]+arr[i-1])%1000000009;
        }
        cout<<arr[n]<<"\n";
    }
    return 0;
}
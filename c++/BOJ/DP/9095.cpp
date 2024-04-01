#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

#define MAX 11

int main(void){
    int t,n;
    
    int arr[MAX];
    arr[1]=1;
    arr[2]=2;
    arr[3]=4;
    for(int i=4; i<=11;i++){
            arr[i]=arr[i-3]+arr[i-2]+arr[i-1];
    }
    cin>>t;
    for(int i=0; i<t; i++){
        cin>>n;
        cout<<arr[n]<<"\n";
    }
    return 0;
}
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

#define MAX 100001

int main(void){
    int t,n;
    
    long long arr[MAX][4];
    cin>>t;

    arr[1][1]=1;
    arr[2][2]=1;
    arr[3][3]=1;
    arr[3][2]=1;
    arr[3][1]=1;
    
    for(int i=0; i<t; i++){
        cin>>n;

         for(int i=4; i<=n;i++){
            if(i-1>=0){
                arr[i][1]=(arr[i-1][2]+arr[i-1][3])%1000000009;
            }
            if(i-2>=0){
                arr[i][2]=(arr[i-2][1]+arr[i-2][3])%1000000009;
            }
            if(i-3>=0){
                arr[i][3]=(arr[i-3][1]+arr[i-3][2])%1000000009;
            }
        }
        cout<<(arr[n][1]+arr[n][2]+arr[n][3])%1000000009<<"\n";
    }
    return 0;
}
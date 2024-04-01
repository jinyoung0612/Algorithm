
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

#define MAX 100001

int arr[15][15];

int main(void){   
int T;
cin>>T;
int k,n;

for(int i=1; i<=14; i++){
    arr[0][i]=i;
}
for(int i=1; i<=14; i++){
    for(int j=1; j<=14; j++){
        arr[i][j]=arr[i-1][j]+arr[i][j-1];
    }
}

while(T-->0){
    cin>>k>>n;
    cout<<arr[k][n]<<"\n";
}


 return 0;

}

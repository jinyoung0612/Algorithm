#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define MAX 1001

int arr[MAX];
int main(void){
    int n;
    cin>>n;
    arr[1]=1;
    arr[2]=3;

    for(int i=3; i<=n; i++){
        arr[i]=(arr[i-1]+2*arr[i-2])%10007;
    }
    cout<<arr[n];
    return 0;
}
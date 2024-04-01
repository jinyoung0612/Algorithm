#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <cmath>
using namespace std;

#define MAX 100001

int arr[MAX];

int main(void){
    
    ios::sync_with_stdio(false);
    cin.tie(0);
    int N;
    cin>>N;
    for(int i=0; i<N; i++){
        cin>>arr[i];
    }
    sort(arr,arr+N);
    
    int start=0;
    int end=N-1;
    int v1,v2;
    
    int temp= 2000000001;
    
    while(start<end){
        if(temp>=abs(arr[start]+arr[end])){
            v1=arr[start];
            v2=arr[end];
            temp=abs(arr[start]+arr[end]);
        }
        if(arr[start]+arr[end]>0)end--;
        else start++;
    }
    cout<<v1<<" "<<v2;
    return 0;
} 
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;
#define MAX 2000000
int result[MAX];


int main(void){
    cin.tie(NULL);
	ios_base::sync_with_stdio(false);
    
    int N,M;
    cin>>N>>M;
    int arr1[N];
    int arr2[M];
  
    for(int i=0; i<N; i++){
        cin>>arr1[i];
    }
     for(int i=0; i<M; i++){
        cin>>arr2[i];
    }
    int idx=0;
    int a=0;
    int b=0;
    ////// 투포인터 512ms //////
    while( a<N && b<M){
        if(arr1[a]<=arr2[b]){
            result[idx++]=arr1[a++];
        }
        else{
            result[idx++]=arr2[b++];
        }
    }

    while(a<N) result[idx++]=arr1[a++];
    while(b<M) result[idx++]=arr2[b++];

    for(int i=0; i<idx; i++){
        cout<<result[i]<<" ";
    }


////// 그냥 sort 704ms //////
   
    // int N,M;
    // cin>>N>>M;
    // int arr1[N+M];

    // for(int i=0; i<N; i++){
    //     cin>>arr1[i];
    // }
    //  for(int i=0; i<M; i++){
    //     cin>>arr1[i+N];
    // }
    // sort(arr1,arr1+N+M);
    // for(int i=0; i<N+M; i++){
    //     cout<<arr1[i]<<" ";
    // }

     




    return 0;
}
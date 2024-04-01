#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

#define MAX 200001
int arr[MAX];
int main(void){   
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int N,C;
    cin>>N>>C;

    for(int i=0; i<N; i++){
        cin>>arr[i];
    }

    sort(arr,arr+N);

    int left=1; // 가능한 최소 거리
    int right=arr[N-1]-arr[0]; // 가능한 최대 거리
    int answer=0;

    while(left<=right){
        int mid=(left+right)/2;
        int cnt=1;
        int start=arr[0];

        for(int i=1; i<N; i++){
            int dist=arr[i]-start;
            if(mid<=dist){
                cnt+=1;
                start=arr[i];
            }

        }
        if(cnt>=C){
            answer=mid;
            left=mid+1;
        }
        else{
            right=mid-1;
        }
    }

    cout<<answer;

    

    
    return 0;

}

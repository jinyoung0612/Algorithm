#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define MAX 10001

int n,m;
int seq[MAX];

int main(void){
  
    cin>>n>>m;
    for(int i=1; i<=n; i++){
        cin>>seq[i];
    }

    int answer=0;
    // for(int i=1; i<=n; i++){
    //     int sum=seq[i];
    //     if(sum==m){
    //         answer++;
    //         continue;
    //     }
    //     for(int j=i+1; j<=n; j++){
    //         sum+=seq[j];
    //         if(sum==m){
    //             answer++;
    //             break;
    //         }
    //         else if(sum>m) break;
    //     }
    // }

    int low=1,high=1,sum=0;
    while(1){
        if(sum>=m)sum-=seq[low++];
        else if(high==n+1) break;
        else sum+=seq[high++];
        
        if(sum==m) answer++;

    }
    cout<<answer;

    return 0;
}
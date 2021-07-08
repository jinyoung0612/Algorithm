#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

#define MAX 100001 
long long t[MAX];

int main(void){   
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int N,M;
    cin>>N>>M;
    for(int i=0; i<N; i++){
        cin>>t[i];
    }
    sort(t,t+N);

    long long left=1;
    long long right=t[N-1]*M;
    long long answer=right;

    while(left<=right){
        long long mid=(left+right)/2;
        long long cnt=0;

        for(int i=0; i<N; i++){
            cnt+=(mid/t[i]);
        }

        if(cnt<M){
            left=mid+1;
        }
        else{
            answer=min(answer,mid);
            right=mid-1;
        }
    }
    cout<<answer;

   
    return 0;

}

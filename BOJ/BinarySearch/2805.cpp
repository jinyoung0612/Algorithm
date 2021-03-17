#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

#define MAX 1000001

int tree[MAX];
int main(void){
    int n,m;

    cin>>n>>m;
    int max_val=0;

    for(int i=0; i<n; i++){
        cin>>tree[i];
        max_val=max(max_val,tree[i]);
    }

    int left, right;
    int answer=0;
    left=0;
    right=max_val;

    while(left<=right){
        int mid=(left+right)/2;
        long long total=0;

        for(int i=0; i<n; i++){
            if(mid<tree[i]){
                total=total+tree[i]-mid;
            }
        }
        if(total>=m){
            if(answer<mid) answer=mid;
            
            left=mid+1;
        }
        else{
            right=mid-1;
        }
    }

    cout<<answer;

   
    return 0;
}
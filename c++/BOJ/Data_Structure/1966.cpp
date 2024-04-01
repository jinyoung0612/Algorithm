
#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

#define MAX 101

int doc[MAX];
int main(void){   
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    int T;
    cin>>T;
    int N,M;

    while(T--){
        cin>>N>>M;
        queue<int> q;
        int importance;

        for(int i=0; i<N; i++){
            cin>>importance;
            doc[i]=importance;
            q.push(i);
        }

        int cnt=1;
        while(1){
            int cur=q.front();
            q.pop();

            int max_val=0;
            for(int i=0; i<N; i++){
                max_val=max(max_val,doc[i]);
            }
            if(doc[cur]==max_val){
                if(cur==M){
                    cout<<cnt<<"\n";
                    break;
                }
                doc[cur]=0;
                cnt++;
            }
            else{
                q.push(cur);
            }
        }
        
    }
    return 0;

}

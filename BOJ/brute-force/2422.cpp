#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <cmath>
using namespace std;

#define MAX 201
vector<int> arr[MAX];

int N,M;
int result[3];
int answer=0;
void combination(int depth, int start){
    if(depth==3){
        
        for(int i=0; i<3; i++){
            for(int j=0; j<arr[result[i]].size(); j++){
                int num=arr[result[i]][j];
                if(i==0){
                    if(num==result[1] || num==result[2]) return;
                }
                else if(i==1){
                     if(num==result[0] || num==result[2]) return;
                }
                else if(i==2){
                     if(num==result[0] || num==result[1]) return;
                }
                
            }
        }
        answer++;
        return;
    }

    for(int i=start; i<=N; i++){
        result[depth]=i;
        combination(depth+1,i+1);
    }
}
int main(void){
    ios::sync_with_stdio(false);
    cin.tie(0);

    
    cin>>N>>M;
    vector<pair<int,int> >bad;
    int a,b;
    for(int i=0; i<M; i++){
        cin>>a>>b;
        arr[a].push_back(b);
    }
    combination(0,1);
    cout<<answer;
    return 0;
} 
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <queue>
using namespace std;

#define MAX 100001

int arr[MAX];
bool visited[MAX];
bool isGroup[MAX];

int cnt=0;
void dfs(int start){
    visited[start]=1;
    int next=arr[start];

    if(!visited[next]) dfs(next);
    else if(!isGroup[next]){
        for(int i=next; i!=start; i=arr[i]){
            cnt++;
        }
        cnt+=1;
    }  
    isGroup[start]=1; 
}
int main(void){
    
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T;
    cin>>T;
    int n;
  
    while(T--){
        cin>>n;
        cnt=0;
        memset(visited,false,sizeof(visited));
        memset(isGroup,false,sizeof(isGroup));
     
        for(int i=1; i<=n; i++){
            cin>>arr[i];
        }
       

        for(int i=1; i<=n; i++){   
            if(!visited[i]){
                dfs(i);
            }  
        }
        cout<<n-cnt<<"\n";
    }






    return 0;
} 
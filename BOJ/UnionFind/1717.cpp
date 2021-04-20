#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

#define MAX 1000002
int set[MAX];

int getParent(int x){
    if(set[x]==x) return x;
    return set[x]=getParent(set[x]);
}
void unionParent(int a, int b){
    a=getParent(a);
    b=getParent(b);

    if(a<b) set[b]=a;
    else set[a]=b;
}
int main(void){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n,m;
    cin>>n>>m;
    bool flag;
    int a,b;
    
    for(int i=0; i<=n; i++){
        set[i]=i;
    }

    while(m--){
        cin>>flag>>a>>b;
        
        if(flag==0){
            unionParent(a,b);
        }
        else{
            if(getParent(a)!=getParent(b)){
                cout<<"NO\n";
            }
            else{
                cout<<"YES\n";
            }
        }
    }
    return 0;
}
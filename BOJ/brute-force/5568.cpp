#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <set>
using namespace std;

#define MAX 1001
 
int N,k;
int card[10];
int Select[4];
bool check[10];
set<string> s;

void permutation(int depth){
    if(depth==k){
        string temp="";
        for(int i=0; i<k; i++){
           temp+=to_string(card[Select[i]]);
        }
        s.insert(temp);
        return;
    }
    for(int i=0; i<N; i++){
        if(!check[i]){
            check[i]=1;
            Select[depth]=i;
            permutation(depth+1);
            check[i]=0;
        }
    }
}
int main(void){
    
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin>>N>>k;
    for(int i=0; i<N; i++){
        cin>>card[i];
    }
    permutation(0);
    cout<<s.size();
    return 0;
} 
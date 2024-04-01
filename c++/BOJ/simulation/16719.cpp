#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

#define MAX 101
#define INF 100
bool check[MAX];
string str;

void recursion(int start, int end){
    
    int min_val=INF;
    int idx=-1;

    for(int i=start; i<end; i++){
        if(!check[i]&&str[i]<min_val){
            min_val=str[i];
            idx=i;
        }
    }
    if(min_val==INF) return;
    check[idx]=1;
    for(int i=0; i<str.size(); i++){
        if(check[i]){
            cout<<str[i];
        }
    }
    cout<<"\n";
    recursion(idx+1,end);
    recursion(start,idx);
}
int main(void){
    
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin>>str;

    recursion(0,str.size());
    

    return 0;
} 
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

#define MAX 10001
int tree[MAX];

void postorder(int start, int end){
    if(start>end) return;
    int root=tree[start];
    int last=end;

    while(tree[last]>root){
        last-=1;
    }
    postorder(start+1,last);
    postorder(last+1,end);
    cout<<root<<"\n";
}

int main(void){
    int num;
    int cnt=0;

    while(scanf("%d",&num)!=-1){
        tree[cnt++]=num;
    }
    postorder(0,cnt-1);
    return 0;
}
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>

using namespace std;

#define MAX 202

int a,b,c;
bool visited[MAX][MAX][MAX];
vector<int> ans;

struct water{
    int a;
    int b;
    int c;
};

void bfs(){
    queue<water> q;
    water w={0,0,c};
    q.push(w);

    while(!q.empty()){
        water cur=q.front();
        q.pop();

        if(cur.a==0){
            ans.push_back(cur.c);
        }

        if(!visited[cur.a][cur.b][cur.c]){
            visited[cur.a][cur.b][cur.c]=1;
            water tmp;

            //a->b
            if(cur.a+cur.b>b){
                tmp.a=(cur.a+cur.b)-b;
                tmp.b=b;
                tmp.c=cur.c;
                q.push(tmp);
            }
            else{
                tmp.a=0;
                tmp.b=cur.a+cur.b;
                tmp.c=cur.c;
                q.push(tmp);
            }

            //a->c
            if(cur.a+cur.c>c){
                tmp.a=(cur.a+cur.c)-c;
                tmp.b=cur.b;
                tmp.c=c;
                q.push(tmp);
            }
            else{
                tmp.a=0;
                tmp.b=cur.b;
                tmp.c=cur.a+cur.c;
                q.push(tmp);
            }

            //b->a
            if(cur.a+cur.b>a){
                tmp.a=a;
                tmp.b=(cur.a+cur.b)-a;
                tmp.c=cur.c;
                q.push(tmp);
            }
            else{
                tmp.a=cur.a+cur.b;
                tmp.b=0;
                tmp.c=cur.c;
                q.push(tmp);
            }

            //b->c

             if(cur.b+cur.c>c){
                tmp.a=cur.a;
                tmp.b=(cur.b+cur.c)-c;
                tmp.c=c;
                q.push(tmp);
            }
            else{
                tmp.a=cur.a;
                tmp.b=0;
                tmp.c=cur.b+cur.c;
                q.push(tmp);
            }

            //c->a
             if(cur.c+cur.a>a){
                tmp.a=a;
                tmp.b=cur.b;
                tmp.c=(cur.c+cur.a)-a;
                q.push(tmp);
            }
            else{
                tmp.a=cur.c+cur.a;
                tmp.b=cur.b;
                tmp.c=0;
                q.push(tmp);
            }

            //c->b
             if(cur.b+cur.c>b){
                tmp.a=cur.a;
                tmp.b=b;
                tmp.c=(cur.b+cur.c)-b;
                q.push(tmp);
            }
            else{
                tmp.a=cur.a;
                tmp.b=cur.c+cur.b;
                tmp.c=0;
                q.push(tmp);
            }

        }
        
    }

}
int main(void){
    
    cin>>a>>b>>c;
    bfs();
    sort(ans.begin(),ans.end());
    ans.erase(unique(ans.begin(),ans.end()),ans.end());
    for(int i=0; i<ans.size(); i++){
        cout<<ans[i]<<" ";
    }
    return 0;
}
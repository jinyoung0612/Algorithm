#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

#define MAX 1001
int s;
int arr[MAX];
int visited[MAX][MAX]={0,}; //display, clipboard

struct emoji{
    int disp, clip, time;
};

int16_t bfs(){
    queue<emoji> q;
    emoji init={1,0,0};
    q.push(init);
    visited[1][0]=1;

    while(!q.empty()){
        int fdisp=q.front().disp;
        int fclip=q.front().clip;
        int ftime=q.front().time;
        q.pop();

        if(fdisp==s) return ftime;
        
        if(0<fdisp&&fdisp<MAX){
            if(!visited[fdisp][fdisp]){
                visited[fdisp][fdisp]=1;
                emoji temp={fdisp,fdisp,ftime+1};
                q.push(temp);
            }
            if(0<fclip&&fdisp+fclip<MAX){
                if(!visited[fdisp+fclip][fclip]){
                    visited[fdisp+fclip][fclip]=1;
                    emoji temp2={fdisp+fclip,fclip,ftime+1};
                    q.push(temp2);
                }
            }
            if(0<fdisp-1){
                if(!visited[fdisp-1][fclip]){
                    visited[fdisp-1][fclip]=1;
                    emoji temp3={fdisp-1,fclip,ftime+1};
                    q.push(temp3);
                }
            }

        }
    }
    return 0;
}

int main(void){
    int cnt=0;
    cin>>s;
    cout<<bfs();
    return 0;
}
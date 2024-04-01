#include <iostream>
#include <vector>
#include <algorithm>
// #include <cstring>
#include <string>
using namespace std;

#define MAX 10001

int main(void){

    string now,wait;
    cin>>now>>wait;
    
    vector<int> v;
    vector<int> v2;
    string tmp;
    int ans[3];
    for(int i=0; i<now.size(); i++){
   
        if(now[i]==':'){
            v.push_back(stoi(tmp));
            tmp.clear();
        }
        else{
            tmp+=now[i];
        }
    }
    v.push_back(stoi(tmp));

    string tmp2;
    for(int i=0; i<wait.size(); i++){
   
        if(wait[i]==':'){
            v2.push_back(stoi(tmp2));
            tmp2.clear();
        }
        else{
            tmp2+=wait[i];
        }
    }
    v2.push_back(stoi(tmp2));   

    if(v2[2]>=v[2]){
        ans[2]=v2[2]-v[2];
    }
    else{
        ans[2]=60+v2[2]-v[2];
        v2[1]--;
    }

    if(v2[1]>=v[1]){
        ans[1]=v2[1]-v[1];
    }
    else{
        ans[1]=60+v2[1]-v[1];
        v2[0]--;
    }
    if(v2[0]>=v[0]){
        ans[0]=v2[0]-v[0];
    }
    else{
        ans[0]=24+v2[0]-v[0];
    }
    
    if(ans[0]==0&&ans[1]==0&&ans[2]==0){
        ans[0]=24;
    }

    for(int i=0; i<3; i++){
        if(ans[i]<10){
            cout<<'0'<<ans[i];
        }
        else{
            cout<<ans[i];
        }
        if(i!=2){
            cout<<":";
        }
    }

    return 0;
}
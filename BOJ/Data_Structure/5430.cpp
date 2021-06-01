#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <queue>
using namespace std;

#define MAX 1001


int main(void){
    
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T;
    cin>>T;
    string p;
    int N;
    string arr;

    while(T--){
        cin>>p;
        cin>>N;
        cin>>arr;
        deque<int> dq;
        arr=arr.substr(1,arr.size()-2);
        string temp="";
        for(int i=0; i<arr.size(); i++){
            if(arr[i]==','){
                dq.push_back(stoi(temp));
                temp="";
                continue;
            }
            temp+=arr[i];
        }
        if(temp.size()>0){
            dq.push_back(stoi(temp));
        }
        bool reverse=false;
        bool err=false;
        for(int i=0; i<p.size(); i++){
            if(p[i]=='R'){
                reverse=!reverse;
            }
            else{
                if(dq.empty()){
                    cout<<"error\n";
                    err=true;
                    break;
                }
                else{
                    if(reverse) dq.pop_back();
                    else dq.pop_front();
                }
            }
        }

        if(!err){
            cout<<'[';
            if(!dq.empty()){
                if(reverse){
                    while(1){
                        cout<<dq.back();
                        dq.pop_back();
                        if(dq.empty()) break;
                        else cout<<",";
                    }
                }
                else{
                    while(1){
                        cout<<dq.front();
                        dq.pop_front();
                        if(dq.empty()) break;
                        else cout<<",";
                    }
                }
            }
            
            cout<<"]\n";
        }
        
    }

   

    return 0;
} 
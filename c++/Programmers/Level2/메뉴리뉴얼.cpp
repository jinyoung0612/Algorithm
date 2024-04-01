#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <iostream>
#include <cstring>
using namespace std;
map<string,int> combi;
int check[11];

void combination(string str,int start, int depth,int c){
    if(depth==c){
        string temp="";
        for(int i=0; i<c; i++){
            temp+=str[check[i]];
        }
        combi[temp]+=1;
        return;
    }
    for(int i=start; i<str.size(); i++){
        check[depth]=i;
        combination(str,i+1,depth+1,c);
    }
}

vector<string> solution(vector<string> orders, vector<int> course) {
    vector<string> answer;

    for(int i=0; i<orders.size(); i++){
        sort(orders[i].begin(),orders[i].end());
        
    }
    // for(int c:course){
    //     for(int i=0; i<orders.size(); i++){
    //         memset(check,false,sizeof(check));
    //         combination(orders[i],0,0,c);
    //     }
        
    //     int max_val=0;
        
    //     for(auto key:combi){
    //         max_val=max(max_val,key.second);
    //     }
        
    //     for(auto key:combi){
    //         if(key.second==max_val&&max_val>=2){
    //             answer.push_back(key.first);
    //         }
    //     }
    //     combi.clear();
        
    // }
    sort(answer.begin(),answer.end());
    return answer;
}
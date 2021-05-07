#include <string>
#include <vector>
#include <set>
#include <algorithm>
#include <iostream>
#include <cstring>
using namespace std;

int N;
int M;
int check[9];
vector<string> user;
vector<string> ban;
bool visited[9];
bool Select[9];
set<vector<string>> s;
bool isBan(string str){

    for(int i=0; i<M; i++){
        bool flag=true;

        if(str.size()!=ban[i].size()||visited[i]) continue;
        for(int j=0; j<ban[i].size(); j++){
            if(ban[i][j]=='*') continue;
            if(ban[i][j]!=str[j]) flag=false;
        }
        if(flag){
            visited[i]=1;
            return true;
        }
    }
    return false;
}
void permutation(int depth){
    if(depth==M){
        int cnt=0;
        memset(visited,false,sizeof(visited));
        for(int i=0; i<M; i++){
            if(isBan(user[check[i]])) cnt++;
        }
        if(cnt==M){
            vector<string> v;
            for(int i=0; i<M; i++){
                v.push_back(user[check[i]]);
            }
            sort(v.begin(),v.end());
            s.insert(v);
        }
        return;
    }
    for(int i=0; i<N; i++){
        if(!Select[i]){
            check[depth]=i;
            Select[i]=1;
            permutation(depth+1);
            Select[i]=0;
        }
        
    }
}
int solution(vector<string> user_id, vector<string> banned_id) {
   int answer = 0;
    N=user_id.size();
    M=banned_id.size();
    user=user_id;
    ban=banned_id;
    
    permutation(0);

    answer=s.size();
    return answer;
}

int main(){
    vector<string> user_id={"frodo", "fradi", "crodo", "abc123", "frodoc"};
    vector<string> banned_id={"fr*d*", "abc1**"};
    cout<<solution(user_id,banned_id);
}
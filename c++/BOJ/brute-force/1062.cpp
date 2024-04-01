#include <iostream>
#include <cstring>
#include <string>

using namespace std;

int N,K;
char arr[51][16];
int answer;
bool Select[26];


void dfs(int depth, int alpha){

    if(depth==K-5){
        int cnt=0;
        
        for(int i=0; i<N; i++){
            bool flag=true;
            string str=arr[i];
            for(int j=0; j<str.size(); j++){
                if(!Select[str[j]-'a']){
                    flag=false;
                    break;
                }
            }
            if(flag){
                cnt++;
            }
        }
       
        answer=max(answer,cnt);
        return;
    }

    for(int i=alpha; i<26; i++){
        if(!Select[i]){
            Select[i]=1;
            dfs(depth+1,i+1);
            Select[i]=0;
        }
    }


}

int main(void) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin>>N>>K;
    string str;
    for(int i=0; i<N; i++){
        cin>>str;
        for(int j=0; j<str.size(); j++){
            arr[i][j]=str[j];
        }
        string tmp=arr[i];
        tmp=tmp.substr(4);
        tmp=tmp.substr(0,tmp.size()-4);

    }

    Select['a'-'a']=1;
    Select['n'-'a']=1;
    Select['t'-'a']=1;
    Select['i'-'a']=1;
    Select['c'-'a']=1;

    if(K<5){
        cout<<0;
    }
    else if(K==26){
        cout<<N;
    }
    else{
        dfs(0,1);
        cout<<answer;
    }

    return 0;
}
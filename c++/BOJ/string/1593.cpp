#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

int lower[27];
int up[27];
int temp_lower[27];
int temp_up[27];
int main(void){
    
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int g,n;
    cin>>g>>n;
    string w;
    string s;
    cin>>w>>s;
    int answer=0;
    int start=0;
    int end=0;

    for(int i=0; i<g; i++){
        if('a'<=w[i]&&w[i]<='z'){
            lower[w[i]-'a']+=1;
        }
        else{
            up[w[i]-'A']+=1;
        }
    }
  
    while(end<g){
        if('a'<=s[end]&&s[end]<='z'){
            temp_lower[s[end]-'a']+=1;
        }
        else{
            temp_up[s[end]-'A']+=1;
        }
        end++;
    }
    
    bool flag1=true;
    for(int i=0; i<27; i++){
        if(temp_lower[i]!=lower[i]){
            flag1=false;
            break;
        }
        if(temp_up[i]!=up[i]){
            flag1=false;
            break;
        }
    }
    if(flag1)answer++;

    while(end<n){
        
        if('a'<=s[start]&&s[start]<='z'){
            temp_lower[s[start]-'a']-=1;
        }
        else{
            temp_up[s[start]-'A']-=1;
        }
    
        start++;

        if('a'<=s[end]&&s[end]<='z'){
            temp_lower[s[end]-'a']+=1;
        }
        else{
            temp_up[s[end]-'A']+=1;
        }
        end++;

        bool flag=true;
        for(int i=0; i<27; i++){
            if(temp_lower[i]!=lower[i]){
                flag=false;
                break;
            }
            if(temp_up[i]!=up[i]){
                flag=false;
                break;
            }
        }
        if(flag)answer++;
    }

    cout<<answer;
    return 0;
} 
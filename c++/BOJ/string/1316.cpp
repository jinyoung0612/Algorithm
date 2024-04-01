#include <iostream>
#include <vector>
#include <cstring>
#include <string>

using namespace std;

bool check[26];
int main(void){
    int N;
    cin>>N;
    int answer=0;
    string str;
    while(N-->0){
        cin>>str;
        bool flag=true;
        memset(check,false,sizeof(check));
        for(int i=0; i<str.size(); i++){
            
            if(!check[str[i]-'a']){
                check[str[i]-'a']=1;
            }
            else{
                if(i-1>=0&&str[i-1]!=str[i]){
                    flag=false;
                    break;
                }
            }
            
        }
        if(flag) answer+=1;
    
    }
   
    cout<<answer;
    return 0;
}
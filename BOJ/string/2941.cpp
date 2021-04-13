#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

#define MAX 10001

int main(void){
    string str;
    cin>>str;

    int answer=0;
    for(int i=0; i<str.size(); i++){
        if(str[i]=='l'){
            if(i+1<str.size()&&str[i+1]=='j'){
                i+=1;
            }
        }
        else if(str[i]=='n'){
            if(i+1<str.size()&&str[i+1]=='j'){
                i+=1;
            }
        }
        else if(str[i]=='c'){
            if(i+1<str.size()){
                if(str[i+1]=='=' || str[i+1]=='-'){
                     i+=1;
                }
            }
        }
        else if(str[i]=='s'){
            if(i+1<str.size()){
                if(str[i+1]=='='){
                     i+=1;
                }
            }
        }
        else if(str[i]=='z'){
            if(i+1<str.size()){
                if(str[i+1]=='='){
                     i+=1;
                }
            }
        }
        else if(str[i]=='d'){
            if(i+1<str.size()){
                if(str[i+1]=='-'){
                     i+=1;
                     answer+=1;
                     continue;
                }
            }
            if(i+2<str.size()){
                if(str[i+1]=='z'&&str[i+2]=='='){
                    i+=2;
                }
            }
        }
        answer+=1;
    }
    
    cout<<answer;
    return 0;
}
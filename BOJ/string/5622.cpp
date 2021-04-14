#include <iostream>
#include <vector>
#include <cstring>
#include <string>

using namespace std;

int main(void){
    string str;
    cin>>str;
    int result=0;

    for(int i=0; i<str.size(); i++){
        if('A'<=str[i]&&str[i]<='O'){
            result+=((str[i]-'A')/3)+2;;
        }
        else if('P'<=str[i]&&str[i]<='S'){
            result+=7;
        }
        else if('T'<=str[i]&&str[i]<='V'){
            result+=8;
        }
        else{
            result+=9;
        }
    }
    cout<<result+str.length();
   
    return 0;
}
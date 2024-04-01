#include <iostream>
#include <vector>
#include <cstring>
#include <string>
#include <algorithm>
using namespace std;

vector<string> parsing(string str){
    string temp;
    vector<string> ret;

    for(int i=0; i<str.size(); i++){
        if(str[i]==' '){
            if(temp=="") continue;
            ret.push_back(temp);
            temp="";
        }
        else{
            temp+=str[i];
        }

    }

    if(temp!=""){
        ret.push_back(temp);
    }
    
    return ret;
}

int main(void){
   
    string str;
    getline(cin,str);
    vector<string> ret=parsing(str);
    
    cout<<ret.size();
    
    return 0;
}
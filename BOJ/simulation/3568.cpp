#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <sstream>
#include <stack>
using namespace std;

string reverse_string(string str){
    string tmp="";
    for(int i=str.size()-1; i>=0; i--){

        if(('a'<=str[i]&&str[i]<='z' || 'A'<=str[i]&&str[i]<='Z')){
            break;
        }

        if(str[i]==';' || str[i]==',') continue;
        else if(str[i]==']'){
            tmp+=str[i-1];
            tmp+=str[i];
            i--;
        }
        else{
            tmp+=str[i];
        }
      
    }
    return tmp;
}
string var_name(string str){
    string tmp="";

    for(int i=0; i<str.size(); i++){
        if(('a'<=str[i]&&str[i]<='z' || 'A'<=str[i]&&str[i]<='Z')){
            tmp+=str[i];
        }
    }

    return tmp;
}
int main(void){
  
    string str;
    vector<string> v;

    getline(cin,str);

    stringstream s(str);
    string variable="";

    while(s>>variable){   
        v.push_back(variable);
    }




    for(int i=1; i<v.size(); i++){
        string answer=v[0];
        string rs="";
        string alpha="";
        for(int j=0; j<v[i].size(); j++){
            rs=reverse_string(v[i]);
            alpha=var_name(v[i]);
        }
        
       answer+=rs;
       answer+=" ";
       answer+=alpha;
       answer+=';';
       cout<<answer<<"\n";
    }

    return 0;
}
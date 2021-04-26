#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
bool cmp(pair<int,string> a, pair<int,string> b){
   return a.first>b.first;
}
vector<string> parsing(string str, char delimeter){
    string temp="";
    vector<string> ans;
    for(int i=0; i<str.size(); i++){
        
        if(str[i]==delimeter){
            ans.push_back(temp);
            temp="";
            continue;
        }
        temp+=str[i];
    }
    ans.push_back(temp);
    return ans;
}
string convertSharp(string str){
    string temp="";
    for(int i=0; i<str.size(); i++){
        if(i!=str.size()-1){
            if(str[i+1]=='#'){
                temp+=tolower(str[i]);
                i++;
                continue;
            }
        }
        temp+=str[i];
    }
    return temp;
}

string solution(string m, vector<string> musicinfos) {
    string answer = "";
    vector<pair<int,string> > v;
    
    for(int i=0; i<musicinfos.size(); i++){
        vector<string> temp=parsing(musicinfos[i],',');
        
        int start=stoi(temp[0].substr(0,2))*60+stoi(temp[0].substr(3,2));
        int end=stoi(temp[1].substr(0,2))*60+stoi(temp[1].substr(3,2));
        int times=end-start;
        
        string a=convertSharp(temp[3]);
        string b=convertSharp(m);
        
        int ssize=a.size();
        string str=a;
        int idx=0;
        if(str.size()>times){
            str=str.substr(0,times);
        }
        else{
            while(str.size()<times){
            str+=a[idx++%ssize];
            }
        }
          
        if(str.find(b)!=string::npos){
            v.push_back(make_pair(times,temp[2]));
        }
        
    }
    
    if(v.size()>0){
        stable_sort(v.begin(),v.end(),cmp);
        answer=v[0].second;
    }
    else{
        answer="(None)";
    }
    return answer;
}
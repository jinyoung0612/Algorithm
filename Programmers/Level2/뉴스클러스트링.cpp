#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include <cctype>
#include <cmath>
using namespace std;

int solution(string str1, string str2) {
    int answer = 0;
    vector<string> v1;
    vector<string> v2;
    
    for(int i=0; i+1<str1.size(); i++){
        
        if(isalpha(str1[i])&&isalpha(str1[i+1])){
            string temp="";
            temp+=str1[i];
            temp+=str1[i+1];
            transform(temp.begin(),temp.end(),temp.begin(),::tolower);
            v1.push_back(temp);
        }
    }
    for(int i=0; i+1<str2.size(); i++){
        
        if(isalpha(str2[i])&&isalpha(str2[i+1])){
            string temp="";
            temp+=str2[i];
            temp+=str2[i+1];
            transform(temp.begin(),temp.end(),temp.begin(),::tolower);
            v2.push_back(temp);
        }
    }
    
    sort(v1.begin(),v1.end());
    sort(v2.begin(),v2.end());
    
    // vector<string> buff(v1.size()+v2.size());
    // auto iter=set_intersection(v1.begin(),v1.end(),v2.begin(),v2.end(),buff.begin());
    // buff.erase(iter,buff.end());
    // int inter=buff.size();
    
    // vector<string> buff2(v1.size()+v2.size());
    // iter=set_union(v1.begin(),v1.end(),v2.begin(),v2.end(),buff2.begin());
    // buff2.erase(iter,buff2.end());
    // int uni=buff2.size();
    
    // if(inter==0&&uni==0){
    //     answer=65536;
    // }
    // else{
    //     answer=floor((double)inter/uni*65536);
    // }
    
    return answer;
    
    
}
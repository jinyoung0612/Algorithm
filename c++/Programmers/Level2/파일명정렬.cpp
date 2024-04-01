#include <string>
#include <vector>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <cctype>
using namespace std;

struct File{
    string head;
    string number;
    string tail;
};

int find_head(string str){
    for(int i=0; i<str.size(); i++){
        if(isdigit(str[i])){
            return i;
        }
    }
}
int find_number(string str){
    for(int i=0; i<str.size(); i++){
        if(!isdigit(str[i])){
            return i;
        }
    }
}
bool cmp(File a, File b){
    transform(a.head.begin(), a.head.end(), a.head.begin(), ::tolower);
    transform(b.head.begin(), b.head.end(), b.head.begin(), ::tolower);
    
    if(a.head==b.head){
        return stoi(a.number)<stoi(b.number);
    }
    else{
        return a.head<b.head;
    }
}

vector<string> solution(vector<string> files) {
    vector<string> answer;
    vector<File> v;
    
    for(int i=0; i<files.size(); i++){
        File file;
        string str=files[i];
        int head_num=find_head(str);
        file.head=str.substr(0,head_num);
        str=str.substr(head_num);
        
        int number_num=find_number(str);
        file.number=str.substr(0,number_num);
        file.tail=str.substr(number_num);
        
        v.push_back(file);
    }
    stable_sort(v.begin(),v.end(),cmp);
    for(int i=0; i<v.size(); i++){
        string str="";
        str+=v[i].head+v[i].number+v[i].tail;
        answer.push_back(str);
    }
    return answer;
}
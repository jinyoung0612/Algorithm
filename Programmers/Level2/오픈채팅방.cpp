#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <sstream>
#include <unordered_map>
using namespace std;

vector<string> solution(vector<string> record) {
    vector<string> answer;
    unordered_map<string,string> m;
    for(int i=0; i<record.size(); i++){
        stringstream ss;
        ss.str(record[i]);
        string inst;
        string uid;
        string nickname;
        ss>>inst>>uid>>nickname;
        
        if(inst=="Enter"){
            m[uid]=nickname;   
        }
        else if(inst=="Change"){
            m[uid]=nickname;
        }
        
    }
    
    for(int i=0; i<record.size(); i++){
        stringstream ss;
        ss.str(record[i]);
        string inst;
        string uid;
        string nickname;
        ss>>inst>>uid>>nickname;
        
        string temp="";
        if(inst=="Enter"){
            temp+=m[uid];
            temp+="님이 들어왔습니다."; 
        }
        else if(inst=="Leave"){
            temp+=m[uid];
            temp+="님이 나갔습니다."; 
        }
        else continue;
        answer.push_back(temp);
        
    }
    

    return answer;
}
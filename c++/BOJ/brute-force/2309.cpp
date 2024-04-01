#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int result[9];
int height[9];
bool flag=false;

void dfs(int start, int end){

    if(end==7){
        int sum=0;
        for(int i=0; i<7; i++){
            sum+=result[i];
        }
        if(sum==100){
            flag=true;
            for(int i=0; i<7; i++){
                cout<<result[i]<<endl;
            }
        }
        return;
    }

    for(int i=start; i<9; i++){
        // cout<<height[i];
        result[end]=height[i];
        dfs(i+1, end+1);
        if(flag) return;
    }
}
int main(void){

    for(int i=0; i<9; i++){
        cin>>height[i];
    }
    sort(height,height+9);

    dfs(0,0);

    return 0;
}

// #include <string>
// #include <vector>
// #include <algorithm>
// #include <sstream>
// #include <iostream>
// using namespace std;

// //숫자인지 판별하는 함수
// bool isNumber(string str){
//     for(int i=0; i<str.size(); i++){
//         if('0'<=str[i]&&str[i]<='9'){
//             continue;
//         }
//         else{
//             return false;
//         }
//     }
//     return true;
// }

// //문자열인지 판별하는 함수
// bool isString(string str){
    
//      for(int i=0; i<str.size(); i++){
//         if(('A'<=str[i]&&str[i]<='Z') || ('a'<=str[i]&&str[i]<='z')){
//             continue;
//         }
//         else{
//             return false;
//         }
//     }
//     return true;
// }

// int parsing(string str){
//     for(int i=0; i<str.size(); i++){
//         if(str[i]==' '){
//             return i;
//         }
//     }
//     return -1;
// }

// vector<bool> solution(string program, vector<string> flag_rules, vector<string> commands) {
//     vector<bool> answer;
    
//     //각 flag_name에 해당되는 flag_argument_type을 저장하는 map
//     unordered_map<string,string> rules;
    
//     //각 flag_name에 해당되는 flag_argument_type을 저장하는 과정
//     for(int i=0; i<flag_rules.size(); i++){
//         //string 받아오기
//         stringstream str(flag_rules[i]);
        
//         string flag_name="";
//         string argument_type="";
        
//         str>>flag_name;
//         str>>argument_type;
        
//         rules[flag_name]=argument_type;
       
//     }
    
//     //commands 길이 만큼 반복 
//     for(int i=0; i<commands.size(); i++){
//         bool flag=true;
//         string command=commands[i];
//         string argument_type="";
//         if(parsing(command)!=-1){
//             string program_name=command.substr(0,parsing(command));
//             string next=command.substr(parsing(command)+1);
//             if(program!=program_name){
//                 flag=false;
//                 break;
//             }
//             else{
//                 string flag_name=next.substr(0,parsing(next));
//                 next=next.substr(parsing(next)+1);
//                 if(rules[flag_name]==""){
//                     flag=false; 
//                     break;
//                 }
//                 else{
                    
                  
                    
//                     while(parsing(next)!=-1){
//                         argument_type=next.substr(0,parsing(next));
//                         next=next.substr(parsing(next)+1);
//                         cout<<argument_type;
//                         // flag_name에 해당되는 argument가 NULL 일때
//                         if(rules[flag_name]=="NULL"){
//                             if(argument_type!=""){
//                                 flag=false;
//                                 break;
//                             }
//                         }
//                          // flag_name에 해당되는 argument가 NUMBER 일때
//                         else if(rules[flag_name]=="NUMBER"){
//                            if(isNumber(argument_type)) continue;
//                             else{
//                                 flag=false;
//                                 break;
//                             }
//                         }
//                          // flag_name에 해당되는 argument가 STRING 일때
//                         else if(rules[flag_name]=="STRING"){

//                             if(isString(argument_type)) continue;
//                             else{
//                                 flag=false;
//                                 break;
//                             }

//                         }
//                          else if(rules[flag_name]=="STRINGS"){

//                             if(isString(argument_type)) continue;
//                             else{
//                                 flag=false;
//                                 break;
//                             }

//                         }
//                          else if(rules[flag_name]=="NUMBERS"){
//                              int cnt=0;
                             
//                              while(1){
//                                if(isNumber(argument_type)){
//                                     cnt++;
//                                     argument_type=next.substr(0,parsing(next));
//                                     next=next.substr(parsing(next)+1);
                                   
//                                 }
//                                 else{
//                                     if(cnt>=1){
                                        
                                        
//                                     }
//                                     else{
//                                         flag=false;
//                                         break;
//                                     }
//                                 }   
//                              }

//                         }
                        
//                     }
                    
                  
//             }
//         }
        
        
//         }
//     }
    
    
//     return answer;
// }

#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
#include <iostream>
using namespace std;

//숫자인지 판별하는 함수
bool isNumber(string str){
    for(int i=0; i<str.size(); i++){
        if('0'<=str[i]&&str[i]<='9'){
            continue;
        }
        else{
            return false;
        }
    }
    return true;
}

//문자열인지 판별하는 함수
bool isString(string str){
    
     for(int i=0; i<str.size(); i++){
        if(('A'<=str[i]&&str[i]<='Z') || ('a'<=str[i]&&str[i]<='z')){
            continue;
        }
        else{
            return false;
        }
    }
    return true;
}


// vector<bool> solution(string program, vector<string> flag_rules, vector<string> commands) {
//     vector<bool> answer;
    
//     //각 flag_name에 해당되는 flag_argument_type을 저장하는 map
//     unordered_map<string,string> rules;
    
//     //각 flag_name에 해당되는 flag_argument_type을 저장하는 과정
//     for(int i=0; i<flag_rules.size(); i++){
//         //string 받아오기
//         stringstream str(flag_rules[i]);
        
//         string flag_name="";
//         string argument_type="";
        
//         str>>flag_name;
//         str>>argument_type;
        
//         rules[flag_name]=argument_type;
       
//     }
    
//     vector<string> v;
//     //commands 길이 만큼 반복 
//     for(int i=0; i<commands.size(); i++){
//         bool flag=true;
        
//         stringstream command(commands[i]);
//         string str;
//         while(command){
//             command>>str;
//             v.push_back(str); 
//         }
//         v.pop_back();
       
//         for(int j=1; j<v.size(); j++){
//             bool flag=true;
//             int idx=1;
//             cout<<v[j];
//             if(rules[v[j]]==""){
//                 flag=false;
//                 break;
//             }
//             else{
//                 // flag_name에 해당되는 argument가 NULL 일때
//                 if(rules[v[j]]=="NULL"){
//                     if(j+1<v.size()){
//                         if(v[j+1]!=""){
//                             flag=false;
//                             break;
//                         }
//                     }
//                 }
//                  // flag_name에 해당되는 argument가 NUMBER 일때
//                 else if(rules[v[j]]=="NUMBER"){
//                     if(j+1<v.size()){
//                         if(isNumber(v[j+1])){
//                             j++;
//                             continue;
//                         } 
//                         else{
//                             flag=false;
//                             break;
//                         }
//                     }
                    
//                 }
//                  // flag_name에 해당되는 argument가 STRING 일때
//                 else if(rules[v[j]]=="STRING"){
//                     if(j+1<v.size()){
//                         if(isString(v[j+1])){
//                             j++;
//                             continue;
//                         }
//                         else{
//                             flag=false;
//                             break;
//                         }
//                     }
//                 }
//                 else if(rules[v[j]]=="STRINGS"){
//                     int cnt=0;
//                     while(1){
//                          if(j+1<v.size()){
//                             if(isString(v[j+1])){
//                                 j++;
//                                 cnt++;
//                                 idx++;
//                                 continue;
//                             }
//                             else{
//                                 if(cnt>=1){
//                                     j+=idx;
//                                     break;
//                                 }
//                                 else{
//                                     flag=false;
//                                     break;
//                                 }
//                             }
//                         }
//                     }
                   
//                 }
//                  else if(rules[v[j]]=="NUMBERS"){
//                     int cnt=0;
//                     while(1){
//                          if(j+1<v.size()){
//                             if(isNumber(v[j+1])){
//                                 j++;
//                                 cnt++;
//                                 idx++;
//                                 continue;
//                             }
//                             else{
//                                 if(cnt>=1){
//                                     j+=(idx);
//                                     break;
//                                 }
//                                 else{
//                                     flag=false;
//                                     break;
//                                 }
//                             }
//                         }
//                     }
                   
//                 }
             
//             }
//         }
//         if(v[0]!=program){
//             flag=false;
//         }
//          answer.push_back(flag);
//     }
    
   
   
    
//     return answer;
// }
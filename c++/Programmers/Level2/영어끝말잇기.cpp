#include <string>
#include <vector>
#include <iostream>
#include <map>
using namespace std;

vector<int> solution(int n, vector<string> words) {
    vector<int> answer(2,0);
    map<string,int> m;
    char temp=words[0][0];
    int flag=0;
    for(int i=0; i<words.size(); i++){
        if(words[i][0]!=temp || m[words[i]]){
            flag=i;
            break;
        }
        m[words[i]]=1;
        temp=words[i][words[i].size()-1];
    }
    
    if(flag!=0){
        answer[0]=flag%n+1;
        answer[1]=flag/n+1;
    }


    return answer;
}
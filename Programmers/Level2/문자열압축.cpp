#include <string>
#include <vector>
#include <iostream>
using namespace std;

int solution(string s) {
    int answer = 1001;
    
    for(int i=1; i<=s.size()/2; i++){
        string result="";
        string temp=s.substr(0,i);
        int coef=1;
        
        for(int j=i; j<s.size(); j+=i){
            
            if(s.substr(j,i)!=temp){
                
                if(coef>1){
                    result+=to_string(coef);
                }
                result+=temp;
                temp=s.substr(j,i);
                coef=1;
            }
            else{
                coef++;
            }
        }
        if(coef>1) result+=to_string(coef);
        result+=temp;
        
        answer=min(answer,(int)result.size());
              
    }
    
    if(s.size()==1) answer=1;
    
    return answer;
}
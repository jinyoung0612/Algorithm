#include <iostream>
#include <vector>
#include <cstring>
#include <string>
using namespace std;

// 1. 문자열 맨 마지막 부터
string reverse(string str){
    string tmp;
    for(int i=str.size()-1; i>=0; i--){
        tmp+=str[i];
    }
    return tmp;
}

// 2. 문자열 길이/2 만큼 반복
string reverse2(string str){
    int len=str.length();
    char tmp;
    for(int i=0; i<len/2; i++){
        tmp=str[i];
        str[i]=str[len-1-i];
        str[len-1-i]=tmp;
    }
    return str;
}

int main(void){
    string answer="";
    string str;
    getline(cin,str);

    string a,b,tmp;    
    for(int i=0; i<str.size(); i++){
        if(str[i]==' '){
            a=tmp;
            tmp="";
        }
        else{
            tmp+=str[i];
        }
    }
    b=tmp;
    a=reverse2(a);
    b=reverse2(b);
    
    // 3. getchar() 사용한 풀이
    // int i=0;
    // char str[1000];
    // while((str[i]=getchar())!=' ') i++;
    // i--;

    // while(i>-1){
    //     a+=str[i];
    //     i--;
    // }

    // i=0;
    // while((str[i]=getchar())!='\n') i++;
    // i--;

    // while(i>-1){
    //     b+=str[i];
    //     i--;
    // }


    answer=max(a,b);
    cout<<answer;
    return 0;
}
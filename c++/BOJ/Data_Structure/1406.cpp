#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <list>
#include <stack>
using namespace std;

#define MAX 1001

int main(void){
    
    ios::sync_with_stdio(false);
    cin.tie(0);

    string str;
    int M;
    cin>>str;
    cin>>M;
    char cmd;

    // 1. Linked List 사용 72ms: 삽입 삭제가 빈번하기 때문에 배열(그냥 string)은 시간초과 
    list<char> li(str.begin(),str.end());
    auto cur=li.end();
   
    for(int i=0; i<M; i++){
        cin>>cmd;
        if(cmd=='P'){
            char a;
            cin>>a;
            li.insert(cur,a);

        }
        else if(cmd=='L'&&cur!=li.begin()) cur--;
        else if(cmd=='D'&&cur!=li.end()) cur++;
        else if(cmd=='B'&&cur!=li.begin()){
            cur=li.erase(--cur); // list의 erase함수의 리턴값은 삭제 원소 다음에 있는 원소 iterator
        }

    }
    for(auto x:li){
        cout<<x;
    }

    // 2. Stack 사용 36ms
    stack<char> s1;
    stack<char> s2;
    for(int i=0; i<str.size(); i++){
        s1.push(str[i]);
    }
    for(int i=0; i<M; i++){
        cin>>cmd;
        if(cmd=='P'){
            char a;
            cin>>a;
            s1.push(a);
        }
        else if(cmd=='L'){
            if(!s1.empty()){
                s2.push(s1.top());
                s1.pop();
            }
        }
        else if(cmd=='B'){
            if(!s1.empty()){
                s1.pop();
            }
        }
        else if(cmd=='D'){
            if(!s2.empty()){
                s1.push(s2.top());
                s2.pop();
            }
        }
    }

    while(!s1.empty()){
        s2.push(s1.top());
        s1.pop();
    }
    while(!s2.empty()){
        cout<<s2.top();
        s2.pop();
    }


    return 0;
} 
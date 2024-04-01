
#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#include <stack>
#include <cmath>
using namespace std;

#define MAX 1000000000

int main(void){   
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    
    string cmd="";
    string cmd2="";
    vector<string> program;
    long long x;
    int N;

    while(1){
       
        while(1){
            cin>>cmd;
          
            if(cmd=="END"){
                program.push_back(cmd);
                break;
            }
            if(cmd=="QUIT"){
                return 0;
            }
            if(cmd=="NUM"){
                string n;
                cin>>n;
                cmd+=n;
            }
           
            program.push_back(cmd);
            
        }

       
        cin>>N;

        while(N--){
            stack<long long> st;
            cin>>x;
            st.push(x);
            bool flag=true;

            for(int i=0; i<program.size(); i++){
                string temp=program[i];

                if(temp=="POP"){
                    if(st.empty()){
                        flag=false;
                        cout<<"ERROR\n";
                        break;
                    }
                    st.pop();
                }
                else if(temp=="INV"){
                    if(st.empty()){
                        flag=false;
                        cout<<"ERROR\n";
                        break;
                    }
                    long long top=st.top();
                    st.pop();
                    st.push(top*-1);
                }
                else if(temp=="DUP"){
                    if(st.empty()){
                        flag=false;
                        cout<<"ERROR\n";
                        break;
                    }
                    long long top=st.top();
                    st.push(top);
                }
                else if(temp=="SWP"){
                    if(st.size()<2){
                        flag=false;
                        cout<<"ERROR\n";
                        break;
                    }
                    long long n1=st.top();
                    st.pop();
                    long long n2=st.top();
                    st.pop();
                    st.push(n1);
                    st.push(n2);
                }
                else if(temp=="ADD"){
                    if(st.size()<2){
                        flag=false;
                        cout<<"ERROR\n";
                        break;
                    }
                    long long n1=st.top();
                    st.pop();
                    long long n2=st.top();
                    st.pop();
                    st.push(n1+n2);
                }
                else if(temp=="SUB"){
                     if(st.size()<2){
                         flag=false;
                        cout<<"ERROR\n";
                        break;
                    }
                    long long n1=st.top();
                    st.pop();
                    long long n2=st.top();
                    st.pop();
                    st.push(n2-n1);
                }
                else if(temp=="MUL"){
                    if(st.size()<2){
                        flag=false;
                        cout<<"ERROR\n";
                        break;
                    }
                    long long n1=st.top();
                    st.pop();
                    long long n2=st.top();
                    st.pop();
                    st.push(n2*n1);
                }
                else if(temp=="DIV"){
                    
                    if(st.size()<2){
                        flag=false;
                        cout<<"ERROR\n";
                        break;
                    }
                    long long n1=st.top();
                    st.pop();
                    long long n2=st.top();
                    st.pop();

                    if(n1==0){
                        flag=false;
                        cout<<"ERROR\n";
                        break;
                    }
                    else{
                        st.push(n2/n1);
                    }

                }
                else if(temp=="MOD"){

                    if(st.size()<2){
                        flag=false;
                        cout<<"ERROR\n";
                        break;
                    }
                    long long n1=st.top();
                    st.pop();
                    long long n2=st.top();
                    st.pop();

                    if(n1==0){
                        flag=false;
                        cout<<"ERROR\n";
                        break;
                    }
                    else{
                        bool flag=true;
                        if(n2<0) flag=false;

                        if(flag){
                            st.push(abs(n2%n1));
                        }
                        else{
                            st.push(abs(n2%n1)*-1);
                        }

                    }

                }
                else if(temp.substr(0,3)=="NUM"){
                    long long num=stol(temp.substr(3));
                    st.push(num);
                }

                if(!st.empty()&&abs(st.top())>MAX){
                    flag=false;
                    cout<<"ERROR\n";
                    break;
                }
            }

            if(flag){
                if(st.size()!=1){
                    cout<<"ERROR\n";
                }
                else{
                    cout<<st.top()<<"\n";
                }
            }
            

        }
        program.clear();
        cout<<"\n";
  
    }
    
    
    return 0;

}

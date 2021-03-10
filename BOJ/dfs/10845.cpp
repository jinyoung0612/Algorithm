#include <iostream>
#include <vector>
#include <queue>
using namespace std;

#define MAX 100001

int main(void){
    int N;
    int num;
    string s;
    cin>>N;
    queue<int> q;
    queue<int> temp;

    for(int i=0; i<N; i++){
        cin>>s;
        if(s=="push"){
            cin>>num;
            q.push(num);
        }
        else if(s=="pop"){
            if(!q.empty()){
                cout<<q.front()<<endl;
                q.pop();
            }
            else{
                cout<<-1<<endl;;
            }
        }
        else if(s=="size"){
            cout<<q.size()<<endl;
        }
        else if(s=="empty"){
            q.empty() ? cout<<1 : cout <<0;
            cout<<endl;
        }
        else if(s=="front"){
            q.empty() ? cout<< -1 : cout <<q.front();
            cout<<endl;
        }
        else if(s=="back"){
            if(q.empty()){
                cout<<-1<<endl;
            }
            else{
                temp=q;
                while(temp.size()!=1){
                    temp.pop();
                }
                cout<<temp.front()<<endl;
            }
        }
    }
    return 0;
}
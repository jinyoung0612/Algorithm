#include <iostream>
#include <vector>

using namespace std;

#define MAX 10001

int stack[MAX];
int top_pointer=-1;

void push(int x){
  stack[++top_pointer]=x;
}

void pop(){
  if(top_pointer==-1){
    cout<<-1<<"\n";
  }
  else{
    cout<<stack[top_pointer]<<"\n";
    stack[top_pointer--]=0;
  }
}
void empty(){
  if(top_pointer==-1){
    cout<<1<<"\n";
  }
  else{
    cout<<0<<"\n";
  }
}
void size(){
  cout<<top_pointer+1<<"\n";
}
void top(){
  if(top_pointer==-1){
    cout<<-1<<"\n";
  }
  else{
     cout<<stack[top_pointer]<<"\n";
  }
}
int main(void){
  int N;
  cin>>N;
  string str;
  while(N>0){
      cin>>str;
      if(str=="push"){
        int num;
        cin>>num;
        push(num);

      }
      else if(str=="pop"){
        pop();
      }
      else if(str=="size"){
        size();
      }
      else if(str=="empty"){
        empty();
      }
      else if(str=="top"){
        top();
      }
      
      N--;
  }
   

    return 0;
}
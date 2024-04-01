#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;


int main(void){
   
   string s;
   string p;
   cin>>s;
   cin>>p;
   if(s.find(p)!=string::npos){
       cout<<1;
   }
   else{
       cout<<0;
   }

    return 0;
}
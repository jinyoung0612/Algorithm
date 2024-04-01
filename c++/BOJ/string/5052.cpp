#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

#define MAX 10001

int main(void){
   int t;
   int n;
   cin>>t;
   string str;

   for(int i=0; i<t; i++){
       cin>>n;
       vector<string> v;
       bool flag=true;

       for(int j=0; j<n; j++){
           cin>>str;
           v.push_back(str);
       }

       sort(v.begin(),v.end());
       
       for(int i=0; i<v.size()-1; i++){
           if(v[i]==v[i+1].substr(0,v[i].size())){
               flag=false;
               break;
           } 
       }
       flag==1 ? cout<<"YES" : cout<<"NO";
       cout<<"\n";
   }

   

    return 0;
}
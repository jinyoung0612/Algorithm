#include <iostream>
#include <cstring>
#include <algorithm>
#include <string>
using namespace std;

#define MAX 10001
int arr[26];

int main(void){
    int T;
    cin>>T;
    string str;

   cin.ignore();

   while(T>0){
        
        int answer=0;
        int cnt=0;
        int idx=0;
        char result;

        getline(cin,str);
        
        memset(arr,0,sizeof(arr));

        for(int i=0; i<str.length(); i++){
            if('a'<=str[i]&&str[i]<='z'){
                 arr[str[i]-'a']+=1;
            }
        }
  
        for(int i=0; i<26; i++){
            answer=max(answer,arr[i]);
        }
         for(int i=0; i<26; i++){
            if(arr[i]==answer){
                cnt++;
                idx=i;
            } 
        }

        if(cnt>1){
            cout<<'?'<<"\n";
        }
        else{
            result=idx+'a';
            cout<<result<<"\n";
        }

        T--;
   }

    return 0;
}
#include <iostream>
#include <vector>
#include <cstring>
#include <string>
#include <algorithm>
using namespace std;

int check[26];

int main(void){
   
    string str;
    cin>>str;

    for(int i=0; i<str.size(); i++){
        str[i]=toupper(str[i]);
        check[str[i]-'A']+=1;
    }

    vector< pair<int, char> > temp;
    for(int i=0; i<26; i++){
        if(check[i]>0){
            temp.push_back(make_pair(check[i],i+'A'));
        }
    }

    sort(temp.begin(),temp.end(),greater< pair<int,char> >());

    if(temp.size()>1&&temp[0].first==temp[1].first){
        cout<<'?';
    }
    else{
        cout<<temp[0].second;
    }

    return 0;
}
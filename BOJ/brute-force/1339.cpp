#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

#define MAX 21

int n;
char word[11][10];
int alpha[26];
int tmp[11];
int answer=0;
bool check[11]={0,};
vector<char> v;


void dfs(int depth){
    
    if(depth==v.size()){

        for(int i=0; i<v.size(); i++){
            alpha[v[i]-'A']=tmp[i];
        }
        int sum=0;

        for(int i=0; i<n; i++){
            string str=word[i];

            for(int j=0; j<str.size(); j++){
                sum+=(alpha[str[j]-'A']*pow(10,str.size()-j-1));
            }
        }
        
        answer=max(sum,answer);
      
        return;
    }
    
    for(int i=10-v.size(); i<10; i++){
        if(!check[i]){
            tmp[depth]=i;
            check[i]=1;
            dfs(depth+1);
            check[i]=0;
        }
    }
}
int main(void){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
   cin>>n;
   string str;
//    for(int i=0; i<n; i++){
//        cin>>str;
//        for(int j=0; j<str.length(); j++){
//            word[i][j]=str[j];
//            if(!alpha[str[j]-'A']){
//                v.push_back(str[j]);
//                alpha[str[j]-'A']=1;
//            } 
//        }
//    }
//    dfs(0);

   for(int i=0; i<n; i++){
       cin>>str;
       for(int j=0; j<str.length(); j++){
           word[i][j]=str[j];
       }
   }
    for(int i=0; i<n; i++){
        string tmp=word[i];
        for(int j=0; j<tmp.size(); j++){
            alpha[tmp[j]-'A']+=pow(10,tmp.size()-j-1);
        }
    } 
    sort(alpha,alpha+26);
    int num=9;
    for(int i=25; i>=0; i--){
        if(alpha[i]!=0){
            answer+=(alpha[i]*num);
            num--;
        }
    }
    cout<<answer<<"\n";
    return 0;
}
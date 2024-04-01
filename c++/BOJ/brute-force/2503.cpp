#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

#define MAX 1001
int N;
bool check[10];
int result[4];
int answer=0;
vector< pair<string, pair<int, int> > > v;

int Strike(string a, string b){
    int cnt=0;
    for(int i=0; i<3; i++){
        if(a[i]==b[i]){
            cnt++;
        }
    }
    return cnt;
}
int Ball(string a, string b){
    int cnt=0;
    for(int i=0; i<3; i++){
        if(a[i]!=b[i]){
            if(a.find(b[i])!=string::npos){
                cnt++;
            }
        }
    }
    return cnt;
}
void permutation(int depth){
    if(depth==3){
        string temp;
        
        for(int i=0; i<3; i++){
            temp+=(result[i]+'0');
        }
        
        int cnt=0;
        for(int i=0; i<v.size(); i++){
            if(Strike(temp,v[i].first)==v[i].second.first && Ball(temp,v[i].first)==v[i].second.second){
                cnt++;
            }
            else{
                break;
            }
        }
        if(cnt==v.size()){
            answer+=1;
        }
        return;
    }

    for(int i=1; i<=9; i++){
        if(!check[i]){
            check[i]=1;
            result[depth]=i;
            permutation(depth+1);
            check[i]=0;
        }
    }

}

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin>>N;

    string num;
    int st,ball;

    while(N--){
        cin>>num>>st>>ball;
        v.push_back(make_pair(num, make_pair(st,ball)));
    }
    permutation(0);
    cout<<answer;
    return 0;
}
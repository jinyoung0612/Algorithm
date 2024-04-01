#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

int N;
string answer="";
bool flag=false;

// 1. 처음 생각
// bool isBad(string str){

//    for(int i=1; i<=str.size()/2; i++){
//        for(int j=0; j<str.size()-i; j++){
//            string temp=str.substr(j,i);
//           if(temp==str.substr(j+i,i)) return true;

//        }
//    }
//    return false;
// }

// 2. 풀이 참조: 뒤에서부터 접근하면 시간단축
bool isBad(string str){

    int start=str.size()-1;
   for(int i=1; i<=str.size()/2; i++){
       if(str.substr(start,i)==str.substr(start-i,i)) return true;
       start-=1;
   }
   return false;
}

void goodSeq(int depth, string str){

    if(isBad(str)||flag) return;
    if(depth>=N){
        answer=str;
        flag=true;
        return;
    }

    goodSeq(depth+1,str+"1");
    goodSeq(depth+1,str+"2");
    goodSeq(depth+1,str+"3");


}

int main(void){
    
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>N;
    goodSeq(0,"");
    cout<<answer;
    return 0;
} 
#include <iostream>
#include <vector>
#include <string>
#include <sstream>
using namespace std;

#define MAX 10001

void reverse_string(string str){
    stringstream s(str);
    string tmp;
    while(s>>tmp){
        for(int i=tmp.size()-1; i>=0; i--){
            cout<<tmp[i];
        }
        cout<<" ";
    }
    cout<<"\n";
}

int main(void){
    int T;
    string str;
    cin>>T;
    cin.ignore();
    while(T>0){
        getline(cin,str);
        reverse_string(str);
        T--;
    }

    return 0;
}
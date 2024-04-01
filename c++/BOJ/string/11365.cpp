#include <iostream>
#include <cstring>

using namespace std;

int main(void){
    string str;
    while(1){
        getline(cin,str);
        if(str=="END") break;

        for(int i=str.size()-1; i>=0; i--){
            cout<<str[i];
        }
        
        cout<<"\n";
    }
    return 0;
}
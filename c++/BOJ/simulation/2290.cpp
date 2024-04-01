#include <iostream>
#include <string>

using namespace std;

int main(void){
    
    ios_base::sync_with_stdio(0); cin.tie(0);

    int s;
    string n;
    cin >> s >> n;

    for(int i=0; i<2*s+3; i++){
        for(int j=0; j<n.length(); j++){
            if(i==0){
                if(n[j]=='0' || n[j]=='2' || n[j]=='3' || n[j]=='5' || n[j]=='6' || n[j]=='7' || n[j]=='8' || n[j]=='9'){
                    cout << " ";
                    for(int k=0; k<s; k++){
                        cout << "-";
                    }
                    cout << " ";
                }
                else{
                    for(int k=0; k<s+2; k++){
                        cout << " ";
                    }
                }
            }
            else if(1<=i&&i<=s){
                if(n[j]=='0'||n[j]=='4'||n[j]=='8'||n[j]=='9'){
                    cout << "|";
                    for(int k=0; k<s; k++) {
                        cout << " ";
                    }  
                    cout << "|";
                }
                else if(n[j]=='1'||n[j]=='2'||n[j]=='3'||n[j]=='7'){
                    for(int k=0; k<s+1; k++) {
                        cout << " ";
                    }  
                    cout << "|";
                }
                else{
                    cout << "|";
                    for(int k=0; k<s+1; k++) {
                        cout << " ";
                    }  
                }
            }
            else if(i==s+1){
                if(n[j]=='0'||n[j]=='1'||n[j]=='7'){
                    for(int k=0; k<s+2; k++){
                        cout << " ";
                    }
                }
                else{
                    cout << " ";
                    for(int k=0; k<s; k++){
                        cout << "-";
                    }
                    cout << " ";
                }
            }
            else if(s+2<=i&&i<=2*s+1){
                if(n[j]=='0'||n[j]=='6'||n[j]=='8'){
                    cout << "|";
                    for(int k=0; k<s; k++) {
                        cout << " ";
                    }  
                    cout << "|";
                }
                else if(n[j]=='2'){
                    cout << "|";
                    for(int k=0; k<s+1; k++) {
                        cout << " ";
                    }  
                }
                else{
                    for(int k=0; k<s+1; k++) {
                        cout << " ";
                    }
                    cout << "|";  
                }
            }
            else{
                 if(n[j]=='0' || n[j]=='2' || n[j]=='3' || n[j]=='5' || n[j]=='6' || n[j]=='8' || n[j]=='9'){
                    cout << " ";
                    for(int k=0; k<s; k++){
                        cout << "-";
                    }
                    cout << " ";
                }
                else{
                    for(int k=0; k<s+2; k++){
                        cout << " ";
                    }
                }
            }
            cout << " ";
        }
        cout << "\n";
    }
    return 0;
}

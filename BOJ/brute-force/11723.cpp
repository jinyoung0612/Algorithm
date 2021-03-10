#include <iostream>
#include <string>
#include <cstring>
 
using namespace std;
 
int main(void) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
 
    const int MAX = 20 + 1;
    bool arr[MAX] = { 0 };
 
    int m;
    cin >> m;
    for (int i = 0; i < m; i++) {
        int num;
        string str;
        cin >> str;
 
        if (str == "add") {
            cin >> num;
 
            arr[num] = true;
        }
        else if (str == "remove") {
            cin >> num;
 
            arr[num] = false;
        }
        else if (str == "check") {
            cin >> num;
 
            if (arr[num])
                cout << "1\n";
            else
                cout << "0\n";
        }
        else if (str == "toggle") {
            cin >> num;
 
            if (arr[num])
                arr[num] = false;
            else
                arr[num] = true;
        }
        else if (str == "all") {
            memset(arr, true, sizeof(arr));
            }
        else {
            memset(arr, false, sizeof(arr));
        }
    }
    return 0;
}
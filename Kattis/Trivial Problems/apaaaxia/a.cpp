#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int main() {
    string str;
    cin >> str;
    
    char *cstr;

    cstr= new char[str.length()];

    for (int i = 0; i < str.length(); i++){
        cstr[i] = str[i];
    }
    cstr[str.length()] = '\0';

    char *p;
    
    p = unique(0, int(sizeof(cstr)));
   
    for(int i = 0; i<sizeof(p); i++) {
        cout << p[i];
    } 
    cout << endl;
 //   cout << p << endl;;
}



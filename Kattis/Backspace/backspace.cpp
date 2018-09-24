#include <iostream>
#include <string>

using namespace std;

int main() {
    string str;
    char in;
    while (cin >> in){
        if(in == '<')
            str.pop_back();
        else
            str += in;    
    }
    cout << str << endl;
}

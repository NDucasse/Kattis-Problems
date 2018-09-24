#include <iostream>
using namespace std;
int main() {
    int n, fizz, buzz, x;
    cin >> fizz >> buzz >> n;
    for (int i = 1; i <= n; i++) {
        if(i % fizz == 0) {
            cout << "Fizz";
        }
        if(i % buzz == 0) {
            cout << "Buzz";
        }
        if(i % fizz != 0 && i % buzz != 0) {
            cout << i;
        }
        cout << endl;
    }
}

#include <iostream>
using namespace std;
int main() {
    int in, x;
    cin >> in;
    for(int i = 0; i<in; i++) {
        cin >> x;
        if(x%2 == 0) {
            cout << x << " is even" << endl;
        } else {
            cout << x << " is odd" << endl;
        }
    }
}

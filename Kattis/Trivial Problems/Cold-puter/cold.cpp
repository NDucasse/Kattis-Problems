#include <iostream>

using namespace std;

int main() {
    int nums;
    int temp;
    int total = 0;
    cin >> nums;
    for(int i = 0; i<nums; i++) {
        cin >> temp;
        if(temp <0)
            total++;
    }
    cout << total << endl;
}

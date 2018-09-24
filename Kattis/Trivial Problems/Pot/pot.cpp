#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main() {
    int x = 0;
    int nums = 0;
    vector<int> data;
    int power;
    
    cin >> nums;

    for(int i = 0; i<nums; i++) {
        cin >> x;
        data.push_back(x);
    }

    x = 0;
    for(int i = 0; i<data.size(); i++) {
        power = data[i]%10;
        x += pow(data[i] / 10, power);
    }
    cout << x;
}

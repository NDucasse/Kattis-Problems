#include <iostream>

using namespace std;

int main() {
    int nums[] = {1, 1, 2, 2, 2, 8};
    int pieces[6];
    cin >> pieces[0] >> pieces[1] >> pieces[2] >> pieces[3] >> pieces[4] >> pieces[5];
    
    for(int i = 0; i<6; i++) {
        cout << nums[i] - pieces[i];
        if(i < 5) { cout << ' '; }
    }
    cout << endl;   
}

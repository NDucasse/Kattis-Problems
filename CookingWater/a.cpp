#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    int x, y, xmax = 0, ymin = INT_MAX;
    bool t = false;
    for(int i = 0; i < n; i++) {
        cin >> x >> y;
        if(x > ymin || y < xmax) {
            cout << "edward is right" << endl;   
            t = true;
            break;
        }
        if(y < ymin) {
            ymin = y;
        }
        if(x > xmax) {
            xmax = x;
        }
    }
    if(!t) {
        cout << "gunilla has a point" << endl;
    }
}

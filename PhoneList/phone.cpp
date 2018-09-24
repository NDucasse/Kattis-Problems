#include <bits/stdc++.h>
using namespace std;

int main() {
    int n = 0;
    cin >> n;
    while(n--) {
        int tc = 0;
        cin >> tc;
        vector<string> vec;
        while(tc--) {
            string temp;
            cin >> temp;
            vec.push_back(temp);
        }
        sort(vec.begin(), vec.end());
        string tempstr = vec[0];
        bool test1 = true;
        auto it = vec.begin();
        it++;
        for(it; it != vec.end(); it++) {
            bool test = true;
            for(int i = 0; i < tempstr.length() && i < (*it).length() && test; i++) {
                if((*it)[i] != tempstr[i]) {
                    test = false;
                }
            }
            tempstr = (*it);
            if(test) {
                cout << "NO" << endl;
                test1 = false;
                break;
            }
        }
        if(test1) {
            cout << "YES" << endl;
        }
    }
}

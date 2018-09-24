#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n, m, b = 0;
    string temp;
    bool c = false;
    char val;
    vector<map<char, vector<int>>> places;
    vector<string> strs;
    cin >> n >> m;
    places.resize(n);
    for(int i = 0; i < n; i++) {
        cin >> temp;
        for(std::string::iterator it = temp.begin(); it != temp.end(); it++) {
            val = *it;
            places[i][val].push_back(it-temp.begin());
        }
        strs.push_back(temp);
    }
    
    for(int i = 0; i < m; i++) {
        cin >> temp;
        temp[0] = tolower(temp[0]);
        temp[1] = tolower(temp[1]);
        temp[2] = tolower(temp[2]);
        c = false;
        for(int j = 0; j < n; j++) {
            if(places[j][temp[0]].size() == 0) {
                continue;
            }
            for(int k = 0; k < places[j][temp[1]].size(); k++) {
                if(places[j][temp[1]][k] > places[j][temp[0]][0]) {
                    b = places[j][temp[1]][k];
                    break;
                }
            }
            if(b != 0) {
                for(int k = 0; k < places[j][temp[2]].size(); k++) {
                    if(places[j][temp[2]][k] > b) {
                        c = true;
                    }
                }
                if(c) {
                    cout << strs[j] << endl;
                    break;
                }
            }
        }
        if(!c) {
            cout << "No valid word" << endl;
        }
    }
    
}

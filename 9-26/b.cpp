#include <bits/stdc++.h>
using namespace std;

bool compareChess(const string& lhs, const string& rhs) {
    if(lhs[1] == rhs[1]) {
        return lhs[0] < rhs[0];
    }
    return lhs[1] > rhs[1];
}

int main() {
    int test;
    cin >> test;
    map<string, vector<string>> board;
    map<string, int> dist;
    for(int i = 1; i < 9; i++) {
        for(int j = 0; j < 8; j++) {
            char pos = 'a' + j;
            string key = "";
            key += pos;
            key += '0' + i;
            vector<string> temp;
            board[key] = temp;
            dist[key] = -1;
            for(int k = -2; k < 3; k++) {
                if(k == 0) {
                    continue;
                }
                for(int l = -2; l < 3; l++) {
                    if(l == 0 || abs(k) == abs(l)) {
                        continue;
                    }
                    string newpos = "";
                    newpos += 'a' + (j + l);
                    newpos += '0' + (i + k);
                    if(newpos[0] < 'a' || newpos[0] > 'h' || newpos[1] < '1' || newpos[1] > '8' || newpos[0] == key[0] || newpos[1] == key[1]) {
                        continue;
                    }
                    board[key].push_back(newpos);
                }
            } 
        }
    }
    while(test--) {
        for(auto x : dist) {
            dist[x.first] = -1;
        }
        string start;
        cin >> start;
        deque<string> bfs; bfs.push_back(start);
        dist[start] = 0;
        while(bfs.size()) {
	        auto top = bfs.front(); bfs.pop_front();
	        for(auto item : board[top]) {
		        if(dist[item] == -1) {
			        dist[item] = dist[top] + 1;
			        bfs.push_back(item);
		        }
	        }
        }
        int max = 0;
        for(auto x : dist) {
            if(x.second > max) {
                max = x.second;
            }
        }
        cout << max;
        vector<string> maxes;
        for(auto x:dist) {
            if(x.second == max) {
                maxes.push_back(x.first);
            }
        }
        sort(maxes.begin(), maxes.end(), compareChess);
        for(auto x : maxes) {
            cout << " " << x;
        }
        cout << endl;
    }
    
}

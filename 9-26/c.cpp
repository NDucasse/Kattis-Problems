#include <bits/stdc++.h>
using namespace std;

int main() {
    int h, w;
    cin >> h >> w;
    vector<vector<int>> baltic(h, vector<int>(w));
    for(int i = 0; i < h; i++) {
        for(int j = 0; j < w; j++) {
            int val;
            cin >> val;
            baltic[i][j] = val;
        }
    }
    pair<int, int> drain;
    cin >> drain.first >> drain.second;
    
    int start, end; cin >> start >> end;
priority_queue<pair<int, int> > djk; djk.push({0, start}); //-dist, idx
vector<bool> seen(nodes, false);
while(djk.size() && djk.top().second != end) {
	int dist = -djk.top().first, spot = djk.top().second; djk.pop();
	if(seen[spot]) continue;
	for(auto next : adj[spot]) {
		djk.push({-dist - next.second, next.first});
	}
}
If (djk.size()) cout << -djk.top().first << endl;
else cout << “no solution” << endl;
}

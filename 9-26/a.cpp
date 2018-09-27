#include <bits/stdc++.h>

using namespace std;

int ct, m;

void dfs(int i, bool visited[], vector<vector<int>> &l) {
    visited[i] = true;
    for(int j=0;j<l[i].size();j++) {
        if(!visited[l[i][j]])
            dfs(l[i][j], visited, l);
    }
}

void findConnected(vector<vector<int>> &l) {
    bool visited[m];
    memset(visited, false, sizeof(visited));
    
    for(int i=0;i<m;i++)
    {
        if(!visited[i]) {
            dfs(i, visited, l);
            ct += 1;
        }
    }
}

int main(){
    int n;
    cin >> n;
    while(n--) {
        int r;
        cin >> m >> r;
        vector<vector<int>> l(m);
        for(int i=0;i<r;i++) {
            int x, y;
            cin >> x>> y;
            l[x].push_back(y);
            l[y].push_back(x);
        }
        
        ct = 0;
        findConnected(l);
        cout << ct - 1 << endl;
    }

    return 0;
}

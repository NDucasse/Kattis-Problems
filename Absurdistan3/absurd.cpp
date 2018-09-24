#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    unordered_map<int, int> roads;
    vector<pair<int, int>> other;
    for(int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        if(roads.find(a) == roads.end()) {
            roads[a] = b;
        } else if(roads.find(b) == roads.end()) {
            roads[b] = a;
        } else {
            if(find(other.begin(), other.end(), make_pair(a, b)) == other.end()) {
                other.push_back(make_pair(a, b));
            } else {
                other.push_back(make_pair(b, a));
            }
        } /*else {
            int originnode = a;
            int currnode = a;
            stack<int> prev;
            do {
                if(roads.find(roads[currnode]) == roads.end()) {
                    roads[roads[currnode]] = roads[currnode];
                    while(!prev.empty()) {
                        int tmp = prev.top();
                        prev.pop();
                        roads[tmp] = currnode;
                        currnode = tmp;
                    }
                    roads[originnode] = currnode;
                    break;
                } else {
                    prev.push(currnode);
                    currnode = roads[currnode];
                }
            }while(currnode != originnode);
        }*/
        
    }
    for(auto x : roads) {
        cout << x.first << " " << x.second << endl;
    }
    for(auto x : other) {
        cout << x.first << " " << x.second << endl;
    }
}

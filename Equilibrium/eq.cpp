#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ll n = 0;
    cin >> n;
    while(n--) {
        string s;
        cin >> s;
        ll count = 0;
        map<ll, ll> categories;
        for(ll i = 0; i < s.length(); i++) {
            string tempint = "";
            ll num = 0;
            if(s[i] == '[') {
                count++;
            } else if(s[i] == ']') {
                count--;
            } else if(s[i] != ',' && s[i+1] != '[') {
                while(i < s.length() && s[i] != ',' && s[i] != ']') {
                    tempint += s[i];
                    i++;
                }
                
                num = atoll(tempint.c_str()) << count;
                if(categories.find(num) == categories.end()) {
                    categories[num] = 1;
                } else {
                    categories[num] += 1;
                }
                if(s[i] == ']') {
                    count -= 1;
                }
            }
        }
        ll value = 0;
        vector<ll> cats;
        for(auto x:categories) {
            value += x.second;
            cats.push_back(x.second);
        }
        value -= *max_element(cats.begin(), cats.end());
        cout << value << endl;
    }
}

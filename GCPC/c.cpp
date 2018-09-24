#include <bits/stdc++.h>

using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template<class TI>
using indexed_set = tree<TI, null_type, less<TI>, rb_tree_tag, tree_order_statistics_node_update>;

struct teamrank {
    int solved, time, teamnum;
    bool operator<(const teamrank* rhs) {
        return lessthan(rhs);
    }
    bool lessthan(const teamrank* rhs) {
        if(this->solved != rhs->solved) {
            return(this->solved > rhs->solved);
        } else {
            return(this->time < rhs->time);
        }
    }
    bool operator==(const teamrank* rhs) {
        return this->teamnum == rhs->teamnum;
    }
    bool operator==(const int rhs) {
        return this->teamnum == rhs;
    }
};
/*
bool operator<(const teamrank* lhs, const teamrank* rhs) {
    if(lhs->solved != rhs->solved) {
        return(lhs->solved > rhs->solved);
    } else {
        return(rhs->time < rhs->time);
    }
}
bool operator==(const teamrank* lhs, const int rhs) {
    return lhs->teamnum == rhs;
}
bool operator==(const int lhs, const teamrank* rhs) {
    return lhs == rhs->teamnum;
}*/


int main() {
    int m, n, t, p;
    cin >> n >> m;
    indexed_set<teamrank*> ranklist;
    for(int i = 1; i <= n; i++) {
        teamrank* temp = new teamrank();
        temp->teamnum = i;
        temp->solved = 0;
        temp->time = 0;
        ranklist.insert(temp);
        delete temp;
    }
    for(int i = 0; i < m; i++) {
        cin >> t >> p;
        teamrank* y = new teamrank();
        y->teamnum = t;
        teamrank* x = new teamrank();
        x = *(ranklist.find(y));
        teamrank* temp = new teamrank();
        temp->teamnum = (*x).teamnum;
        cout << "fuck" << endl;
        temp->solved = (*x).solved + 1;
        temp->time = (*x).solved + p;
        ranklist.erase(y);
        ranklist.insert(temp);
        int j = 0;
        for(auto l : ranklist) {
            cout << l->teamnum << endl;
            j++;
        }
        
        y->teamnum = 1;
        auto z = ranklist.find(y);
        //cout << ranklist.order_of_key(*z) << endl;
    }
    
}

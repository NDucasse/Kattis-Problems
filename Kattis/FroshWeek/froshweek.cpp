#include <iostream>
#include <vector>
//#include <fstream>

using namespace std;
void merge(vector<int> &ids, int l, int m, int r, long long &val);
void mergesort(vector<int> &ids, int l, int r, long long &val);

int main() {
    int nums, num;
    //ifstream fin;
    //fin.open("test.txt");
    cin >> nums;
    vector<int> ids;
    for(int i = 0; i < nums; i++) {
        cin >> num;
        ids.push_back(num);
    }
    long long val = 0;
    mergesort(ids, 0, ids.size()-1, val);
    cout << val << endl;
    //fin.close();
    
}

void mergesort(vector<int> &ids, int l, int r, long long &val) {
    int m;
    if(l < r) {
        m = (l+r)/2;
        mergesort(ids, l, m, val);
        mergesort(ids, m+1, r, val);
        merge(ids, l, m, r, val);
    }
}

void merge(vector<int> &ids, int l, int m, int r, long long &val) {
    int n1 = m - l + 1;
    int n2 = r - m;
    int fR = 0;
    
    vector<int> L, R;
    for(int i = 0; i < n1; i++) {
        L.push_back(ids[l+i]);
    }
    for(int i = 0; i < n2; i++) {
        R.push_back(ids[m + 1 + i]);
    }
    
    int i = 0, j = 0, k = l;
    while(i < n1 && j < n2) {
        if(L[i] <= R[j]) {
            val += fR;
            ids[k] = L[i];
            i++;
        } else {
            ids[k] = R[j];
            j++;
            fR++;
        }
        k++;
    }
    
    while(i < n1) {
        val += fR;
        ids[k] = L[i];
        i++;
        k++;
    }
    
    while(j < n2) {
        fR++;
        ids[k] = R[j];
        j++;
        k++;
    }
    
}

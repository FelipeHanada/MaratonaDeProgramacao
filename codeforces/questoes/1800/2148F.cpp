#include <bits/stdc++.h>
using namespace std;


bool cmp(const vector<int>& a, const vector<int>& b, int j) {
    for (int i=j; i<min(a.size(), b.size()); i++) {
        if (a[i] < b[i]) return true;
        else if (a[i] > b[i]) return false;
    }
    if (a.size() < b.size()) return true;
    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;
    
        vector<vector<int>> a(n);
        int m, x;
        for (int i=0; i<n; i++) {
            cin >> m;
            for (int j=0; j<m; j++) {
                cin >> x;
                a[i].push_back(x);
            }
        }

        set<int> active;
        for (int i=0; i<n; i++) active.insert(i);
        int curr=0;
        while (!active.empty()) {
            int minimal = *active.begin();
            for (int j : active) if (a[j].size() > curr) {
                if (cmp(a[j], a[minimal], curr)) {
                    minimal = j;
                }
            }
            
            for (; curr<a[minimal].size(); curr++) {
                cout << a[minimal][curr] << ' ';
            }

            set<int> new_active;
            for (int j : active) if (a[j].size() >= curr + 1) {
                new_active.insert(j);
            }
            swap(active, new_active);
        }
        cout << '\n';
    }
}

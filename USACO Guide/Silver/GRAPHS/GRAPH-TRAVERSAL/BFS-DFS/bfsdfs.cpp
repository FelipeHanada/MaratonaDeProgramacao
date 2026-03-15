#include <bits/stdc++.h>
using namespace std;


bool ok;
vector<pair<int, int>> edges;

void solve(vector<int> a, vector<int> b) {
    int j = 1;
    vector<vector<int>> bs;
    vector<set<int>> bsset;
    for (int i=1; i<a.size() && j < a.size();) {
        vector<int> currb;
        set<int> currbsset;
        
        if(a[i] != b[j]) {
            ok = 0;
            return;
        }

        edges.push_back({a[0], a[i]});
        currb.push_back(b[j]);
        currbsset.insert(b[j]);
        i++; j++;
        while (i < a.size() && j < a.size() && a[i] != b[j]) {
            currb.push_back(b[j]);
            currbsset.insert(b[j]);
            j++;
        }
        
        bs.push_back(currb);
        bsset.push_back(currbsset);
    }
    
    vector<vector<int>> as(bs.size());
    
    for (int x : a) {
        for (int i=0; i<bs.size(); i++) {
            if (bsset[i].count(x)) {
                as[i].push_back(x);
                break;
            }
        }
    }
    
    for (int i=0; i<as.size(); i++) {
        solve(as[i], bs[i]);
        if (!ok) return;
    }
}

int main() {
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for (int i=0; i<n; i++) {
        cin >> a[i];
        a[i]--;
    }
    for (int i=0; i<n; i++) {
        cin >> b[i];
        b[i]--;
    }
    
    ok = 1;
    solve(a, b);
   
    
    if (!ok) {
        cout << "-1\n";
    } else {
        cout << edges.size() << '\n';
        for (auto [x, y] : edges) {
            cout << x + 1 << ' ' << y + 1 << '\n';
        }
    }
}
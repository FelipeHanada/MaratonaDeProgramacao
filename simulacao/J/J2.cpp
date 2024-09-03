#include <bits/stdc++.h>
using namespace std;


vector<int>::iterator f(int a, int b, vector<int> v[]) {
    int l = min(a, b); int h = (a + b) - l;

    return v[l].begin() + (h - l);
}

int main() {
    int n; cin >> n;

    vector<pair<int, int>> ans(n, make_pair(-1, INT32_MAX));
    vector<int> fw[n];
    for (int i=0; i<n; i++) fw[i].assign(n - i, INT32_MAX);
    vector<vector<int>> adj(n);
    for (int i=0; i<n-1; i++) {
        adj[i].push_back(i);

        int a, b; cin >> a >> b; a--; b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
        
        *f(a, b, fw) = 1;

        int l = min(a, b), h = max(a, b);
        if (ans[l].second > 1 || (ans[l].second == 1 && ans[l].first > h)) {
            ans[l] = {h, 1};
        }
    }


    for (int i=0; i<n; i++) {
        // vector i is the intermediate
        for (int a=0; a<n-1; a++) {
            for (int b=a+1; b<n; b++) {
                int distai = *f(a, i, fw);
                int distbi = *f(b, i, fw);
                if (distai == INT32_MAX || distbi == INT32_MAX) continue;
                int dist = distai + distbi;
                
                *f(a, b, fw) = min(*f(a, b, fw), dist);
                if (ans[a].second > dist || (ans[a].second == dist && ans[a].first > b)) {
                    ans[a] = {b, dist};
                }
            }
        }
    }

    for (int i=0; i<n; i++) {
        cout << ((ans[i].first == -1) ? i + 1 : ans[i].first + 1) << " ";
    }
    cout << endl;
}
#include <bits/stdc++.h>
using namespace std;


int main() {
    int n;
    cin >> n;
    bool ok = true;
    vector<int> in(n);
    vector<bool> seen(n+1, false);
    for (int i=0; i<n; i++) {
        cin >> in[i];
        if (in[i] != -1) {
            if (seen[in[i]]) ok = false;
            seen[in[i]] = true;
        }
    }

    if (!ok) {
        cout << "No\n";
    } else {
        cout << "Yes\n";

        set<int> not_seen;
        for (int i=1; i<=n; i++) {
            if (!seen[i]) not_seen.insert(i);
        }

        auto it = not_seen.begin();
        for (int i=0; i<n; i++) {
            if (in[i] != -1) {
                cout << in[i] << ' ';
            } else {
                cout << *it << ' ';
                it++;
            }
        }
        cout << '\n';
    }
}

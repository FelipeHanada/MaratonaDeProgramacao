#include <bits/stdc++.h>
using namespace std;


constexpr int MAX_N = 1000;
int n, a;
int p[MAX_N+1];
bool seen[MAX_N+1];
int ans[MAX_N+1];

int succ(int x) { // x is 1 indexed
    return p[x];
}


int main() {
    cin >> n;

    // for all students in the cycle -> the answer is itself
    // else the answer is the first student in the cycle
    for (int i=1; i<=n; i++) {
        cin >> p[i];
    }

    fill_n(seen, n+1, false);
    fill_n(ans, n+1, -1);
    for (int i=1; i<=n; i++) {
        if (seen[i]) continue;
        seen[i] = true;
        int t = succ(i), h = succ(t);
        while (t != h) {
            seen[t] = true;
            t = succ(t);
            h = succ(succ(h));
        }

        ans[t] = t; seen[t] = true;
        while ((t = succ(t)) != h) {
            seen[t] = true;
            ans[t] = t;
        }
    }

    for (int i=1; i<=n; i++) {
        if (ans[i] > 0) {
            cout << ans[i] << ' ';
            continue;
        }
        
        vector<int> path = {i};
        int t = succ(i);
        while (ans[t] < 0) {
            path.push_back(t);
            t = succ(t);
        }

        for (int x : path) {
            ans[x] = ans[t];
        }

        cout << ans[i] << ' ';
    }
    cout << '\n';
}

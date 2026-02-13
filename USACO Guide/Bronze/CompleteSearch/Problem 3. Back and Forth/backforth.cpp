#include <bits/stdc++.h>
using namespace std;

vector<int> a(10), b(10);
set<int> solutions;
void solve(int depth = 0, int x = 1000) {
    if (depth == 4) {
        solutions.insert(x);
        return;
    }

    if (depth % 2 == 0) {
        for (int i=0; i<a.size(); i++) {
            b.push_back(a[i]);
            a.erase(a.begin() + i);
            solve(depth + 1, x - b.back());
            a.insert(a.begin() + i, b.back());
            b.pop_back();
        }
    } else {
        for (int i=0; i<b.size(); i++) {
            a.push_back(b[i]);
            b.erase(b.begin() + i);
            solve(depth + 1, x + a.back());
            b.insert(b.begin() + i, a.back());
            a.pop_back();
        }
    }
}

int main() {
    freopen("backforth.in", "r", stdin);
    freopen("backforth.out", "w", stdout);

    for (int i=0; i<10; i++) {
        cin >> a[i];
    }

    for (int i=0; i<10; i++) {
        cin >> b[i];
    }

    solve();
    cout << solutions.size() << '\n';
}

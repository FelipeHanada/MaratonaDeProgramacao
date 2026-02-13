#include <bits/stdc++.h>
using namespace std;


int n;
string s;
int x;

bool check() {
    deque<char> dq;
    char last = '0';
    for (int i=0; i<n; i++) {
        if (x & (1 << i)) {
            if (last == '1' && s[i] == '0') return false;
            last = s[i];
            continue;
        }
        dq.push_back(s[i]);
    }
    while (dq.size() > 0) {
        if (dq.front() != dq.back()) return false;
        dq.pop_front();
        if (dq.size()) dq.pop_back();
    }
    return true;
}

void solve() {
    cin >> n;
    cin >> s;
    for (x=0; x<(1<<n); x++) {
        if (check()) {
            cout << __builtin_popcount(x) << '\n';
            for (int i=0; i<n; i++) {
                if (x & (1 << i)) cout << 1 + i << ' ';
            }
            cout << '\n';
            return;
        }
    }
    
    cout << "-1\n";
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}

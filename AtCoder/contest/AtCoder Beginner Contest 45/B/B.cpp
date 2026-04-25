#include <bits/stdc++.h>
using namespace std;

#define _ ios::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);
using ll = long long;


int main() { _
    int n, m;
    cin >> n >> m;
    set<int> s;
    bool ans1 = 1, ans2 = 0;
    for (int i=0; i<n; i++) {
        int f;
        cin >> f;
        if (s.count(f)) ans1 = 0;
        s.insert(f);
    }

    ans2 = m == s.size();

    cout << (ans1 ? "Yes" : "No") << '\n';
    cout << (ans2 ? "Yes" : "No") << '\n';
}

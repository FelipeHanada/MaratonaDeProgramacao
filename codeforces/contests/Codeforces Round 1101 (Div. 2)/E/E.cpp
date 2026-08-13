#include <bits/stdc++.h>
using namespace std;
#define _ ios::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);


int n;
vector<int> a;
vector<array<int,3>> ans;
inline void move(int id, int from, int to) {
    ans.push_back({ id, from, to });
}
void solve(int id, int src, int aux, int dest) {
    if (id < 0) return;

    if (id == a[id]) {
        move(id, src, dest);
        solve(id - 1, src, aux, dest);
        return;
    }
    
    if (a[id] == 0) {
        solve(id - 1, src, dest, aux);
        move(id, src, dest);
        solve(id - 1, aux, src, dest);
    } else {
        solve(id - 1 - a[id], src, dest, aux);
        move(id, src, dest);
        solve(id - 1 - a[id], aux, dest, src);
        solve(id - 1, src, aux, dest);
    }
}

/*
let f(k) be the number of moves that this algorithm yields for a tower of size k
    we need to prove that f(n) <= 2^n
    but lets prove f(n) <= 2^n - 1 instead

f(1) = 1 (<= 2^1 - 1)
f(k) = 2f(k-1) + 1                      if a[k] = 0 
       2f(k-1-x) + f(k-1) + 1           if a[k] = x > 0 

knowing that f(k-1) <= 2^(k-1)-1
    (1) 2f(k-1) + 1 <= 2*(2^(k-1) + 1) + 1 = 2^k - 1
    (2) 2f(k-1-x) + f(k-1) + 1 <= 2*(2^(k-1-x) - 1) + 2^(k-1) - 1 + 1
            = 2^(k-x) - 1 + 2^(k-1)
            since x > 0, 2^(k-x) < 2^(k-1)
            then 2^(k-x) - 1 + 2^(k-1) < 2^k - 1

therefore f(n) <= 2^n-1 < 2^n
    the algorithm passes.
*/


int main() { _
    int tt;
    cin >> tt;
    while (tt--) {
        cin >> n;
        bool ok = 1;
        a.resize(n);
        for (int i=0; i<n; i++) {
            cin >> a[i];
            if (a[i] > i) ok = 0;
        }

        if (!ok) {
            cout << "NO\n";
            continue;
        }

        ans.clear();
        solve(n-1, 1, 2, 3);

        cout << "YES\n";
        cout << ans.size() << '\n';
        for (auto [ id, from, to ] : ans) {
            cout << id + 1 << ' ' << from << ' ' << to << '\n';
        }
    }
}
#include <bits/stdc++.h>
using namespace std;


int n, m;
constexpr int MAX_N = 1e5;
int students[MAX_N];
map<int, int> curr;

bool satisfy() {
    // checks if the students on curr satisfy all proficiencies
    if (curr.size() < 1) return false;
    int lb = curr.begin()->first;
    int ub = curr.rbegin()->first;

    bool check;
    for (int i=2; i<=m; i++) {
        // checks if some multiple of i between lb and ub is in curr
        check = false;
        for (int k=(lb+i-1)/i*i; k<=ub; k+=i) {
            if (curr.find(k) != curr.end()) {
                check = true;
                break;
            }
        }

        if (!check) return false;
    }
    return true;
}

void solve() {
    cin >> n >> m;
    for (int i=0; i<n; i++)
        cin >> students[i];
    sort(students, students + n);

    curr.clear();
    int i=0, j=0;
    bool satisfied;
    int ans = INT32_MAX;
    while (i < n) {
        satisfied = satisfy();
        if (j<n && !satisfied) {
            curr[students[j]]++;
            j++;
        } else {
            if (satisfied) {
                ans = min(ans, curr.rbegin()->first - curr.begin()->first);
            }
            if (--curr[students[i]] == 0) {
                curr.erase(students[i]);
            }
            i++;
        }
    }

    cout << ((ans == INT32_MAX) ? -1 : ans) << '\n';
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    for (int i=0; i<t; i++) solve();
}

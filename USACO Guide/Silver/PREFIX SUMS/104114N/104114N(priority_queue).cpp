#include <bits/stdc++.h>
using namespace std;


constexpr int MAX_N = 100000;
int salt[MAX_N];
bool cmp(const int& a, const int& b) {
    return salt[a] < salt[b] || (salt[a] == salt[b] && a < b);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    set<int, bool (*)(const int&, const int&)> pq(cmp);
    for (int i=0; i<n; i++) {
        cin >> salt[i];
        pq.emplace(i);
    }

    while (!pq.empty()) {
        auto to_fix = --pq.end();

        if (*to_fix > 0) {
            if (salt[*to_fix - 1] < salt[*to_fix] - m) {
                pq.erase(*to_fix - 1);
                salt[*to_fix - 1] = salt[*to_fix] - m;
                pq.insert(*to_fix - 1);
            }
        }

        if (*to_fix < n-1) {
            if (salt[*to_fix + 1] < salt[*to_fix] - m) {
                pq.erase(*to_fix + 1);
                salt[*to_fix + 1] = salt[*to_fix] - m;
                pq.insert(*to_fix + 1);
            }
        }

        pq.erase(to_fix);
    }

    for (int i=0; i<n; i++) {
        cout << salt[i] << ' ';
    }
    cout << '\n';
}
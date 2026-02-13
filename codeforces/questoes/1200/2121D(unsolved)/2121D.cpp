#include <bits/stdc++.h>
using namespace std;


void solve() {
    int n;
    cin >> n;

    vector<int> a(n), b(n);
    map<int, deque<int>> pos_a;
    map<int, deque<int>> pos_b;
    for (int i=0; i<n; i++) {
        cin >> a[i];
        pos_a[a[i]].push_back(i);
    }

    for (int i=0; i<n; i++) {
        cin >> b[i];
        pos_b[b[i]].push_back(i);
    }

    while (pos_a.rbegin()->first > pos_b.begin()->first) {
        auto &[x, i] = *pos_a.rbegin();
        auto &[y, j] = *pos_b.begin();
        cout << "1 1 " << i.front()+1 << '\n';
        cout << "1 1 " << j.front()+1 << '\n';
        cout << "3 1\n";
        pos_a[y].push_back(0);
        pos_b[x].push_back(0);
        pos_a[a[0]]
        swap(a[0], a[i.front()]);
        swap(b[0], b[j.front()]);
        swap(a[0], b[0]);
        i.pop_front();
        j.pop_front();
        if (i.empty()) pos_a.erase(x);
        if (j.empty()) pos_b.erase(y);
    }

}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}
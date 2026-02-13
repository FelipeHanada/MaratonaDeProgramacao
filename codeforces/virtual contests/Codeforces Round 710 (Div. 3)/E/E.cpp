#include <bits/stdc++.h>
using namespace std;


void solve() {
    int n;
    cin >> n;
    deque<int> a(n);
    unordered_set<int> used;
    for (int i=0; i<n; i++) {
        cin >> a[i];
        used.insert(a[i]);
    }

    int curr = 1;
    cout << a[0] << ' ';
    for (int i=1; i<n; i++) {
        if (a[i] > a[i-1]) {
            cout << a[i] << ' ';
        } else {
            while (used.count(curr)) curr++;
            cout << curr << ' ';
            curr++;
        }
    }
    cout << '\n';

    priority_queue<int> pq;
    int last = 0;
    for (int i=last+1; i<a[0]; i++) if (!used.count(i)) pq.push(i);
    cout << a[0] << ' ';
    last = a[0];
    for (int i=1; i<n; i++) {
        if (a[i] > a[i-1]) {
            cout << a[i] << ' ';
            for (int j=last+1; j<a[i]; j++) if (!used.count(j)) pq.push(j);
            last = a[i];
        } else {
            cout << pq.top() << ' ';
            pq.pop();
        }
    }
    cout << '\n';
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}
#include <bits/stdc++.h>
using namespace std;


int main() {
    int tt;
    cin >> tt;
    while (tt--) {
        int n, m;
        cin >> n >> m;
        priority_queue<int> a, b;
        int x;
        for (int i=0; i<n; i++) {
            cin >> x;
            a.push(x);
        }
        for (int i=0; i<m; i++) {
            cin >> x;
            b.push(x);
        }

        while (1) {
            if (a.top() >= b.top()) b.pop();
            else {
                b.push(b.top() - a.top());
                b.pop();
            }

            if (b.empty()) {
                cout << "Alice\n";
                break;
            }

            if (b.top() >= a.top()) a.pop();
            else {
                a.push(a.top() - b.top());
                a.pop();
            }

            if (a.empty()) {
                cout << "Bob\n";
                break;
            }
        }
    }
}
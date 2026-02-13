#include <bits/stdc++.h>
using namespace std;


int main() {
    int n;
    cin >> n;
    deque<int> a(n);
    for (int i=0; i<n; i++) {
        cin >> a[i];
    }

    stack<int> stk;
    for (int i=0; i<n; i++) {
        while (!stk.empty() && a[i] <= a[stk.top()])
            stk.pop();

        if (stk.empty()) {
            cout << "0 ";
        } else {
            cout << stk.top() + 1 << ' ';
        }

        stk.push(i);
    }
    cout << '\n';
}

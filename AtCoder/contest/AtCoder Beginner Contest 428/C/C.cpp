#include <bits/stdc++.h>
using namespace std;



int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int q;
    cin >> q;

    stack<char> stk;
    stack<char> hist;
    while (q--) {
        int op;
        cin >> op;
        if (op == 1) {
            char c;
            cin >> c;
            if (!stk.empty() && stk.top() == '(' && c == ')') {
                hist.push(stk.top());
                stk.pop();
            } else {
                stk.push(c);
                hist.push(-1);
            }
        } else {
            if (hist.top() == -1) {
                stk.pop();
            } else {
                stk.push(hist.top());
            }
            hist.pop();
        }

        cout << (stk.empty() ? "Yes" : "No") << '\n';
    }
}
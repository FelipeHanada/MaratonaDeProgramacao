#include <bits/stdc++.h>
using namespace std;


int main() {
    int n;
    cin >> n;
    stack<int> stk;
    for (int i=0; i<n; i++) {
        int x;
        cin >> x;
        if (x) stk.push(x);
        else stk.pop();
    }

    int ans = 0;
    while (!stk.empty()) {
        ans += stk.top();
        stk.pop();
    }
    
    cout << ans << '\n';
}
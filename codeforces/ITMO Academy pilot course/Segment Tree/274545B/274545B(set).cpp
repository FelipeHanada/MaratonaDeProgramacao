#include <bits/stdc++.h>
using namespace std;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    cin >> n;

    stack<int> stk;
    deque<int> s(n);
    iota(s.begin(), s.end(), 0);
    int x;
    for (int i=0; i<n; i++) {
        cin >> x;
        stk.push(x);
    }

    stack<int> ans;
    while (!stk.empty()) {
        int curr = stk.top(); stk.pop();
        ans.push(*(s.rbegin() + curr));
        s.erase(s.begin()+s.size()-curr-1);
    }
    while (!ans.empty()) {
        cout << ans.top() + 1 << ' ';
        ans.pop();
    }
    cout << '\n';
}

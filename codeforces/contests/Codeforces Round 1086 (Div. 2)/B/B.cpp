#include <bits/stdc++.h>
using namespace std;

#define _ ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using ll = long long;


int main() { _ 
    int tt;
    cin >> tt;
    while (tt--) {
        int n, k, p, m;
        cin >> n >> k >> p >> m;
        deque<int> a(n);
        for (int i=0; i<n; i++) cin >> a[i];
    
        int cost_sp = a[p-1]; a[p-1] = -1;
        multiset<int> hand;
        queue<int> q;
        for (int i=0; i<n; i++) q.push(a[i]);
        for (int i=0; i<k; i++) {
            hand.insert(q.front());
            q.pop();
        }
    
        int ans = 0;
        while (m >= cost_sp) {
            if (*hand.begin() == -1) {
                m -= cost_sp;
                ans++;
                q.push(*hand.begin());
                hand.extract(hand.begin());
                hand.insert(q.front());
                q.pop();
            } else {
                m -= *hand.begin();
                q.push(*hand.begin());
                hand.extract(hand.begin());
                hand.insert(q.front());
                q.pop();
            }
        }
    
        cout << ans << '\n';
    }
}
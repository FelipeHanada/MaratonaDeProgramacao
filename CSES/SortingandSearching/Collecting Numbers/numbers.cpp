#include <bits/stdc++.h>
using namespace std;


int main() {
    int n;
    cin >> n;
    deque<int> a(n);
    for (int i=0; i<n; i++) {
        cin >> a[i];
    }

    int ans = 0;
    set<int> s;
    for (int i=0; i<n; i++) {
        if (!s.count(a[i] - 1)) ans++;
        s.insert(a[i]);
    }
    
    cout << ans << '\n';
}

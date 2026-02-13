#include <bits/stdc++.h>
using namespace std;

#define ll long long

void precompute() {

}


/*
5

0 0 0
1 0 0
1 1 0
1 1 3
1 3 3


1 -> 3
2 -> 5
3 -> 7

*/

void solve() {
    int x;
    cin >> x;
    multiset<int> ms;
    ms.insert(0);
    ms.insert(0);
    ms.insert(0);
    int ans = 0;
    while (ms.count(x) != 3) {
    	ms.extract(ms.begin());
    	int v = *ms.begin();
    	ms.insert(min(x, v*2+1));
    	ans++;
    }
    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    precompute();
    int tt;
    cin >> tt;
    while (tt--) solve();    
    return 0;
}

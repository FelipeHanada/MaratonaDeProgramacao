#include <bits/stdc++.h>
using namespace std;

#define ll long long

void precompute() {

}

void solve() {
    int a, b;
    cin >> a >> b;
    ll need_a, need_b;
    
    need_a = need_b = 0;

    ll p = 1;
    int i = 0;
    for (; need_a <= a && need_b <= b; i++) {
    	if (i % 2) {
    		need_a += p;
    	} else {
    		need_b += p;
    	}
    	p *= 2;
    }
    int ans = i - 1;
    
    need_a = need_b = 0;
    p = 1; i = 0;
    for (; need_a <= a && need_b <= b; i++) {
    	if (i % 2) {
    		need_b += p;
    	} else {
    		need_a += p;
    	}
    	p *= 2;
    }
    
    cout << max(ans, i - 1) << '\n';
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

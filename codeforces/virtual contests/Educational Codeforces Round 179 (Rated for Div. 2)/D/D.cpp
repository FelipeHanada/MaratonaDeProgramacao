#include <bits/stdc++.h>
using namespace std;

#define ll long long

void precompute() {

}

/*

we need to group the classes in 

we want to partitionate the classes in pairs with maximum difference
*/

void solve() {
    int n, m;
    cin >> n >> m;
    deque<array<int,2>> a(m);
    for (int i=0; i<m; i++) {
    	cin >> a[i][1];
    	a[i][0] = a[i][1] / 100;
    }
    sort(a.begin(), a.end());
    
    for (int i=0; i<n/2; i++) {
    	cout << a.front()[1] << ' ' << a.back()[1] << ' ' << a.front()[1] << ' ' << a.back()[1] << ' ' << a.front()[1] << ' ' << a.back()[1] << '\n';
    	cout << a.back()[1] << ' ' << a.front()[1] << ' ' << a.back()[1] << ' ' << a.front()[1] << ' ' << a.back()[1] << ' ' << a.front()[1] << '\n';
    	a.pop_front();
    	a.pop_back();
    }
    
    if (n % 2) {
    	cout << a.front()[1] << ' ' << a.back()[1] << ' ' << a.front()[1] << ' ' << a.back()[1] << ' ' << a.front()[1] << ' ' << a.back()[1] << '\n';
    }
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

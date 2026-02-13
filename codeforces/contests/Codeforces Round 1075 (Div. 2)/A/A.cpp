#include <bits/stdc++.h>
using namespace std;

#define ll long long

void precompute() {

}

void solve() {
   int n, h, l;
   cin >> n >> h >> l;

   if (h > l) swap(h, l);
   int a = 0, b = 0, c = 0;
   for (int i=0; i<n; i++) {
     int x;
     cin >> x;
     if (x > l) c++;
     else if (x > h) b++;
     else a++;
   }

   int ans = 0;
   ans += min(a, b);
   a -= ans;
   ans += a / 2;
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

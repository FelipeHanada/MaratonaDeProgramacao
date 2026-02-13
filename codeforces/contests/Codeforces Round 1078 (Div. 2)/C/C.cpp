#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pii pair<int, int>
#define _1 first
#define _2 second

void precompute() {
  
}

constexpr int MAX_N = 50000;
ll cnt[26][MAX_N];
void solve() {
  int n, k;
  cin >> n >> k;
  for (int i=0; i<26; i++) fill_n(cnt[i], n, 0);
  vector<string> a(k);
  for (int i=0; i<k; i++) {
    cin >> a[i];
    for (int j=0; j<n; j++) cnt[a[i][j]-'a'][j]++;
  }

  ll curr[26][n/2];
  for (int size=1; size <=n/2; size++) if (n % size == 0) {
    for (int i=0; i<26; i++) fill_n(curr[i], size, 0);

    for (int i=0; i<26; i++) {
      for (int j=0; j<size; j++)
        curr[i][j] = cnt[i][j];
    }
    
    for (int d=size; d+size<=n; d+=size) {
      for (int i=0; i<26; i++)
        for (int j=0; j<size; j++)
          curr[i][j] = min(curr[i][j], cnt[i][d + j]);
    }

    bool ok = 1;
    string ans;
    for (int j=0; ok && j<size; j++) {
      char c = 0;
      for (int i=0; !c && i<26; i++) {
        if (curr[i][j]) c = i + 'a';
      }

      ok = c;
      ans.push_back(c);
    }

    if (ok) {
      for (int i=0; i<n; i+=size) cout << ans;
      cout << '\n';
      return;
    }
  }

  cout << a[0] << '\n';
}

int main() {
#ifdef ONLINE_JUDGE
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
#endif
    
  precompute();
  int tt;
  cin >> tt;
  while (tt--) solve();
  return 0;
}

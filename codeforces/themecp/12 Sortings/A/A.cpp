#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pii pair<int, int>
#define _1 first
#define _2 second

void precompute() {
  
}

void solve() {
 string a, b;
 cin >> a >> b;

 if (a.size() != b.size()) {
   cout << "WRONG_ANSWER\n";
   return;
 }

 multiset<char> s;
 for (char c : a) s.insert(c);

 string ans;
 if (a.size() > 1) {
   ans.push_back(*(upper_bound(s.begin(), s.end(), '0')));
   s.extract(ans.back());

   for (int i=0; i<a.size()-1; i++) {
     ans.push_back(*s.begin());
     s.extract(*s.begin());
   }
 } else {
   ans = a;
 }

 for (int i=0; i<a.size(); i++) {
   if (ans[i] != b[i]) {
     cout << "WRONG_ANSWER\n";
     return;
   }
 }

 cout << "OK\n";
}

int main() {
#ifdef ONLINE_JUDGE
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
#endif
    
  precompute();
  solve();
  return 0;
}

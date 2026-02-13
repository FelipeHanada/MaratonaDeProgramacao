#include <bits/stdc++.h>
using namespace std;


int main() {
  int tt;
  cin >> tt;
  while (tt--) {
    int n;
    long long k;
    cin >> n >> k;

    k--;
    deque<int> dq;
    dq.push_back(n);
    for (int i=n-1; i>0; i--) {
      if (k & 1) {
        dq.push_back(i);
      } else {
        dq.push_front(i);
      }
      k >>= 1;
    }

    if (k) {
      cout << "-1\n";
      continue;
    }

    for (int x : dq) {
      cout << x << ' ';
    }
    cout << '\n';
  }
}

#include <bits/stdc++.h>
using namespace std;


int main() {
  int n;
  cin >> n;
  while (n) {
    stack<int> stk;
    int next = 1;
    for (int i=0; i<n; i++) {
      int x;
      cin >> x;
      while (!stk.empty() && stk.top() == next) {
        stk.pop();
        next++;
      }
      if (x == next) {
        next++;
        continue;
      }
      stk.push(x);
    }
    while (!stk.empty() && stk.top() == next) {
      stk.pop();
      next++;
    }

    cout << (stk.empty() ? "yes" : "no") << '\n';
    cin >> n;
  }
}

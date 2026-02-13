#include <bits/stdc++.h>
using namespace std;


struct MinStack {
  stack<pair<int, int>> stk;
  void push(int x) {
    if (stk.empty()) stk.push({x, x});
    else {
      stk.push({x, min(stk.top().second, x)});
    }
  }
  void pop() { stk.pop(); }
  int get_min() { return stk.top().second; }
};


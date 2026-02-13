#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pii pair<int, int>
#define _1 first
#define _2 second

void precompute() {
  
}

/*
7 11

0111 -> 0100 (*0110)
1011 -> 1011 (*1001)

011 -> 010
110 -> 101 => 1 + 1 = 2

100 -> 100
100 -> 000

001111011 -> 010000000
101000001 -> 101000001


7 11
0111 
1011

p = 0110
q = 1001

p = 01
q = 10
*/


void solve() {
  int x, y;
  cin >> x >> y;

  int p1 = x, p2 = x, q1 = 0, q2 = 0;
  int i=31;
  for (; i>=0; i--) if (!((x&(1<<i)) && (y&(1<<i)))) {
    q1 |= y&(1<<i);
    q2 |= y&(1<<i);
  }

  if (i >= 0) {
    // q1 is the bigger < y, q2 is the smallest > y
    q1 += 1<<(i+1);
    for (int j=0; j<i; j++) q2 |= 1<<j;
  }

  int b1 = ()
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

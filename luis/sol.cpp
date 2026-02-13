#include <bits/stdc++.h>
using namespace std;


/*
we are looking for the largest interval (i, j) such that
    sum[a[i..j]]/(j-i+1) <= k
    sum[a[i..j]] <= k * (j-i+1)
    sum[a[i..j] - k] <= 0

we need to get the longest subarray with sum -k*size <= 0
    that is equivalent to consider the problem with
        a new a[i]-k and a new k=0

let p be the prefix array for a
    an interval satisfy the constraint if
        p[j] - p[i] <= 0 --> p[j] <= p[i]

we do not need to consider any position i
    such that exists another i' < i such that p[i'] >= p[i]
    since for any interval (i, j) valid (i', j) is also valid and larger

its enough to build a monotonic crescent stack from left to right
    after that, we iterate from right to left
*/

using ll = long long;

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i=0; i<n; i++) {
        cin >> a[i];
        a[i] -= k;
    }
    vector<ll> p(n+1);
    p[0] = 0;
    for (int i=1; i<=n; i++) p[i] = p[i-1] + a[i-1];

    stack<int> stk;
    for (int i=0; i<=n; i++) {
        if (stk.empty() || p[i] > p[stk.top()]) stk.push(i);
    }

    int ans = 0;
    for (int j=n; j>=0; j--) {
        while (!stk.empty() && p[stk.top()] >= p[j]) {
            ans = max(ans, j - stk.top());
            stk.pop();
        }
    }

    cout << ans << '\n';
}
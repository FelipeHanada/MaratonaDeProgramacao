#include <bits/stdc++.h>
using namespace std;


#define ll long long


int main() {
    int n;
    cin >> n;
    deque<int> a(n);
    for (int i=0; i<n; i++) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());

    ll curr = 0;
    for (int i=0; i<n; i++) {
        if (a[i] <= curr + 1) {
            curr += a[i];
        }
    }

    cout << curr + 1 << '\n';
}

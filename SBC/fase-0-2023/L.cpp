#include <bits/stdc++.h>
using namespace std;


using ll = long long;

int main(){
    int n, m;
    cin >> n >> m;

    int s;
    cin >> s;

    ll ac = 0;
    for (int i=0; i<s; i++) {
        int x, y, r;
        cin >> x >> y >> r;

        int top = max(1, y - r),
            bottom = min(m, y + r),
            left = max(1, x - r),
            right = min(n, x + r);

        ac += (bottom - top + 1) * (right - left + 1);
    }

    cout << ac / (m * n) << '\n';
}
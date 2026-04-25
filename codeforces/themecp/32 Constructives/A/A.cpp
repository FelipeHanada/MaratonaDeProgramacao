#include <bits/stdc++.h>
using namespace std;

#define _ ios::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);
using ll = long long;


int main() {
    int tt;
    cin >> tt;
    while (tt--) {
        int n; ll k;
        cin >> n >> k;

        vector<int> a(n);
        iota(a.begin(), a.end(), 1);
        ll i=0, j=n-1;
        while (i < j && k) {
            while (i < j && 2 * (j - i) > k) j--;

            if (2 * (j - i) <= k) {
                swap(a[i], a[j]);
                k -= 2 * (j - i);
                i++;
                j--;
            } else {
                break;
            }
        }

        if (k) {
            cout << "No\n";
        } else {
            cout << "Yes\n";
            for (int x : a) {
                cout << x << ' ';
            }
            cout << '\n';
        }
    }
}

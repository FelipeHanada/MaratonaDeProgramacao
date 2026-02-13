#include <bits/stdc++.h>
using namespace std;


using ll = long long;

int main() {
#ifdef ONLINE_JUDGE
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
#endif
    int tt;
    cin >> tt;
    while (tt--) {
        int n, k;
        cin >> n >> k;
        string s;
        for (int i=0; i<n-2; i++) s.push_back('a');
        s.push_back('b'); s.push_back('b');
        k--;
        int l = n-2, r = n-1;

        while (k >= n-l-1) {
            k -= n-l-1;
            swap(s[l], s[l-1]);
            l--;
        }
        swap(s[r], s[r-k]);

        cout << s << '\n';
    }
}
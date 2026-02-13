#include <bits/stdc++.h>
using namespace std;


#define ll long long

void solve() {
    int n;
    cin >> n;
    vector<char> s(n);
    ll count[2] = {0, 0};
    int block0 = 0, block1 = 0;
    char curr = '2'; int curr_size = 0;
    for (int i=0; i<n; i++) {
        cin >> s[i];
        count[s[i]-'0']++;
        if (s[i] == curr) {
            curr_size++;
        } else {
            if (curr == '0' && curr_size > block0) {
                block0 = curr_size;
            } else if (curr == '1' && curr_size > block1) {
                block1 = curr_size;
            }

            curr_size = 1;
        }
        curr = s[i];
    }
    if (curr == '0' && curr_size > block0) {
        block0 = curr_size;
    } else if (curr == '1' && curr_size > block1) {
        block1 = curr_size;
    }

    ll ans0 = 2*count[0] + count[1] - 2*block0;
    ll ans1 = count[0] + 2*count[1] - 2*block1;

    cout << min(ans0, ans1) << '\n';
}


int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}
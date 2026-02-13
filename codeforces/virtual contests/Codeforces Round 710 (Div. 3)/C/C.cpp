#include <bits/stdc++.h>
using namespace std;


void solve() {
    string a, b;
    cin >> a >> b;

    int ans = a.size() + b.size();
    for (int i=0; i<a.size(); i++) {
        for (int j=i+1; j<=a.size(); j++) {
            int size = j - i;
            for (int k=0; k+size<=b.size(); k++) {
                string a2(a.begin()+i, a.begin()+j);
                string b2(b.begin()+k, b.begin()+k+size);
                if (a2 == b2) {
                    ans = min(ans, (int)(a.size() + b.size() - 2*size));
                }
            }

        }
    }

    cout << ans << '\n';
}

int main() {
    int t;
    cin >>t;
    while (t--){
        solve();
    }
}
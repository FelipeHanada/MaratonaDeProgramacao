#include <bits/stdc++.h>
using namespace std;


int main() {
    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        int x; cin >> x;

        vector<int> factors;
        for (int i = 2; i * i <= x; i++) {
            int a = 0;
            while (x % i == 0) {
                a++;
                x /= i;
            }
            factors.push_back(a);
        }
        if (x > 1) {
            factors.push_back(1);
        }

        int ans = 1;
        for (auto f : factors) {
            ans *= f + 1;
        }

        cout << ans << endl;
    }
}

#include <bits/stdc++.h>
using namespace std;


int main() {
    int n;
    cin >> n;

    int sum = 0;
    vector<int> v(n);
    for (int i=0; i<n; i++) {
        cin >> v[i];
        sum += v[i];
    }
    vector<int> dp(10001, -2);
    dp[0] = -1;
    // dp[i] = o indice do último elmento adicionado à um subset que soma i
    // dp[0] = -1 (não tem último elemento, mas é possível de se fazer)
    // dp[i] = -2 (não tem como fazer)

    for (int i=0; i<n; i++) {
        for (int j=10000; j>=v[i]; j--) {
            if (dp[j-v[i]] == -2 || dp[j] != -2) continue;
            dp[j] = i;
        }
    }

    if (sum % 2 || dp[sum/2] == -2) {
        cout << "-1\n";
        return 0;
    }

    int curr = sum / 2;
    vector<int> a, b;
    for (int i=n-1; i>=0; i--) {
        if (dp[curr] == i) {
            curr -= v[i];
            a.push_back(v[i]);
        } else {
            b.push_back(v[i]);
        }
    }

    int sumA=0, sumB=0;
    auto i = a.begin(), j = b.begin();
    while (i != a.end() && j != b.end()) {
        while (i != a.end() && sumA <= sumB) {
            sumA += *i;
            cout << *(i++) << ' ';
        }

        while (j != b.end() && sumB < sumA) {
            sumB += *j;
            cout << *(j++) << ' ';
        }
    }
    while (i != a.end()) {
        cout << *(i++) << ' ';
    }
    while (j != b.end()) {
        cout << *(j++) << ' ';
    }
    cout << '\n';
}

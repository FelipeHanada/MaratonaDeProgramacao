#include <bits/stdc++.h>
using namespace std;


int k;
vector<int> v;
bool check(int d) {
    int sum = 0, lines = 1;

    for (int x : v) {
        sum += x;

        if (sum > d) {
            sum = x;
            lines++;

            if (lines > k)
                return false;
        }
    }

    return true;
}


int main() {
    cin >> k;

    char c;
    v = {0};    
    getchar();
    while ((c = getchar()) != '\n') {
        v.back()++;
        if (c == ' ' || c == '-')
            v.push_back(0);
    }

    if (v.size() <= k) {
        int ans = 0;
        for (int x : v) {
            ans = max(ans, x);
        }
        cout << ans << '\n';
        return 0;
    }

    int l = 1, r = 1e6;
    while (l < r) {
        int mid = (l + r) / 2;

        if (check(mid)) {
            r = mid;
        } else {
            l = mid + 1;
        }
    }

    cout << l << '\n';
}
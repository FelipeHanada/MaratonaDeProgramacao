#include <bits/stdc++.h>
using namespace std;


bool query(int i) {
    cout << "? " << i << '\n';
    fflush(stdout);
    string ans;
    cin >> ans;
    return ans == "YES";
}

int main() {
    int l = 0, r = int(1e9);
    while (r - l > 1) {
        int mid = (l + r) / 2;
        if (query(mid)) {
            l = mid;
        } else {
            r = mid;
        }
    }

    cout << "! " << r << '\n';
}
#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    ll n;
    cin >> n;

    if ((n * (n+1)) % 4 > 0) {
        cout << "NO\n";
        return 0;
    }

    ll half = n * (n+1) / 4;
    vector<int> v;
    for (int i=n; half > 0; i--) {
        if (half < i) {
            v.push_back(half);
            half = 0;
            break;
        }

        half -= i;
        v.push_back(i);
    }

    cout << "YES\n";
    cout << v.size() << "\n";
    for (int x : v)
        cout << x << " ";
    cout << "\n";
    cout << n - v.size() << "\n";
    auto it = v.begin();
    for (int i=n; i>0; i--) {
        if (it != v.end() && *it == i) {
            it++;
            continue;
        }
        cout << i << " ";
    }
    cout << "\n";
}
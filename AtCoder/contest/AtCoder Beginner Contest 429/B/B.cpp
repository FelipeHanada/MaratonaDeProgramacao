#include <bits/stdc++.h>
using namespace std;


int main() {
    int n, m;
    cin >> n >> m;
    int sum = 0;
    set<int> s;
    int a;
    for (int i=0; i<n; i++) {
        cin >> a;
        sum += a;
        s.insert(a);
    }

    if (s.count(sum - m)) {
        cout << "Yes\n";
    } else {
        cout << "No\n";
    }
}

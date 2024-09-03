#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    set<int> s;

    cin >> n;
    int k;
    for (int i=0; i<n; i++) {
        cin >> k;
        s.insert(k);
    }

    cout << s.size() << endl;
}
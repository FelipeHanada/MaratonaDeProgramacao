#include <bits/stdc++.h>
using namespace std;


using ll = long long;


int query(int i, int j) {
    cout << "? " << i+1 << ' ' << j+1 << '\n';
    fflush(stdout);
    int k;
    cin >> k;
    return k;
}

int main() {
    int n;
    cin >> n;

    queue<int> pos;
    for (int i=0; i<n; i++) pos.push(i);

    vector<int> ans(n);
    while (pos.size() > 1) {
        int i = pos.front(); pos.pop();
        int j = pos.front(); pos.pop();

        int k1 = query(i, j);
        int k2 = query(j, i);

        if (k1 < k2) {
            ans[j] = k2;
            pos.push(i);
        } else {
            ans[i] = k1;
            pos.push(j);
        }
    }

    ans[pos.front()] = n;
    cout << "! ";
    for (int x : ans) cout << x << ' ';
    cout << '\n';
}

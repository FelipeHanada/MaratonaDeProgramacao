#include <bits/stdc++.h>
using namespace std;

#define _ ios::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);
#define _1 first
#define _2 second
using ll = long long;

int main() { _
    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    vector<pair<int,int>> ord(n);
    for (int i=0; i<n; i++) {
        cin >> a[i];
        ord[i] = { a[i], i };
    }
    sort(ord.begin(), ord.end());

    while (q--) {
        int k;
        cin >> k;
        vector<pair<int,int>> b(k);
        for (int i=0; i<k; i++) {
            cin >> b[i]._2; b[i]._2--;
            b[i]._1 = a[b[i]._2];
        }
        sort(b.begin(), b.end());

        int i = 0;
        for (auto p : b) {
            if (ord[i] == p) i++;
        }

        cout << ord[i]._1 << '\n';
    }
}

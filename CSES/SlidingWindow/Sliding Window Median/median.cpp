#include <bits/stdc++.h>
using namespace std;


int main() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i=0; i<n; i++) cin >> a[i];

    multiset<int> L, R;
    for (int i=0; i<k; i++) {
        L.insert(a[i]);
    }
    while (L.size() > (k+1)/2) {
        R.insert(*L.rbegin());
        L.extract(*L.rbegin());
    }
    cout << *L.rbegin() << ' ';


    for (int i=k; i<n; i++) {
        if (a[i] <= *L.rbegin()) L.insert(a[i]);
        else R.insert(a[i]);
        if (a[i-k] <= *L.rbegin()) L.extract(a[i-k]);
        else R.extract(a[i-k]);

        while (L.size() < (k+1)/2) {
            L.insert(*R.begin());
            R.extract(R.begin());
        }
        while (L.size() > (k+1)/2) {
            R.insert(*L.rbegin());
            L.extract(*L.rbegin());
        }

        cout << *L.rbegin() << ' ';
    }
    cout << '\n';
}
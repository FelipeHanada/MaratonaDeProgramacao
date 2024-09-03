#include <bits/stdc++.h>
using namespace std;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; cin >> n;

    set<int> s;
    int isolated_vertices = 0;
    for (int i=0; i<n; i++) {
        int k; cin >> k;
        
        if (i + 1 == k) {
            isolated_vertices++;
        } else {
            s.insert(k);
        }
    }

    cout << isolated_vertices + s.size()/2 << endl;
}
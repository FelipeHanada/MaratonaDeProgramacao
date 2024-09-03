#include <bits/stdc++.h>

using namespace std;


int n;

int main() {
    freopen("factory.in", "r", stdin);
    freopen("factory.out", "w", stdout);

    cin >> n;

    set<int> deg0_vertices = []() {
        set<int> tmp;
        for (int i=0; i<n; i++) tmp.insert(i);
        return tmp;
    }();

    int a, b;
    for (int i=0; i<n-1; i++) {
        cin >> a >> b; a--; b--;
        deg0_vertices.erase(a);
    }

    if (deg0_vertices.size() == 1) {
        cout << *deg0_vertices.begin() + 1 << endl;
    } else {
        cout << -1 << endl;
    }
}

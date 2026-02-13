#include <bits/stdc++.h>
using namespace std;


int main() {
    freopen("mixmilk.in", "r", stdin);
    freopen("mixmilk.out", "w", stdout);

    int c1, c2, c3;
    int m1, m2, m3;
    cin >> c1 >> m1 >> c2 >> m2 >> c3 >> m3;

    for (int i=0; i<33; i++) {
        m2 += m1;
        m1 = max(0, m2 - c2);
        m2 = min(m2, c2);

        m3 += m2;
        m2 = max(0, m3 - c3);
        m3 = min(m3, c3);

        m1 += m3;
        m3 = max(0, m1 - c1);
        m1 = min(m1, c1);
    }
    m2 += m1;
    m1 = max(0, m2 - c2);
    m2 = min(m2, c2);

    cout << m1 << '\n' << m2 << '\n' << m3 << '\n';
}
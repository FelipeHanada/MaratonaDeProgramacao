#include <bits/stdc++.h>

using namespace std;

int main() {
    freopen("pails.in", "r", stdin);
    freopen("pails.out", "w", stdout);

    int x, y, m;
    cin >> x >> y >> m;

    int max_y_pours = m / y;

    int max_m_fill = 0;
    for (int i=0; i<=max_y_pours; i++) {
        int m_fill = y * i;
        
        int max_x_pours = (m - m_fill) / x;
        m_fill += max_x_pours * x;
        max_m_fill = max(max_m_fill, m_fill);
    }

    cout << max_m_fill << endl;
}
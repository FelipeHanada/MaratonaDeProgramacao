#include <bits/stdc++.h>
using namespace std;


int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);

    int tt; cin >> tt;
    int test_id = 1;
    while (tt--) {
        cout << "Case " << test_id++ << ":\n";

        int q; cin >> q;
        vector<vector<int>> a(1005, vector<int>(1005, 0)),
                            prefix(1005, vector<int>(1005, 0));
        vector<pair<int, int>> s;
        
        int B = sqrt(q);
        int cnt = 0;
        while (q--) {
            int op; cin >> op;

            if (op == 0) {
                int x, y; cin >> x >> y;
                if (a[x][y]) continue;
                a[x][y] = 1;
                s.push_back({ x, y });

                if (s.size() > B) {
                    s = vector<pair<int, int>>();

                    for (int i=0; i<prefix.size(); i++)
                        prefix[i][0] = prefix[0][i] = 0;

                    for (int i=1; i<prefix.size(); i++) {
                        for (int j=1; j<prefix.size(); j++) {
                            prefix[i][j] = prefix[i-1][j] + prefix[i][j-1] - prefix[i-1][j-1]
                                            + a[i-1][j-1];
                        }
                    }
                }
            } else {
                int x1, y1, x2, y2;
                cin >> x1 >> y1 >> x2 >> y2;
                int ans = prefix[x2+1][y2+1] - prefix[x1][y2+1] - prefix[x2+1][y1] + prefix[x1][y1];
                for (auto [ x, y ] : s) {
                    if (x >= x1 && x <= x2 && y >= y1 && y <= y2) ans++;
                }
                cout << ans << '\n';
            }
        }
    }
}

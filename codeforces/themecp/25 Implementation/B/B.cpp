#include <bits/stdc++.h>
using namespace std;


using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m, k, t;
    cin >> n >> m >> k >> t;

    set<int> wastes;
    for (int i=0; i<k; i++) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        wastes.insert(a*m+b);
    }

    vector<pair<int, int>> segs;

    int sum = 0;
    int last = -1;
    for (int w : wastes) {
        segs.push_back({ last, sum });
        sum += w - last - 1;
        last = w;
    }
    segs.push_back({last, sum});

    while (t--) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        int i = a * m + b;

        if (wastes.count(i)) {
            cout << "Waste\n";
        } else {
            auto lb = lower_bound(segs.begin(), segs.end(), make_pair(i, 0));
            auto [last, sum] = *(--lb);
            sum += i - last;

            if (sum%3 == 1) {
                cout << "Carrots\n";
            } else if (sum%3 == 2) {
                cout << "Kiwis\n";
            } else {
                cout << "Grapes\n";
            }
        }
    }
}

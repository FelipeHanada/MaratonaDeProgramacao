#include <bits/stdc++.h>
using namespace std;


using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<bool> chosen(m, 0);
    for (int i=0; i<n; i++) {
        int l;
        cin >> l;
        int chose = -1;
        for (int j=0; j<l; j++) {
            int x;
            cin >> x;
            x--;
            if (chose == -1 && !chosen[x]) {
                chosen[x] = 1;
                chose = x;
            }
        }

        cout << (chose == -1 ? 0 : chose + 1) << '\n';
    }
}

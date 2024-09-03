#include <bits/stdc++.h>

using namespace std;


int main() {
    freopen("bcount.in", "r", stdin);
    freopen("bcount.out", "w", stdout);

    int N, Q;
    cin >> N >> Q;

    vector<vector<int>> prefix(3, {0});
    int cow;
    for (int i=0; i<N; i++) {
        cin >> cow;
        for (int j=0; j<3; j++) prefix[j].push_back(prefix[j][i]);
        prefix[cow-1][i + 1]++;
    }

    int a, b;
    for (int i=0; i<Q; i++) {
        cin >> a >> b;
        cout << prefix[0][b] - prefix[0][a - 1] << " "
            << prefix[1][b] - prefix[1][a - 1] << " "
            << prefix[2][b] - prefix[2][a - 1] << endl;
    }
}

#include <bits/stdc++.h>

using namespace std;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    cin >> N >> M;

    vector<tuple<int, int, int>> cows;
    vector<pair<int, int>> occupied_stalls;
    int s, t, c;
    for (int i=0; i<N; i++) {
        cin >> s >> t >> c;
        cows.push_back(tie<int, int, int>(s, t, c));
        occupied_stalls.push_back({s, t});
    }

    vector<tuple<int, int, int, int>> airs;
    int a, b, p, m;
    for (int i=0; i<M; i++) {
        cin >> a >> b >> p >> m;
        airs.push_back(tie<int, int, int, int>(a, b, p, m));
    }

    int min_price = INT32_MAX;
    for (int mask=0; mask<(1<<M); mask++) {
        int price = 0;

        vector<int> used_airs;
        for (int k=0; k<M; k++) {
            if (mask & (1 << k)) {
                price += get<3>(airs[k]);
                used_airs.push_back(k);
            }
        }

        bool ok = true;
        for (int i=0; i<N && ok; i++) {
            pair<int, int> stall = occupied_stalls[i];
            
            for (int j=stall.first; j<= stall.second; j++) {
                int cooling_points = 0;
                for (int air : used_airs) {
                    if (get<0>(airs[air]) <= j && j <= get<1>(airs[air])) {
                        cooling_points += get<2>(airs[air]);
                    }
                }

                if (cooling_points < get<2>(cows[i])) {
                    ok = false;
                    break;
                }
            }
        }
        if (ok) min_price = min(min_price, price);
    }

    cout << min_price << endl;
}

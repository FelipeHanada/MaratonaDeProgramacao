#include <bits/stdc++.h>
using namespace std;


int main() {
    freopen("rental.in", "r", stdin);
    freopen("rental.out", "w", stdout);

    int n, m, r;
    cin >> n >> m >> r;

    vector<int> cows_prefix;
    for (int i=0; i<n; i++) {
        int cow;
        cin >> cow;
        cows_prefix.push_back(cow);
    }
    sort(cows_prefix.begin(), cows_prefix.end(), greater<int>());
    cows_prefix.insert(cows_prefix.begin(), 0);
    for (int i=0; i<n; i++) {
        cows_prefix[i + 1] += cows_prefix[i];
    }

    vector<pair<int, int>> stores;
    for (int i=0; i<m; i++) {
        int p, q;
        cin >> p >> q;
        stores.push_back({p, q});
    }
    sort(stores.begin(), stores.end(), [&](const pair<int, int> &s1, const pair<int, int> &s2) {
        return s1.second > s2.second;
    });

    vector<int> neighbors_prefix;
    for (int i=0; i<r; i++) {
        int ri;
        cin >> ri;
        neighbors_prefix.push_back(ri);
    }
    sort(neighbors_prefix.begin(), neighbors_prefix.end(), greater<int>());
    neighbors_prefix.insert(neighbors_prefix.begin(), 0);
    for (int i=0; i<r; i++) {
        neighbors_prefix[i + 1] += neighbors_prefix[i];
    }

    long long max_profit = 0;
    for (int milked_cows=0; milked_cows<=n; milked_cows++) {
        long long profit = 0;

        int total_milk = cows_prefix[milked_cows];
        vector<pair<int, int>>::iterator store = stores.begin();

        while (total_milk > 0 && store != stores.end()) {
            int milk_sold = min(total_milk, (*store).first);            
            total_milk -= milk_sold;
            profit += milk_sold * (*store).second;
            if (milk_sold == (*store).first) store++; 
        }

        profit += neighbors_prefix[n - milked_cows];

        max_profit = max(max_profit, profit);
    }

    cout << max_profit << endl;
}

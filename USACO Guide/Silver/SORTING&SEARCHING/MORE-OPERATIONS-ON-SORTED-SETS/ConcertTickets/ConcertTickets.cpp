#include <bits/stdc++.h>
using namespace std;


int main() {
    int n, m;
    cin >> n >> m;

    map<int, int> prices;
    for (int i=0; i<n; i++) {
        int h;
        cin >> h;
        if (prices.find(h) == prices.end()) {
            prices.insert({h, 0});
        }
        prices[h]++;
    }

    for (int i=0; i<m; i++) {
        int t;
        cin >> t;
        auto ticket = prices.upper_bound(t);
        if (ticket != prices.begin()) {
            ticket--;
            cout << ticket->first << endl;
            prices[ticket->first]--;
            if (prices[ticket->first] <= 0) {
                prices.erase(ticket);
            }
        } else {
            cout << -1 << endl;
        }
    }
}
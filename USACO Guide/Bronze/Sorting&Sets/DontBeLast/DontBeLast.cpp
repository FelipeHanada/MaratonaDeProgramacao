#include <bits/stdc++.h>

using namespace std;

int main() {
    freopen("notlast.in", "r", stdin);
    freopen("notlast.out", "w", stdout);

    map<string, int> milks = {
        {"Bessie", 0}, {"Elsie", 0}, {"Daisy", 0}, {"Gertie", 0},
        {"Annabelle", 0}, {"Maggie", 0}, {"Henrietta", 0}
    };

    int n;
    cin >> n;

    string s;
    int m;
    for (int i=0; i<n; i++) {
        cin >> s >> m;
        milks[s] += m;
    }

    int min_m = INT32_MAX;
    for (const auto &entry : milks) {
        if (entry.second < min_m) min_m = entry.second;
    }

    string rs = "Tie";
    int rm = INT32_MAX;
    for (const auto &entry : milks) {
        if (entry.second < rm && entry.second > min_m) {
            rs = entry.first;
            rm = entry.second;
        } else if (entry.second == rm) {
            rs = "Tie";
        }
    }

    cout << rs << endl;
}
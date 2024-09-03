#include <bits/stdc++.h>

using namespace std;


int main() {
    freopen("lineup.in", "r", stdin);
    freopen("lineup.out", "w", stdout);

    string cows[8] = {
        "Bessie", "Buttercup", "Belinda", "Beatrice",
        "Bella", "Blue", "Betsy", "Sue"
    };
    sort(cows, cows + 8);


    int n;
    cin >> n;

    set<pair<int, int>> constraints;
    string a, b, s;
    for (int i=0; i<n; i++) {
        cin >> a;
        cin >> s >> s >> s >> s;
        cin >> b;

        int p, q;
        for (int j=0; j<8; j++) {
            if (a == cows[j]) p = j;
            if (b == cows[j]) q = j;
        }

        constraints.insert({ p, q });
    }

    int perm[8] = { 0, 1, 2, 3, 4, 5, 6, 7 };

    do {
        bool valid = true;

        for (pair<int, int> constraint : constraints) {
            int i = 0;
            for (i=0; i<8 && perm[i]!=constraint.second; i++);

            if (
                (i + 1 >= 8 || (i + 1 < 8 && perm[i + 1] != constraint.first)) &&
                (i - 1 < 0 || (i - 1 >= 0 && perm[i - 1] != constraint.first))
            ) {
                valid = false;
                break;
            }
        }

        if (valid) {
            for (int i=0; i<8; i++)
                cout << cows[perm[i]] << endl;
            break;
        }
    } while (next_permutation(perm, perm + 8));
}

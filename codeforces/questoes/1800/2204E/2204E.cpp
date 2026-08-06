#include <bits/stdc++.h>
using namespace std;


int d[10], dd[10];
bool solve(int x) {
    int xx = 0;
    for (int y = x; y; y /= 10) {
        xx += y % 10;
        d[y % 10]--;
    }

    bool ok = 1;
    for (int i=0; ok && i<10; i++) {
        if (d[i] < 0) ok = 0;
    }

    ok = ok && (x == xx || solve(xx));

    if (!ok) {
        for (int y = x; y; y /= 10) {
            d[y % 10]++;
        }
        return 0;
    }

    return 1;
}

int main() {
    int tt;
    cin >> tt;
    while (tt--) {
        string s; cin >> s;
        fill_n(dd, 10, 0);
        for (char c : s) dd[c-'0']++;

        if (s.size() == 1) {
            cout << s << '\n';
            continue;
        }

        int x;
        for (int sum = 1; sum <= 9 * s.size(); sum++) {
            for (int i=0; i<10; i++) d[i] = dd[i];
            // sum = soma dos digitos do primeiro número

            if (!solve(sum)) continue;

            int actual = 0;
            for (int i=1; i<10; i++) actual += d[i] * i;

            if (actual != sum) continue;
            x = sum;
            break;
        }

        string ans;
        for (int i=9; i>=0; i--) {
            while (d[i]--) ans.push_back('0' + i);
        }
        while (1) {
            int xx = 0;
            vector<int> ds;
            for (int y = x; y; y /= 10) {
                xx += y % 10;
                ds.push_back(y % 10);
            }

            reverse(ds.begin(), ds.end());
            for (int digit : ds) ans.push_back('0' + digit);

            if (x == xx) break;
            x = xx;
        }

        cout << ans << '\n';
    }
}

/*
1 -> 10

10^19



*/
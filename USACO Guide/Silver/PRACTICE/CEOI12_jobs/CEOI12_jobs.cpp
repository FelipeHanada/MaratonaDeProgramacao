#include <bits/stdc++.h>
using namespace std;


#define pii pair<int, int>
#define f first
#define s second

int n, d, m;
vector<pii> subs;

bool validate(int k) {
    auto submitted = subs.begin();
    auto done = subs.begin();

    for (int i=1; i<=n+d && done != subs.end(); i++) {
        if (i - done->f > d) {
            return false;
        }

        if (submitted->f <= i) {
            submitted = upper_bound(subs.begin(), subs.end(), pii(i, m+1));
        }

        for (int j=0; j<k && done != submitted; j++) {
            done++;
        }
    }

    return done == submitted;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> d >> m;

    int x;
    for (int i=0; i<m; i++) {
        cin >> x;
        subs.push_back({x, i+1});
    }
    sort(subs.begin(), subs.end());

    int lower = 1;
    int upper = m;
    while (lower < upper) {
        int mid = lower + (upper-lower)/2;

        if (validate(mid)) {
            upper = mid;
        } else {
            lower = mid+1;
        }
    }

    cout << upper << '\n';
    auto it = subs.begin();
    for (int curr = 1; curr <= n; curr++) {
        for (int i=0; i<upper && it != subs.end() && it->f <= curr; i++) {
            cout << it->s << ' ';
            it++;
        }

        cout << "0\n";
    }
}

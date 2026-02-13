#include <bits/stdc++.h>
using namespace std;

int n;
int cows[50000][2];
set<int> h, v;

bool verify(int left, int right, int top, int bottom) {
    int out = 0;
    for (int i=0; i<n; i++) {
        if (
            cows[i][0] < left
            || cows[i][0] > right
            || cows[i][1] < top
            || cows[i][1] > bottom
        ) {
            if (++out > 3) return false;
        }
    }

    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    freopen("reduce.in", "r", stdin);
    freopen("reduce.out", "w", stdout);

    cin >> n;
    for (int i=0; i<n; i++) {
        cin >> cows[i][0] >> cows[i][1];
        h.insert(cows[i][0]);
        v.insert(cows[i][1]);
    }

    int best = (*h.rbegin() - *h.begin()) * (*v.rbegin() - *v.begin());
    auto left = h.begin();
    for (int i=0; i<=3; i++) {
        auto right = h.rbegin();
        for (int j=0; j<=3; j++) {
            auto top = v.begin();            
            for (int k=0; k<=3; k++) {
                auto bottom = v.rbegin();
                for (int w=0; w<=3; w++) {
                    if (verify(*left, *right, *top, *bottom)) {
                        best = min(best, (*right - *left) * (*bottom - *top));
                    }
                    bottom++;
                }
                top++;
            }
            right++;
        }
        left++;
    }

    cout << best << '\n';
}

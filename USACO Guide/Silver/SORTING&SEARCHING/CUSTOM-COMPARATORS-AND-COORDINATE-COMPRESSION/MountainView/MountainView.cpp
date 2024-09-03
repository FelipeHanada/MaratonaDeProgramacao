#include <bits/stdc++.h>
using namespace std;


struct Mountain {
    int x;
    int y;
    friend bool operator<(const Mountain &x, const Mountain &y) {
        return x.y < y.y;
    }
};

int main() {
    freopen("mountains.in", "r", stdin);
    freopen("mountains.out", "w", stdout);

    int n;
    cin >> n;

    vector<Mountain> mountains;
    for (int i=0; i<n; i++) {
        int x, y;
        cin >> x >> y;
        mountains.push_back({x, y});
    }
    sort(mountains.begin(), mountains.end());

    int viewable = n;
    for (int i=0; i<n; i++) {
        for (int j=i+1; j<n; j++) {
            int delta_y = mountains[j].y - mountains[i].y;
            if (
                mountains[i].x >= mountains[j].x - delta_y &&
                mountains[i].x <= mountains[j].x + delta_y
            ) {
                viewable--;
                break;
            }
        }
    }

    cout << viewable << endl;
}

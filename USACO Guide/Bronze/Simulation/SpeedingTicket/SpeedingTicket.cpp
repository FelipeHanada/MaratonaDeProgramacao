#include <bits/stdc++.h>
using namespace std;


int main() {
    freopen("speeding.in", "r", stdin);
    freopen("speeding.out", "w", stdout);

    int n, m;
    scanf("%d %d", &n, &m);

    queue<pair<int, int>> a;
    queue<pair<int, int>> b;

    int x, y;
    for (int i=0; i<n; i++) {
        scanf("%d %d", &x, &y);
        a.push({x, y});
    }
    for (int i=0; i<m; i++) {
        scanf("%d %d", &x, &y);
        b.push({x, y});
    }

    int max_speed_over_lim = 0;
    while (a.size() * b.size() != 0) {
        int distance = min(a.front().first, b.front().first);

        if (b.front().second > a.front().second)
            max_speed_over_lim = max(max_speed_over_lim, b.front().second - a.front().second);

        a.front().first -= distance;
        b.front().first -= distance;

        if (a.front().first == 0) a.pop();
        if (b.front().first == 0) b.pop();
    }

    printf("%d\n", max_speed_over_lim);
}

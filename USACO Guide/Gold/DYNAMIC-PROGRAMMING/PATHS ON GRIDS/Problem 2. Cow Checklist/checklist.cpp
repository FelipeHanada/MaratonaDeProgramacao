#include <bits/stdc++.h>
using namespace std;

#define ll long long

struct Cow { int x, y; };
int dist(Cow& a, Cow& b) {
    int dx = a.x - b.x, dy = a.y - b.y;
    return dx*dx + dy*dy;
}

Cow H[1000], G[1000];
ll dpH[1001][1001], dpG[1001][1001];


int main() {
    freopen("checklist.in", "r", stdin);
    freopen("checklist.out", "w", stdout);

    int h, g;
    cin >> h >> g;

    for (int i=0; i<h; i++) {
        cin >> H[i].x >> H[i].y;
    }
    for (int i=0; i<g; i++) {
        cin >> G[i].x >> G[i].y;
    }

    for (int i=0; i<=h; i++) {
        fill_n(dpH[i], g+1, INT32_MAX);
        fill_n(dpG[i], g+1, INT32_MAX);
    }

    dpH[1][0] = 0;
    for (int i=1; i<=h; i++) {
        for (int j=0; j<=g; j++) {

            if (i > 1) {
                // its possible to go from H to H
                dpH[i][j] = min(
                    dpH[i][j],
                    dpH[i-1][j] + dist(H[i-2], H[i-1])
                );
            }

            if (j > 1) {
                // its possible to go from G to G
                dpG[i][j] = min(
                    dpG[i][j],
                    dpG[i][j-1] + dist(G[j-2], G[j-1])
                );
            }

            // to go from H to G or G to H
            if (j > 0) {
                dpH[i][j] = min(
                    dpH[i][j],
                    dpG[i-1][j] + dist(H[i-1], G[j-1])
                );
    
                dpG[i][j] = min(
                    dpG[i][j],
                    dpH[i][j-1] + dist(H[i-1], G[j-1])
                );
            }

        }
    }

    cout << dpH[h][g] << '\n';
}

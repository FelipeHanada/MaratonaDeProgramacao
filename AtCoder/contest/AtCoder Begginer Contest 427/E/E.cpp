#include <bits/stdc++.h>
using namespace std;


int mdx[4] = {-1, 1, 0, 0};
int mdy[4] = {0, 0, -1, 1};

int main() {
    int h, w;
    cin >> h >> w;

    int Tx, Ty;
    vector<int> tx, ty;
    char c;
    for (int i=0; i<h; i++) {
        for (int j=0; j<w; j++) {
            cin >> c;
            if (c == '#') {
                tx.push_back(i);
                ty.push_back(j);
            } else if (c == 'T') {
                Tx = i;
                Ty = j;
            }
        }
    }

    // dxx, dyy, lx, ly, rx, ry
    vector d(2*h+1, vector(2*w+1, vector(h+1, vector(w+1, vector(h+1, vector(w+1, -1))))));
    queue<array<int, 6>> bfs;

    d[h][w][0][0][h][w] = 0;
    bfs.push({h, w, 0, 0, h, w});
    while (!bfs.empty()) {
        auto [dxx, dyy, lx, ly, rx, ry] = bfs.front(); bfs.pop();
        int dx = h - dxx, dy = w - dyy;

        bool ok = true;
        int trashes = 0;
        for (int i=0; i<tx.size(); i++) {
            if (tx[i] < lx || tx[i] >= rx || ty[i] < ly || ty[i] >= ry) continue;
            trashes++;
            if (tx[i]+dx == Tx && ty[i]+dy == Ty) ok = false;
        }
        if (!ok) continue;
        if (trashes == 0) {
            cout << d[dxx][dyy][lx][ly][rx][ry] << '\n';
            return 0;
        }

        for (int i=0; i<4; i++) {
            int ddxx = dxx+mdx[i],
                ddyy = dyy+mdy[i];
            int llx = max(lx, ddxx - h),
                lly = max(ly, ddyy - w),
                rrx = min(rx, ddxx),
                rry = min(ry, ddyy);

            if (ddxx < 0 || ddxx > 2*h || ddyy < 0 || ddyy > 2*w
                || llx < 0 || llx > h || rrx < 0 || rrx > h
                || lly < 0 || lly > w || rry < 0 || rry > w
            ) continue;
            
            if (d[ddxx][ddyy][llx][lly][rrx][rry] != -1) continue;
            bfs.push({ddxx, ddyy, llx, lly, rrx, rry});
            d[ddxx][ddyy][llx][lly][rrx][rry] = d[dxx][dyy][lx][ly][rx][ry] + 1;
        }
    }

    cout << "-1\n";
}

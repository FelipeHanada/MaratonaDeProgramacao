#include <bits/stdc++.h>
using namespace std;


const int MAX_N = 1000, MAX_M = 1000;
bool seen[MAX_N][MAX_M];
int n, m;

void flood_fill(int i, int j) {
    if (i < 0 || i >= n || j < 0 || j >= m) return;
    if (seen[i][j]) return;

    seen[i][j] = true;
    
    flood_fill(i-1, j);
    flood_fill(i+1, j);
    flood_fill(i, j-1);
    flood_fill(i, j+1);
}

int main() {
    cin >> n >> m;

    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            char c;
            cin >> c;
            seen[i][j] = (c == '#');
        }
    }

    int rooms = 0;
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            if (!seen[i][j]) {
                rooms++;
                flood_fill(i, j);
            }
        }
    }

    cout << rooms << endl;
}
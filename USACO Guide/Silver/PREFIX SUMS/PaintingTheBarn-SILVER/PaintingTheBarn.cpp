#include <bits/stdc++.h>
using namespace std;


int prefix_array[1000][1001] = {};

int main() {
    freopen("paintbarn.in", "r", stdin);
    freopen("paintbarn.out", "w", stdout);
    
    int n, k;
    cin >> n >> k;

    for (int i=0; i<n; i++) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;

        for (int j=y1; j<y2; j++) {
            prefix_array[j][x1]++;
            prefix_array[j][x2]--;
        }
    }

    int area = 0;
    for (int i=0; i<1000; i++) {
        for (int j=0; j<1000; j++) {
            if (prefix_array[i][j] == k) area++;
            prefix_array[i][j+1] += prefix_array[i][j];
        }
    }

    cout << area << endl;
}

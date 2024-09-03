#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    int x[n];
    int y[n];

    for (int i=0; i<n; i++) cin >> x[i];
    for (int i=0; i<n; i++) cin >> y[i];
    
    int max_square_distance = 0;
    for (int i=0; i<n; i++) {
        for (int j=i+1; j<n; j++) {
            int dx = x[i] - x[j];
            int dy = y[i] - y[j];
            
            max_square_distance = max(max_square_distance, dx*dx + dy*dy);
        }
    }

    cout << max_square_distance << endl;
}

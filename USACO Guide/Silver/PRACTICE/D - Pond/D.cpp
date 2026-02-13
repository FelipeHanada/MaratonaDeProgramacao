#include <bits/stdc++.h>
using namespace std;


constexpr int MAX_N = 800;
int n, k;
int grid[MAX_N][MAX_N];
int prefix[MAX_N+1][MAX_N+1];

bool check(int x) {
    // all submatrices kxk median are >= x?

    for (int i=1; i<=n; i++) {
        for (int j=1; j<=n; j++) {
            prefix[i][j] = prefix[i-1][j] + prefix[i][j-1] - prefix[i-1][j-1];
            if (grid[i-1][j-1] > x) prefix[i][j]++;
        }
    }

    for (int i=k; i<=n; i++) {
        for (int j=k; j<=n; j++) {
            if (prefix[i][j] - prefix[i-k][j] - prefix[i][j-k] + prefix[i-k][j-k] < ((k*k)/2)+1)
                return false;
        }
    }
    return true;
}

int main() {
    cin >> n >> k;
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            cin >> grid[i][j];
        }
    }

    for (int i=0; i<=n; i++) {
        fill_n(prefix[i], n+1, 0);
    }


    int low = -1, high = 1e9+1;
    while (high - low > 1) {
        int mid = (low + high) / 2;
        if (check(mid)) {
            low = mid;
        } else {
            high = mid;
        }
    }

    cout << high << '\n';
}

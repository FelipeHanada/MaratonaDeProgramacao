#include <bits/stdc++.h>
using namespace std;


constexpr int MAX_N = 800;
int n, k;
int grid[MAX_N][MAX_N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> k;

    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            cin >> grid[i][j];
        }
    }

    int best = INT32_MAX;
    for (int i=0; i<n-k+1; i++) {
        // run a sliding window for the biggest median
        multiset<int> small, big;
        for (int a=0; a<k; a++) {
            for (int b=0; b<k; b++) {
                big.insert(grid[i+a][b]);
            }
        }
        while (small.size() < big.size()) {
            small.insert(*big.begin());
            big.extract(*big.begin());
        }

        best = min(best, *small.rbegin());

        for (int l=1; l+k-1<n; l++) {
            for (int a=i; a<i+k; a++) {
                if (small.count(grid[a][l-1])) small.extract(grid[a][l-1]);
                else big.extract(grid[a][l-1]);

                if (small.empty() || *small.rbegin() < grid[a][l+k-1])
                    big.insert(grid[a][l+k-1]);
                else 
                    small.insert(grid[a][l+k-1]);
            }

            while (big.size() < small.size()) {
                big.insert(*small.rbegin());
                small.extract(*small.rbegin());
            }

            while (small.size() < big.size()) {
                small.insert(*big.begin());
                big.extract(*big.begin());
            }

            best = min(best, *small.rbegin());
        }
    }

    cout << best << '\n';
}
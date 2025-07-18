#include <bits/stdc++.h>
using namespace std;


using ll = long long;
using ull = unsigned long long;
using uint = unsigned int;
constexpr int MOD = 1e9 + 7;
constexpr ll MAX_N = 1e18 + 1;
constexpr int MAX_M = 1e5;
constexpr int MAX_A = 100;
constexpr int MAX_B = 60;
constexpr ll BLOCK = 10000;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ull n; int m;
    vector<int> v[MAX_B + 1];
    // v[i] all the weapons with b = i
    array<int, BLOCK> block;

    cin >> n >> m;
    for (int i=0; i<m; i++) {
        int a, b;
        cin >> a >> b;
        v[b].push_back(a);
    }

    for (int i=0; i<= MAX_B; i++)
        sort(v[i].begin(), v[i].end());

        fill(block.begin(), block.end(), 0);

    // calculate the first 100 and place them on the end of block
    block[BLOCK - MAX_A] = 1;
    for (int i=BLOCK - MAX_A + 1; i < BLOCK; i++) {
        int x = i - BLOCK + MAX_A, j = 0;
        
        while (x && !(x & 1)) {
            for (auto it = v[j].begin(); it != v[j].end() && i - *it >= 0; it++) {
                block[i] = (block[i] + block[i - *it]) % MOD;
            }
            x >>= 1; j++;                
        }

        if (x) {
            for (auto it = v[j].begin(); it != v[j].end() && i - *it >= 0; it++) {
                block[i] = (block[i] + block[i - *it]) % MOD;
            }
        }
    }

    ull start = MAX_A; // already calculated the first 100
    do {
        // copy the last 100 elements to the first and erase everything
        start -= MAX_A;
        for (int i=0; i < MAX_A; i++) {
            block[i] = block[BLOCK - MAX_A + i];
        }
        fill(block.begin() + MAX_A, block.end(), 0);

        for (uint i=MAX_A; i < BLOCK && start + i <= n; i++) {
            for (auto it = v[0].begin(); it != v[0].end() && start + i - *it >= 0; it++) {
                block[i] = (block[i] + block[i - *it]) % MOD;
            }
            
            uint x = start + i;
            for (int j=1; ~(x & 1); j++) {
                for (auto it = v[j].begin(); it != v[j].end() && start + i - *it >= 0; it++) {
                    block[i] = (block[i] + block[i - *it]) % MOD;
                }
                x >>= 1;
            }
        }

        start += BLOCK;
    } while (start <= n);

    start -= BLOCK;
    cout << block[n - start] << "\n";
}

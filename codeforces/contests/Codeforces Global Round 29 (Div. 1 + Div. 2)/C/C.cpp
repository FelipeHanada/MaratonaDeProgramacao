#include <bits/stdc++.h>
using namespace std;


/*
dá pra tirar todos os zeros do começo e do final


001101100 -> 11011

10001110001
101010

clusters de pelo menos 2 zeros nunca vão ter problemas
0's isolados precisam de 

cada zero isolado precisa de outro cluster próximo
*/


bool solve() {
    int n;
    cin >> n;

    deque<char> bunnies(n);
    for (int i=0; i<n; i++) cin >> bunnies[i];

    int i=0;
    while (i < n && bunnies[i] == '1') i++;
    int start = i;
    if (i >= n) return true; // there is no bunny
    bool prev = true;
    int zeros = 1;
    i++;
    for (; i<n; i++) {
        if ((bunnies[i] == '0') == prev) {
            if (bunnies[i] == '1' && zeros % 2) {
                // impar
                if (!((start == 0 && bunnies[start] == '0') || (start > 0 && bunnies[start-1] == '0'))) {
                    return false;
                }
            }

            while (i < n && bunnies[i] == '1') i++;
            start = i;
            zeros = 0;
            // começa nova cadeia
        }
        
        if (bunnies[i] == '0') zeros++;
        prev = bunnies[i] == '0';
    }

    if (start < n && zeros % 2) {
        if (!((start == 0 && bunnies[start] == '0') || bunnies[n-1] == '0' || (start > 0 && bunnies[start-1] == '0'))) return false;
    }

    return true;
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        cout << (solve() ? "YES" : "NO") << '\n';
    }
}
#include <bits/stdc++.h>
using namespace std;


void solve() {

}

int main() {
    int n, k;
    cin >> n >> k;

    // N * x + (N-1) <= K
    // N * x <= K - N + 1

    cout << (k - n + 1) / n << "\n"; 
}

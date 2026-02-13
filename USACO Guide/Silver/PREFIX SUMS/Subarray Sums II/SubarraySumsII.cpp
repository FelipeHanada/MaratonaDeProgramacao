#include <bits/stdc++.h>
using namespace std;


#define ll long long

int n, x;
constexpr int MAX_N = 2*2e5;
ll prefix[MAX_N+1];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> x;
    prefix[0] = 0;

    int curr;
    ll ans = 0;
    ll prefix = 0;
    map<ll, int> sums; // sums[k] = quantidade de subarrays que somam k e começam no começo
    sums[0] = 1;
    for (int i=0; i<n; i++) {
        cin >> curr;
        prefix += curr;

        ans += sums[prefix - x];
        // seja A o subarray atual que começa no primeiro elemento e para em i com soma prefix
        // e B um subarray que começa no primeiro elemento e termina antes que A com soma prefix-x
        // o subarray C definido pelos elementos de A que não estão em B soma exatamente x.
        sums[prefix]++;
    }

    cout << ans << '\n';
}

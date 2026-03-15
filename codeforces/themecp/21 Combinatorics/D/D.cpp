#include <bits/stdc++.h>
using namespace std;


using ll = long long;

/*
13990 | 13990 | 13990 | ... | 13990 

2^|a|   2^|a|*2^|a|

2^j * (1 + 2^|a| + 2^(2|a|) + 2^(3|a|) + ... + 2^((k-1)|a|))
    j é a posição de 5 ou 0

somatório disso pra cada posição
*/

constexpr int md = int(1e9)+7;
constexpr int inv2 = ((ll)md * 2) % md;
int mult(int a, int b) {
    return ((ll)a * b) % md;
}
int add(int a, int b) {
    a += b;
    if (a > md) a -= md;
    return a;
}
int sub(int a, int b) {
    a -= b;
    if (a < 0) a += md;
    return a;
}

int binpow(int a, ll b) {
    int ans = 1;
    while (b) {
        if (b & 1) {
            ans = mult(ans, a);
        }
        a = mult(a, a);
        b >>= 1;
    }
    return ans;
}

string a; int k;
vector<int> twop;

map<int, pair<int, int>> memo;
pair<int, int> get_sum(int n) {
    if (n == 0) return { 0, 1 };
    if (n == 1) return { 1, twop[a.size()] };

    if (memo.count(n)) return memo[n];

    auto [ sum_left, left ] = get_sum(n/2);
    auto [ sum_right, right ] = get_sum(n - n/2);

    memo[n] = { add(sum_left, mult(left, sum_right)), mult(left, right) };
    return { add(sum_left, mult(left, sum_right)), mult(left, right) };
}

int main() {
#ifdef ONLINE_JUDGE
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
#endif
    cin >> a >> k;

    twop.assign(a.size()+1, 0);
    twop[0] = 1;
    for (int i=1; i<=a.size(); i++) {
        twop[i] = mult(twop[i-1], 2);
    }

    auto [ sum, trash ] = get_sum(k);

    int ans = 0;
    for (int i=0; i<a.size(); i++) {
        if (a[i] != '5' && a[i] != '0') continue;

        ans = add(ans, mult(sum, twop[i]));
    }

    cout << ans << '\n';
}

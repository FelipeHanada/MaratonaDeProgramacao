#include <bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr int md = 998244353;
constexpr int inv2 =  (998244353+1)/2;

int add(int a, int b) {
    a += b;
    if (a >= md) a -= md;
    return a;
}
int mult(int a, int b) { return ((ll)a * b) % md; }
int binpow(int a, int b) {
    int ans = 1;
    while (b) {
        if (b & 1) ans = mult(ans, a);
        a = mult(a, a);
        b >>= 1;
    }
    return ans;
}
int inv(int a) { return binpow(a, md-2); }
constexpr int N = int(2e5) + 5;
int fat[N], ifat[N];
int binom(int n, int k) {
    return mult(fat[n], mult(ifat[k], ifat[n-k]));
}
int ipow2[N];

int main() {
    fat[0] = 1;
    for (int i=1; i<N; i++) fat[i] = mult(fat[i-1], i);
    ifat[N-1] = inv(fat[N-1]);
    for (int i=N-2; i>=0; i--) ifat[i] = mult(ifat[i+1], i+1);

    ipow2[0] = 1;
    for (int i=1; i<N; i++) ipow2[i] = mult(ipow2[i-1], inv2);

    int n; cin >> n;
    vector<pair<int, int>> a(n);
    for (int i=0; i<n; i++) cin >> a[i].first >> a[i].second;

    int W = INT32_MIN;
    for (int i=0; i<n; i++) W = max(W, max(a[i].first, a[i].second));

    for (int i=0; i<n; i++) {
        if (a[i].first == W) a[i].first = 2;
        else if (a[i].first == W-1) a[i].first = 1;
        else a[i].first = 0;
        if (a[i].second == W) a[i].second = 2;
        else if (a[i].second == W-1) a[i].second = 1;
        else a[i].second = 0;
    }

    int w2_w2 = 0, w2_w1 = 0, w2_w0 = 0, w1_w1 = 0, w1_w0 = 0;
    for (int i=0; i<n; i++) {
        int x = min(a[i].first, a[i].second),
            y = max(a[i].first, a[i].second);

        if (x == 2) w2_w2++;
        else if (x == 1) {
            if (y == 2) w2_w1++;
            else w1_w1++;
        } else {
            if (y == 2) w2_w0++; 
            else if (y == 1) w1_w0++;
        }
    }

    map<pair<int, int>, int> memo;
    auto solve = [&](int curr, int par) -> int {
        if (memo.count({curr, par})) return memo[{curr, par}];
        if (curr == 0) return 0;
        else if (curr == 1) {
            if (w2_w2) return 0;
            
            if (par == 0) w1_w0--;
            else if (par == 1) w1_w1--;
            else w2_w1--;

            // precisa vencer, obrigatoriamente
            int ans = inv2;

            // nenhum confronto w2_wx pode ser vitorioso para o w2
            ans = mult(ans, ipow2[w2_w0]);
            ans = mult(ans, ipow2[w2_w1]);

            // o coinflip final depende da quantidade de w1 vitoriosos
            //      + quantidade de w2
            // w1_w1 sempre gera algum w1 vitorioso
            // w2_w1 sempre gera algum w1 vitorioso
            // w1_w0 é um problema
            int c = add(add(add(w1_w1, w2_w1), add(w2_w0, w2_w1)), add(par == 2, 1));
            int coinflip = 0;
            int N = w1_w0;
            for (int b=0; b<=N; b++) {
                coinflip = add(coinflip, mult(binom(N, b), inv(add(c, b))));
            }
            coinflip = mult(coinflip, ipow2[N]);

            ans = mult(ans, coinflip);

            if (par == 0) w1_w0++;
            else if (par == 1) w1_w1++;
            else w2_w1++;

            memo[{curr, par}] = ans;
            return ans;
        } else {
            int ans = 0;

            if (par == 0) w2_w0--;
            else if (par == 1) w2_w1--;
            else w2_w2--;

            if (!w2_w2 && par != 2) {
                // caso onde perde

                int lose = inv2;
                // nenhum confronto w2_wx pode ser vitorioso para o w2
                lose = mult(lose, ipow2[w2_w0]);
                lose = mult(lose, ipow2[w2_w1]);

                // o coinflip final depende da quantidade de w1 vitoriosos
                //      + quantidade de w2
                // w1_w1 sempre gera algum w1 vitorioso
                // w2_w1 sempre gera algum w1 vitorioso
                // w2_w0 + w2_w1 contam w2 (eles sempre perdem)
                // w1_w0 é o problema
                int c = add(add(add(w1_w1, w2_w1), add(w2_w0, w2_w1)), add(par == 1, 1));
                int coinflip = 0;
                int N = w1_w0;
                for (int b=0; b<=N; b++) {
                    coinflip = add(coinflip, mult(binom(N, b), inv(add(c, b))));
                }
                coinflip = mult(coinflip, ipow2[N]);

                lose = mult(lose, coinflip);
                ans = add(ans, lose);
            }

            {
                // caso onde ganha
                // o coinflip final depende da quantidade de w2 vitoriosos
                // w2_w2 sempre gera um w2 vitorioso
                // w2_w1 e w2_w0 são o problema
                int win = inv2;

                int c = add(1, w2_w2);
                int coinflip = 0;
                int N = add(w2_w1, w2_w0);
                for (int b=0; b<=N; b++) {
                    coinflip = add(coinflip, mult(binom(N, b), inv(add(c, b))));
                }
                coinflip = mult(coinflip, ipow2[N]);
                win = mult(win, coinflip);
                ans = add(ans, win);
            }

            if (par == 0) w2_w0++;
            else if (par == 1) w2_w1++;
            else w2_w2++;

            memo[{curr, par}] = ans;
            return ans;
        }
    };

    vector<int> ans(n*2);
    for (int i=0; i<n; i++) {
        ans[2*i] = solve(a[i].first, a[i].second);
        ans[2*i+1] = solve(a[i].second, a[i].first);
    }

    for (int x : ans) cout << x << ' ';
    cout << '\n';
}

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define _ ios::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);


/*
let prefix[i] = (a, b, c)

for some index j, the number of substrings that satisfy are the ones such that
    prefix[j] - prefix[i] = (aj - ai, bj - bi, cj - ci) are all diff.
    = total - number that have some equal

    we can compute the number that have some equal using inclusion-exclusion principle
    number that have some equal
    = nº that have (aj - ai = bj - bi) + nº that have (aj - ai = cj - ci)
     + nº that have (bj - bi = cj - ci) - 3 * nº that have (aj - ai = bj - bi = cj - ci)
     this may be not fast enough...


if they are diff. there exists some order like
    a < b < c





total - some is equal
some is equal =
    Q(a = b) + Q(b = c) + Q(a = c)
    - Q(a = b && b = c) - Q(b = c && a = c) - Q(a = b && a = c)
    + Q(a = b && b = c && a = c)
that is
some is equal = Q(a = b) + Q(b = c) + Q(a = c) - 2Q(a = b = c)

we can compute Q(a = b), Q(b = c) and Q(a = c) easily
    using prefixes in O(N)

Q(a = b = c) is the hard one
    let store the deltas to the bigger one

some is equal
 = Q(a = b or b = c or a = c)
 = Q(a = b) + Q(b = c) + Q(a = c)
   - Q(a = b and b = c) - Q(a = b and a = c) - Q(b = c and a = c)
   + Q(a = b and b = c and a = c)
 = Q(a = b) + Q(b = c) + Q(a = c) - 2Q(a = b = c)
*/

int main() {
    ll n; string s;
    cin >> n >> s;

    auto solve1 = [&](char A, char B) -> ll {
        map<pair<int, int>, int> cnt;
        int cntA = 0, cntB = 0;
        cnt[make_pair(max(cntA, cntB) - cntB, max(cntA, cntB) - cntA)]++;

        ll ans = 0;
        for (int i=0; i<n; i++) {
            if (s[i] == A) cntA++;
            if (s[i] == B) cntB++;
            auto p = make_pair(max(cntA, cntB) - cntA, max(cntA, cntB) - cntB);
            ans += cnt[p];
            cnt[p]++;
        }
        return ans;
    };
    ll qab = solve1('A', 'B'),
        qbc = solve1('B', 'C'),
        qac = solve1('A', 'C');

    ll qabc = 0;
    map<tuple<int, int, int>, int> cnt;
    int cntA = 0, cntB = 0, cntC = 0;
    cnt[make_tuple(0, 0, 0)]++;

    for (int i=0; i<n; i++) {
        if (s[i] == 'A') cntA++;
        if (s[i] == 'B') cntB++;
        if (s[i] == 'C') cntC++;
        int big = max(max(cntA, cntB), cntC);
        auto t = make_tuple(big - cntA, big - cntB, big - cntC);
        qabc += cnt[t];
        cnt[t]++;
    }

    cout << n * (n+1) / 2 - (qab + qbc + qac - 2*qabc) << '\n';
}
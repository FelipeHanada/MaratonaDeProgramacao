#include <bits/stdc++.h>
using namespace std;


using ll = long long;

/*
cntB[0]x + cntC[0]y <= cntA[0]
cntB[1]x + cntC[1]y <= cntA[1]
cntB[2]x + cntC[2]y <= cntA[2]
...
cntB[25]x + cntC[25]y <= cntA[25]

temos que maximizar x + y, satisfazendo todas essas restrições
x estará maximizado ou minimizado em alguma dessas ineq.
como são 26 ineqs. podemos testar cada uma
*/

int main() {
#ifdef ONLINE_JUDGE
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
#endif
    string a, b, c;
    cin >> a >> b >> c;

    array<int,26> cntA, cntB, cntC;
    fill(cntA.begin(), cntA.end(), 0);
    fill(cntB.begin(), cntB.end(), 0);
    fill(cntC.begin(), cntC.end(), 0);
    for (char ch : a) cntA[ch-'a']++;
    for (char ch : b) cntB[ch-'a']++;
    for (char ch : c) cntC[ch-'a']++;

    pair<int,int> best = { -1, -1 };

    int any = b[0] - 'a';
    for (int x=0; cntB[any]*x <= cntA[any]; x++) {
        int y = INT32_MAX;

        bool ok = 1;
        // verifica se há solução
        for (int j=0; ok && j<26; j++) {
            if (cntB[j]) {
                if (x > cntA[j]/cntB[j]) ok = 0;
            }

            if (cntC[j]) {
                y = min(y, cntA[j]/cntC[j]);
            }

            if (cntB[j] && cntC[j]) {
                y = min(y, (cntA[j]-cntB[j]*x)/cntC[j]);
            }
        }

        ok = ok && (y >= 0);
        if (!ok) continue;
        if (x + y > best.first + best.second) {
            best = { x, y };
        }
    }

    for (int i=0; i<best.first; i++) {
        cout << b;
        for (char ch : b) cntA[ch-'a']--;
    }
    for (int i=0; i<best.second; i++) {
        cout << c;
        for (char ch : c) cntA[ch-'a']--;
    }
    for (int i=0; i<26; i++) {
        for (int j=0; j<cntA[i]; j++) cout << char('a'+i);
    }
    cout << '\n';
}

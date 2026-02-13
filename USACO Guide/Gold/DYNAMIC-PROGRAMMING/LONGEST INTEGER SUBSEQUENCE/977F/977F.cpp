#include <bits/stdc++.h>
using namespace std;



int main() {
    int n;
    cin >> n;

    map<int, int> d;  // d[x]: tamanho da maior subseq terminada em x
    map<int, int> di; // di[x]: índice do último elemento da maior subseq terminada em x
    int p[n];         // p[i]: o índice do elemento anterior da maior subseq cujo último elemento está em i

    int x;
    int ans = 0;
    int ans_i = 0;
    for (int i=0; i<n; i++) {
        cin >> x;

        if (d[x-1] + 1 > d[x]) {
            // existe uma subseq maior
            d[x] = d[x-1] + 1;
            di[x] = i;
            p[i] = di.count(x-1) ? di[x-1] : -1;

            if (d[x] > ans) {
                ans = d[x];
                ans_i = i;
            }
        }
    }

    cout << ans << '\n';
    stack<int> sol;
    while (ans_i >= 0) {
        sol.push(ans_i);
        ans_i = p[ans_i];
    }
    while (!sol.empty()) {
        cout << sol.top() + 1 << ' ';
        sol.pop();
    }
    cout << '\n';
}

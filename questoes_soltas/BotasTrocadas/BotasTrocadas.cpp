// https://olimpiada.ic.unicamp.br/pratique/p2/2017/f1/botas/

#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    
    map<int, pair<int, int>> m;
    int p; char q;
    for (int i=0; i<n; i++) {
        cin >> p >> q;
        
        if (m.find(p) == m.end()) {
            // não encontrou a chave p dentro do map m
            m.insert({p, {0, 0}});
        }

        if (q == 'D') m[p].first++;
        else m[p].second++;
    }

    int count = 0;
    for (pair<int, pair<int, int>> entry : m) {
        pair<int, int> v = entry.second;
        count += min(v.first, v.second);
    }

    cout << count << endl;
}

#include <bits/stdc++.h>

using namespace std;


int main() {
    freopen("cownomics.in", "r", stdin);
    freopen("cownomics.out", "w", stdout);

    int n, m;
    cin >> n >> m;

    set<char> possible_spotty_genes[m];

    string gen_strip;
    for (int i=0; i<n; i++) {
        cin >> gen_strip;

        for (int j=0; j<m; j++) {
            possible_spotty_genes[j].insert(gen_strip[j]);
        }
    }

    int result[m] = { 0 };
    for (int i=0; i<n; i++) {
        cin >> gen_strip;

        for (int j=0; j<m; j++) {
            if (result[j] == 1) continue;
             
            if (possible_spotty_genes[j].find(gen_strip[j]) != possible_spotty_genes[j].end())
                result[j] = 1;
        }
    }

    int count = 0;
    for (int i=0; i<m; i++)
        if (result[i] == 0)
            count += 1;

    cout << count << endl;
}

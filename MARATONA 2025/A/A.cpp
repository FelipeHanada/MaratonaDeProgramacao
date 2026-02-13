#include <bits/stdc++.h>
using namespace std;


int main() {
    int n, m;
    cin >> n >> m;
    
    vector<int> min_alunos(m, 0);
    int x;
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            cin >> x;
            min_alunos[j] = max(min_alunos[j], x);
        }
    }

    int ans = 0;
    for (int i=0; i<m; i++) {
        ans += min_alunos[i];
    }
    cout << ans << '\n';
}

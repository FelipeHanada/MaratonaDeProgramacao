#include <bits/stdc++.h>

using namespace std;

int main() {
    freopen("div7.in", "r", stdin);
    freopen("div7.out", "w", stdout);

    int n;
    cin >> n;
    vector<int> prefix(n+1, 0);

    for(int i = 1; i <= n; i++){
        cin >> prefix[i];
        prefix[i] = (prefix[i] + prefix[i-1]) % 7;
    }

    int best = 1;
    for(int i = 0; i <= n; i++){
        for(int j = i; j <= n; j++){
            if(!((prefix[j]-prefix[i]) % 7)){
                best = max(best, j-i);
            }
        }
    }
    cout << best << endl;

    return 0;
}
#include <bits/stdc++.h>
using namespace std;


int main() {
    int n, k;
    cin >> n >> k;

    vector<pair<int, int>> p(n);
    for (int i=0; i<n; i++)
        cin >> p[i].first >> p[i].second;
    
    sort(p.begin(), p.end());
}
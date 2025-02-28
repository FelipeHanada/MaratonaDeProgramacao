#include <bits/stdc++.h>
using namespace std;


int main() {
    int n, k;
    cin >> n >> k;
    
    vector<int> h(n);
    for (int i=0; i<n; i++)
        cin >> h[i];

    int i = 0, j = 1;
    int best = 1;
    while (i < n) {
        int current = 1;
        while (j < n && abs(h[j] - h[j - 1]) <= k) {
            j++;
            current++;
        }
        
        i = j++;
        best = max(best, current);
    }

    cout << best << "\n";
}
#include <bits/stdc++.h>
using namespace std;



int main() {
    int n, k;
    cin >> n >> k;

    vector<int> v(n);
    int min_pos = -1;
    int menor = INT32_MAX;
    for (int i=0; i<n; i++) {
        cin >> v[i];
        if (v[i] < menor) {
            menor = v[i];
            min_pos = i;
        }
    }

    int j=0;
    int maior_in = INT32_MIN;
    int best_c;
    for (int i=min_pos; i<n && j<k; i++) {
        if (menor + k - j >= v[i]) {
            maior_in = menor + k - j;
            best_c = i;
        }
        j++;
    }

    int left = INT32_MAX, right = INT32_MAX;
    for (int i=0; i<=best_c - k; i++) {
        left = min(left, v[i]);
    }
    for (int i=best_c +1; i<n; i++) {
        right = min(right, v[i]);
    }

    cout << min(maior_in, min(left, right)) << '\n';
}
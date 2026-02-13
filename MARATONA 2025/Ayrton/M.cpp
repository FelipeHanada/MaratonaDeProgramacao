#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    long long array[n];

    int min_pos;
    long long minimum = 10000000000000;
    int best_pos;

    for (int i = 0; i < n; i++) {
        cin >> array[i];

        if (array[i] < minimum) {
            minimum = array[i];
            min_pos = i;
        }
    }

    for (int i = min_pos, j = 0; i < n && j < k; i++, j++) {
        if (minimum + k - j >= array[i]) {
            best_pos = i;
        }
    }

    for (int i = best_pos, j = 0; i >= 0 && j < k; i--, j++) {
        array[i] += k - j;
    }

    long long res = 10000000000000;

    for (int i = 0; i < n; i++) {
        res = min(res, array[i]);
    }

    cout << res << "\n";

    return 0;
}

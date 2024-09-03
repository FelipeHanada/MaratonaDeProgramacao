#include <bits/stdc++.h>
using namespace std;


int main() {
    freopen("diamond.in", "r", stdin);
    freopen("diamond.out", "w", stdout);

    int n, k;
    cin >> n >> k;

    int v[n];
    for (int i=0; i<n; i++) cin >> v[i];
    sort(v, v+n);

    int case_size[n];
    // size of the case if we pick i is the smallest diamond of the case
    for (int left=0; left<n; left++) {
        int right = left + 1;
        while (right < n && v[right] - v[left] <= k) {
            right++;
        }

        case_size[left] = right - left;
    }

    int max_size = 0;
    for (int left_case_i=0; left_case_i<n; left_case_i++) {
        int max_right_case_size = 0;
        int right_case_i = left_case_i + case_size[left_case_i];
        for (; right_case_i < n; right_case_i++) {
            max_right_case_size = max(max_right_case_size, case_size[right_case_i]);
        }

        max_size = max(max_size, case_size[left_case_i] + max_right_case_size);
    }

    cout << max_size << endl;
}
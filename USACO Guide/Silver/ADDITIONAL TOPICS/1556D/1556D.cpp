#include <bits/stdc++.h>
using namespace std;


int ask_sum(int a, int b) {
    int band, bor;

    cout << "and " << a << ' ' << b << '\n';
    fflush(stdout);
    cin >> band;
    cout << "or " << a << ' ' << b << '\n';
    fflush(stdout);
    cin >> bor;

    return (bor & ~(band)) + (band << 1);
}

int main() {
    int n, k;
    cin >> n >> k;

    vector<int> a;

    int sum12 = ask_sum(1, 2),
        sum13 = ask_sum(1, 3),
        sum23 = ask_sum(2, 3);
    
    a.push_back((sum12 + sum13 - sum23) / 2);
    a.push_back(sum12 - a[0]);
    a.push_back(sum13 - a[0]);

    for (int i=3; i<n; i++) {
        int sum = ask_sum(1, i+1);
        a.push_back(sum - a[0]);
    }

    sort(a.begin(), a.end());
    cout << "finish " << a[k-1] << '\n';
}
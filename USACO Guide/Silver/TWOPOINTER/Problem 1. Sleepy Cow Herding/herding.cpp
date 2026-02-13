#include <bits/stdc++.h>
using namespace std;


#define ll long long

int main() {
    freopen("herding.in", "r", stdin);
    freopen("herding.out", "w", stdout);

    int n;
    cin >> n;
    vector<int> cow(n);
    for (int i=0; i<n; i++) {
        cin >> cow[i];
    }
    sort(cow.begin(), cow.end());

    // minimum cost = n - x (where x is the maximum number of cows in a interval of size n)
    deque<int> w;
    int l = 0, r = 0;
    int x = 0;
    while (r < n) {
        while (r < n && (w.empty() || cow[r] - w.front() < n)) {
            w.push_back(cow[r++]);
        }

        if (w.back() - w.front() + 1 == n || (l > 0 && r < n))
            x = max(x, (int)w.size());
        w.pop_front();
        l++;
    }

    cout << n - x << '\n';

    x = 0;
    for (int i=0; i<n-1; i++) {
        x += cow[i+1]-cow[i]-1;
    }

    cout << x - min(cow[1]-cow[0]-1, cow[n-1]-cow[n-2]-1) << '\n';
}

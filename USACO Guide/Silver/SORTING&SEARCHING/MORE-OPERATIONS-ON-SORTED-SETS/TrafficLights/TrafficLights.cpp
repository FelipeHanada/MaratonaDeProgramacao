#include <bits/stdc++.h>
using namespace std;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int x, n;
    cin >> x >> n;
    set<int> traffic_lights;
    multiset<int> passages = {x};

    for (int i=0; i<n; i++) {
        int p;
        cin >> p;

        if (traffic_lights.find(p) != traffic_lights.end()) {
            continue;
        }

        auto upper_bound = traffic_lights.upper_bound(p);
        int right = (upper_bound == traffic_lights.end()) ? x : *upper_bound;
        int left = (upper_bound == traffic_lights.begin()) ? 0 : *(--upper_bound);

        passages.erase(passages.find(right - left));
        passages.insert(right - p);
        passages.insert(p - left);

        traffic_lights.insert(p);
        cout << *(--passages.end()) << " ";
    }
}
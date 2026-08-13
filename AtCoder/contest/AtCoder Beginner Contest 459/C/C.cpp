#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define _ ios::sync_with_stdio(0); cin.tie(nullptr);

#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
typedef tree<pair<int,int>,null_type,less<pair<int,int>>,rb_tree_tag, tree_order_statistics_node_update> indexed_set;

int main() { _
    int n, q;
    cin >> n >> q;
    vector<pair<int,int>> a(n);
    int delta = 0;

    int id = 0;
    indexed_set s;
    for (int i=0; i<n; i++) {
        a[i] = { 0, id };
        s.insert({ 0, id++ });
    }

    for (int i=0; i<q; i++) {
        int t;
        cin >> t;
        if (t == 1) {
            int x; cin >> x; x--;
            s.erase(a[x]);
            a[x] = { a[x].first + 1, id++ };
            s.insert(a[x]);
            if (s.find_by_order(0)->first - delta) delta++;
        } else {
            int y; cin >> y;
            
            cout << n - s.order_of_key({ y + delta, 0 }) << '\n';
        }
    }
}

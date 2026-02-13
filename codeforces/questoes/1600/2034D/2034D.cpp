#include <bits/stdc++.h>
using namespace std;


/*
we solve this by comparing the current state a of the vector
    with the sorted one b.

we try to fix a from the right to the left,
I) a[i] = 0 and b[i] = 1
    we simply swap i with the leftest 1 on a[j]
II) a[i] = 1 and b[i] = 2
    we simply swap i with the leftest 2
III) a[i] = 0 and b[i] = 2
    we swap i with the leftest 1 a[j]
    after, we swap i with the leftest 2 a[k]

To argument that the cost is at most n. We assign at most a single swap to each index

indexes that fall on case (I) and (II) can be assigned to i itself

case (III) is more complicated, since we have to assign 2 swaps
    one can be assigned to i itself

    let the leftest 1 and 2 are found at index j and k respectively
        the other swap can be assigned to k by the following argument:

        after swapping i with j, and i with k
        we will have a[i] = 2, a[j] = 0 and a[k] = 1
        
        although k can be swapped, it will not be marked by any other step in this process
            we can prove it by looking at two cases
        i) k is swapped before we reach k by a type II or type III(0->1) swap, k is not marked
            right now a[k] = 0, and there is only 0's on its left
        ii) we reach k
            if k is not swapped by a type II swap, b[k] cannot be equal to 2
                since all the 2's are on the right side of k
            then k does not trigger any swapping
*/

void solve() {
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    set<int> p[3];
    for (int i=0; i<n; i++) {
        cin >> a[i];
        b[i] = a[i];
        p[a[i]].insert(i);
    }
    sort(b.begin(), b.end());

    vector<pair<int, int>> ans;

    for (int i=n-1; i>=0; i--) {
        if (a[i] == 0 && b[i] == 1) {
            int j = *p[1].begin();
            swap(a[i], a[j]);
            ans.push_back({i, j});
            p[0].erase(i);
            p[1].insert(i);
            p[0].insert(j);
            p[1].erase(j);

        } else if (a[i] == 1 && b[i] == 2) {
            int j = *p[2].begin();
            swap(a[i], a[j]);
            ans.push_back({i, j});
            p[1].erase(i);
            p[2].insert(i);
            p[1].insert(j);
            p[2].erase(j);

        } else if (a[i] == 0 && b[i] == 2) {
            int j = *p[1].begin();
            swap(a[i], a[j]);
            ans.push_back({i, j});
            p[0].erase(i);
            p[1].insert(i);
            p[0].insert(j);
            p[1].erase(j);

            j = *p[2].begin();
            swap(a[i], a[j]);
            ans.push_back({i, j});
            p[1].erase(i);
            p[2].insert(i);
            p[1].insert(j);
            p[2].erase(j);
        }
    }

    cout << ans.size() << '\n';
    for (auto &[p, q] : ans) {
        cout << p+1 << ' ' << q+1 << '\n';
    }
}

    

int main() {
    #ifdef ONLINE_JUDGE
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    #endif

    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}
#include <bits/stdc++.h>
using namespace std;

#define _ ios::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);
using ll = long long;


int main() {
    int tt;
    cin >> tt;
    while (tt--) {
        int n, x;
        cin >> n >> x;
        vector<int> a(n);
        for (int i=0; i<n; i++) cin >> a[i];
        set<int> s;
        for (int i=1; i<=x; i++) s.insert(i);

        deque<int> ans;
        ans.push_back(a.front());
        for (int i=0; i<n-1; i++) {
            if (!s.empty()) {
                if (a[i] <= a[i+1]) {
                    auto lb = s.lower_bound(a[i]);
                    while (!s.empty() && lb != s.end() && *lb <= a[i+1]) {
                        ans.push_back(*lb);
                        s.erase(lb);
                        lb = s.lower_bound(a[i]);
                    }
                } else {
                    auto ub = s.upper_bound(a[i]);
                    while (!s.empty() && ub != s.begin() && *(--ub) >= a[i+1]) {
                        ans.push_back(*ub);
                        s.erase(ub);
                        ub = s.upper_bound(a[i]);
                    }
                }
            }
            ans.push_back(a[i+1]);
        }

        if (ans.front() > ans.back()) {
            reverse(ans.begin(), ans.end());
        }

        auto lb = s.lower_bound(ans.back());
        auto save = ans.back();
        while (lb != s.end()) {
            ans.push_back(*lb);
            lb++;
        }

        lb = s.lower_bound(save);
        while (lb != s.begin()) {
            lb--;
            ans.push_front(*lb);
        }

        ll cost = 0;
        for (int i=0; i<ans.size()-1; i++) {
            cost += abs(ans[i] - ans[i+1]);
        }
        cout << cost << '\n';
    }
}

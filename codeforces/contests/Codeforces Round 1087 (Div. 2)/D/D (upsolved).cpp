#include <bits/stdc++.h>
using namespace std;


#define f first
#define s second

int main() {
    int tt;
    cin >> tt;
    while (tt--) {
        int r, g, b;
        cin >> r >> g >> b;
        array<pair<int,char>,3> cnt;
        cnt[0] = {r, 'R'};
        cnt[1] = {g, 'G'};
        cnt[2] = {b, 'B'};

        deque<char> last = {-1, -1, -1};

        string ans;
        auto add = [&](int i) {
            cnt[i].f--;
            ans.push_back(cnt[i].s);
            last.pop_front();
            last.push_back(cnt[i].s);
        };

        while (1) {
            sort(cnt.rbegin(), cnt.rend());

            vector<int> cand;
            for (int i=0; i<3; i++)
                if (cnt[i].s != last[0] && cnt[i].s != last[2])
                    cand.push_back(i);

            if (!cnt[cand[0]].f) break;
            if (cand.size() == 1 || cnt[cand[0]].f > cnt[cand[1]].f) {
                add(cand[0]);
            } else {
                if (cnt[cand[0]].s == last[1]) {
                    add(cand[0]);
                } else {
                    add(cand[1]);
                }
            }
        }

        cout << ans << '\n';
    }
}

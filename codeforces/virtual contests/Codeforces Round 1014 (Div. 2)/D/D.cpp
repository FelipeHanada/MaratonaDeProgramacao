#include <bits/stdc++.h>
using namespace std;

#define ll long long

void precompute() {

}

string base = "LIT";
void solve() {
    int n; string s;
    cin >> n >> s;

    if (count(s.begin(), s.end(), s[0]) == n) {
        cout << "-1\n";
        return;
    }

    vector<int> ans;
    auto op = [&](int i) -> void {
        string z = base;
        z.erase(find(z.begin(), z.end(), s[i]));
        z.erase(find(z.begin(), z.end(), s[i+1]));
        ans.push_back(i);
        s = s.substr(0, i+1) + z[0] + s.substr(i+1);
    };

    while (true) {
        vector<pair<int, char>> cnt;
        for (char c : base) cnt.push_back(make_pair(count(s.begin(), s.end(), c), c));
        sort(cnt.begin(), cnt.end());
        if (cnt[0].first == cnt[1].first && cnt[1].first == cnt[2].first) break;

        bool done = false;
        for (int i=0; i<s.size()-1; i++) {
            if (s[i] == s[i+1]) continue;
            if (s[i] != cnt[0].second && s[i+1] != cnt[0].second) {
                op(i);
                done = true;
                break;
            }
        }

        if (done) continue;

        for (int i=0; i<s.size()-1; i++) {
            if (s[i] == s[i+1]) continue;
            if (s[i] == cnt[2].second) { // ca -0> cba -1> cbca -1> cbaca -0> cabaca
                op(i); op(i+1); op(i+1); op(i);
                break;
            } else { // ac -0> abc -1> abac -1> abcac -1> abacac
                op(i); op(i+1); op(i+1); op(i+1);
                break; 
            }
        }
    }

    cout << ans.size() << '\n';
    for (int x : ans) {
        cout << x + 1 << '\n';
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    precompute();
    int tt;
    cin >> tt;
    while (tt--) solve();    
    return 0;
}

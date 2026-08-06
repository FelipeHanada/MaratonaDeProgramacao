#include <bits/stdc++.h>
using namespace std;

string s;
void solve(set<string>& ans, string& curr, int i) {
    if (curr.size() + s.size() - i > 11) return;
    if (curr.size() == 11) {
        ans.insert(curr);
        return;
    }

    if (curr.size() == 0) {
        curr.push_back('1');
        solve(ans, curr, i + (i < s.size() && s[i] == '1'));
        curr.pop_back();

    } else if (curr.size() == 1) {
        // cant be 0
        curr.push_back('1');
        solve(ans, curr, i + (i < s.size() && s[i] == '1'));
        curr.pop_back();

        if (i < s.size() && s[i] != '1' && s[i] != '9' && s[i] != '0') {
            curr.push_back(s[i]);
            solve(ans, curr, i+1);
            curr.pop_back();
        }

        curr.push_back('9');
        solve(ans, curr, i + (i < s.size() && s[i] == '9'));
        curr.pop_back();

    } else if (curr.size() == 2) {
        curr.push_back('9');
        solve(ans, curr, i + (i < s.size() && s[i] == '9'));
        curr.pop_back();

    } else {
        curr.push_back('1');
        solve(ans, curr, i + (i < s.size() && s[i] == '1'));
        curr.pop_back();

        if (i < s.size() && s[i] != '1' && s[i] != '9') {
            curr.push_back(s[i]);
            solve(ans, curr, i+1);
            curr.pop_back();
        }

        curr.push_back('9');
        solve(ans, curr, i + (i < s.size() && s[i] == '9'));
        curr.pop_back();
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);

    cin >> s;
    set<string> ans;
    string curr;
    solve(ans, curr, 0);
    cout << ans.size() << '\n';
    for (string s : ans) {
        cout << s << '\n';
    }
}

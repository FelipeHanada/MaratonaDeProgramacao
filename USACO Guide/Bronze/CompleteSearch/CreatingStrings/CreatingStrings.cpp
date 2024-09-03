#include <bits/stdc++.h>

using namespace std;

char char_count[26] = { 0 };
string s;

void solve(const string &curr_s) {
    if (curr_s.size() == s.size()) {
        cout << curr_s << endl;
        return;
    }

    for (int i=0; i<26; i++) {
        if (char_count[i] <= 0) continue;

        char_count[i]--;
        solve(curr_s + (char) ('a' + i));
        char_count[i]++;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> s;
    int n = 1;
    for (int i=0; i<s.size(); i++) {
        char_count[s[i] - 'a']++;
        
        n *= i + 1;
        n /= char_count[s[i] - 'a'];
    }
    cout << n << endl;

    solve("");
}
#include <bits/stdc++.h>
using namespace std;

#define _ ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

using ll = long long;
#define _0 first
#define _1 second;


int main() { _
    string s, t;
    cin >> s >> t;
    vector<char> divs1, divs2;
    vector<int> segs1, segs2;
    segs1.push_back(0); segs2.push_back(0);
    for (char c : s) {
        if (c == 'A') segs1.back()++;
        else {
            segs1.push_back(0);
            divs1.push_back(c);
        }
    }

    for (char c : t) {
        if (c == 'A') segs2.back()++;
        else {
            segs2.push_back(0);
            divs2.push_back(c);
        }
    }

    if (divs1.size() != divs2.size()) {
        cout << "-1\n";
        return 0;
    }

    bool ok = 1;
    for (int i=0; ok && i<divs1.size(); i++) {
        if (divs1[i] != divs2[i]) ok = 0;
    }
    if (!ok) {
        cout << "-1\n";
        return 0;
    }

    int ans = 0;
    for (int i=0; i<segs1.size(); i++) {
        ans += abs(segs1[i] - segs2[i]);
    }

    cout << ans << '\n';
}

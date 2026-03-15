#include <bits/stdc++.h>
using namespace std;

#define _ ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

using ll = long long;
#define _0 first
#define _1 second;


int main() { _
    string s;
    cin >> s;
    const int n = s.size();
    int ans = 0;
    int used = 0;
    int a = count(s.begin(), s.end(), 'A'), c = 0;
    for (int i = n-1; i>=0; i--) {
        if (s[i] == 'A') {
            if (used) used--;
            a--;
        }
        else if (s[i] == 'C') c++;
        else if ((used < a) && c) {
            ans++;
            used++;
            c--;
        }
    }

    cout << ans << '\n';
}

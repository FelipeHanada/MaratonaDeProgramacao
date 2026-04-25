#include <bits/stdc++.h>
using namespace std;

#define _ ios::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);
using ll = long long;


string solve(int h, int w, int a, int b) {
    if (h == 2 && w == 2) {
        if (a == 1) return "RD";
        else return "DR";
    }

    string ans;
    if (a > 1) {
        for (int i=0; i<w-1; i++) ans.push_back('R');
        ans.push_back('D');
        for (int i=0; i<w-1; i++) ans.push_back('L');
        ans.push_back('D');
        return ans + solve(h-2, w, a-2, b);
    }
    if (a < h-2) {
        ans.push_back('D');
        for (int i=0; i<w-1; i++) ans.push_back('L');
        ans.push_back('D');
        for (int i=0; i<w-1; i++) ans.push_back('R');
        return solve(h-2, w, a, b) + ans;
    }
    if (b > 1) {
        for (int i=0; i<h-1; i++) ans.push_back('D');
        ans.push_back('R');
        for (int i=0; i<h-1; i++) ans.push_back('U');
        ans.push_back('R');
        return ans + solve(h, w-2, a, b-2);
    }
    if (b < w-2) {
        ans.push_back('R');
        for (int i=0; i<h-1; i++) ans.push_back('U');
        ans.push_back('R');
        for (int i=0; i<h-1; i++) ans.push_back('D');
        return solve(h, w-2, a, b) + ans;
    }

    cout << "BUG" << '\n';
}

int main() {
    int tt;
    cin >> tt;
    while (tt--) {
        int n, a, b;
        cin >> n >> a >> b;
        a--; b--;

        if ((n % 2) || !((a+b)%2)) {
            cout << "No\n";
            continue;
        }

        cout << "Yes\n";
        cout << solve(n, n, a, b) << '\n';
    }
}

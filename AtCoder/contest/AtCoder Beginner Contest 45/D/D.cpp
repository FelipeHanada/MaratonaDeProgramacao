#include <bits/stdc++.h>
using namespace std;

#define _ ios::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);
using ll = long long;


int main() {
    int tt;
    cin >> tt;

    auto norm = [&](const string a) -> string {
        string out;
        int left = 0;
        int currx = 0;
        for (char c : a) {
            if (c == 'x') {
                currx++;
            } else if (c == '(') {
                if (currx) {
                    while (left) {
                        out.push_back('(');
                        left--;
                    }
                    while (currx) {
                        out.push_back('x');
                        currx--;
                    }
                }
                left++;
            } else {
                if (left && currx == 2) {
                    left--;
                } else {
                    while (left) {
                        out.push_back('(');
                        left--;
                    }
                    while (currx) {
                        out.push_back('x');
                        currx--;
                    }
                    out.push_back(')');
                }
            }
        }

        while (left) {
            out.push_back('(');
            left--;
        }
        while (currx) {
            out.push_back('x');
            currx--;
        }

        return out;
    };

    while (tt--) {
        string a, b;
        cin >> a >> b;

        cout << (norm(a) == norm(b) ? "Yes" : "No") << '\n';
    }
}

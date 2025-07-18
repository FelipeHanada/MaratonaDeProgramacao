#include <bits/stdc++.h>
using namespace std;

using uint = unsigned int;

int bin_mod(string &a, uint b) {
    int r = 0;
    for (int i=0; i<a.size(); i++) {
        r = (2 * r + a[i] - '0') % b;
    }
    return r;
}

int main() {
    string m, n;
    cin >> m >> n;

    vector<int> mwc, nwc;
    for (int i=0; i<m.size(); i++) {
        if (m[i] == '*') mwc.push_back(i);
    }
    for (int i=0; i<n.size(); i++) {
        if (n[i] == '*') {
            nwc.push_back(i);
            n[i] = '0';
        }
    }

    uint curr_n = 0;
    int p = 1;
    for (auto it = n.rbegin(); it != n.rend(); it++) {
        if (*it - '0')
            curr_n += p;
        p <<= 1;
    }

    for (uint bitmask = 0; bitmask < (1 << (mwc.size() + nwc.size())); bitmask++) {
        for (int i=0; i<mwc.size(); i++) {
            m[mwc[i]] = (bitmask & (1 << i) ? '1' : '0');
        }

        for (int i=0; i<nwc.size(); i++) {
            char newbit = (bitmask & (1 << (i + mwc.size())) ? '1' : '0');
            if (n[nwc[i]] > newbit) {
                curr_n -= (1 << nwc[i]);
            } else if (n[nwc[i]] < newbit) {
                curr_n += (1 << nwc[i]);
            }
            n[nwc[i]] = newbit;
        }

        if (bin_mod(m, curr_n) == 0)
            break;
    }

    cout << m << '\n';
}

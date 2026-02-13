#include <bits/stdc++.h>
using namespace std;


int main() {
    int m, s;
    cin >> m >> s;

    if ((m > 1 && s == 0) || s > m*9) {
        cout << "-1 -1\n";
        return 0;
    }

    deque<int> dq;
    if (s - (m-1) * 9 > 0) dq.push_back(s - (m-1) * 9);
    else dq.push_back(min(1, s));
    for (int i=1, curr = s-dq[0]; i<m; i++) {
        int d = min(9, curr);
        dq.insert(dq.begin() + 1, d);
        curr -= d;
    }
    while (!dq.empty()) {
        cout << dq.front();
        dq.pop_front();
    }
    cout << ' ';
    for (int i=0, curr = s; i<m; i++) {
        int d = min(9, curr);
        cout << d;
        curr -= d;
    }
}

#include <bits/stdc++.h>
using namespace std;


constexpr int MAX_N = 2e5;
int n;
int t[MAX_N+1];
int ans[MAX_N+1];

int succ(int x) { return t[x]; };

void fill_path(int start, int end) {
    // fills answers with ans[end]
    int x = start, len = 0;
    while (x != end) {
        len++;
        x = succ(x);
    }

    x = start;
    while (x != end) {
        ans[x] = ans[end] + len--;
        x = succ(x);
    }
}

void floyd(int x) {
    // find all answers for this connected component using floyds algo

    int t = succ(x), h = succ(t);
    while (t != h) {
        if (ans[t] != -1) {
            fill_path(x, t);
            return;
        }

        t = succ(t);
        h = succ(succ(h));
    }

    int len = 1;
    t = succ(t);
    while (t != h) {
        len++;
        t = succ(t);
    }

    ans[t] = len;
    t = succ(t);
    while (t != h) {
        ans[t] = len;
        t = succ(t);
    }

    t = x;
    while (t != h) {
        t = succ(t);
        h = succ(h);
    }
    fill_path(x, t);
}

int main() {
    cin >> n;
    for (int i=1; i<=n; i++) {
        cin >> t[i];
    }

    fill_n(ans, n+1, -1);
    for (int i=1; i<=n; i++) {
        if (ans[i] != -1) continue;
        floyd(i);
    }

    for (int i=1; i<=n; i++) {
        cout << ans[i] << ' ';
    }
    cout << '\n';
}
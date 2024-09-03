#include <bits/stdc++.h>

using namespace std;


int main() {
    freopen("outofplace.in", "r", stdin);
    freopen("outofplace.out", "w", stdout);

    int N;
    cin >> N;

    vector<int> v;
    int ant_prev = 0, prev = 0;
    pair<int, int> bessie;
    int height;
    bool right;
    for (int i=0; i<N; i++) {
        cin >> height;
        v.push_back(height);

        if (height < prev) {
            if (height > ant_prev) {
                bessie = {i-1, prev};
                right = true;
            } else {
                bessie = {i, height};
                right = false;
            }
        }
        ant_prev = prev;
        prev = height;
    }

    int dest = 0;
    while (dest == bessie.first || (dest<N && v[dest] < bessie.second))
        dest++;
    if (right) dest--;
    
    set<int> seen;
    if (right) {
        for (int i=bessie.first; i<N && i<=dest; i++) {
            seen.insert(v[i]);
        }
    } else {
        for (int i=bessie.first; i>=0 && i>=dest; i--) {
            seen.insert(v[i]);
        }
    }

    cout << seen.size() - 1 << endl;
}
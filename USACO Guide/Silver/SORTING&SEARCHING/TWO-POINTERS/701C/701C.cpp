#include <bits/stdc++.h>
using namespace std;


int main() {
    int n;
    cin >> n;

    set<char> types;
    char flats[n];
    for (int i=0; i<n; i++) {
        cin >> flats[i];
        types.insert(flats[i]);
    }

    map<char, int> curr;
    int i=0, j=0;
    int ans = INT32_MAX;
    while (i<n) {
        if (j<n && curr.size() < types.size()) {
            curr[flats[j]]++;
            j++;
        } else {
            if (curr.size() == types.size())
                ans = min(ans, j-i);

            curr[flats[i]]--;
            if (curr[flats[i]] == 0)
                curr.erase(flats[i]);
            i++;
        }
    }

    cout << ans << '\n';
}
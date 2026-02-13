#include <bits/stdc++.h>
using namespace std;


using ll = long long;

int main() {
    int n;
    cin >> n;

    int vol = 0;
    bool playing = false;
    for (int i=0; i<n; i++) {
        int x;
        cin >> x;

        if (x == 1) {
            vol++;
        } else if (x == 2) {
            vol = max(0, vol-1);
        } else {
            playing = !playing;
        }

        if (vol >= 3 && playing) {
            cout << "Yes\n";
        } else {
            cout << "No\n";
        }
    }
}

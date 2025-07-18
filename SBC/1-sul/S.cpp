#include <bits/stdc++.h>

using namespace std;


int main() {
    int n;
    cin >> n;


    for (int i=0; i<n; i++) {
        string s;
        cin >> s;

        int best = 0;
        int curr = 0;
        for (char c : s) {
            if (
                c != 'A' && c != 'a' &&
                c != 'E' && c != 'e' &&
                c != 'I' && c != 'i' &&
                c != 'O' && c != 'o' &&
                c != 'U' && c != 'u'
            ) {
                curr++;
            } else {
                best = max(best, curr);
                curr = 0;
            }
        }
        best = max(best, curr);

        cout << s;
        if (best >= 3) {
            cout << " nao";
        }

        cout << " eh facil\n";
    }
}
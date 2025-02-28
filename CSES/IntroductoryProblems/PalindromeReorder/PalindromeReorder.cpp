#include <bits/stdc++.h>
using namespace std;


int main() {
    int chars[26];
    fill_n(chars, 26, 0);

    string s;
    cin >> s;

    for (char c : s)
        chars[c - 'A']++;

    int odd;
    int count_odd = 0;
    for (int i=0; i<26; i++) {
        if (chars[i] % 2) {
            odd = i;
            count_odd++;
        }
    }

    if (count_odd > 1) {
        cout << "NO SOLUTION\n";
        return 0;
    }

    for (int i=0; i<26; i++) {
        if (i == odd) continue;

        for (int j=0; j<chars[i]/2; j++)
            cout << (char) ('A' + i);
    }

    if (count_odd) {
        for (int i=0; i<chars[odd]; i++)
            cout << (char) ('A' + odd);
    }

    for (int i=25; i>=0; i--) {
        if (i == odd) continue;

        for (int j=0; j<chars[i]/2; j++)
            cout << (char) ('A' + i);
    }
    
    cout << "\n";
}

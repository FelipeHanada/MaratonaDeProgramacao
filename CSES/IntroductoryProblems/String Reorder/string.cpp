#include <bits/stdc++.h>
using namespace std;


int main() {
    string s;
    cin >> s;
    int n = s.size();

    deque<int> freq(26, 0);
    for (char c : s) {
        freq[c - 'A']++;
    }

    if (*max_element(freq.begin(), freq.end()) > (n+1)/2) {
        cout << "-1\n";
        return 0;
    }

    int last = -1;
    for (int i=0; i<n; i++) {
        for (int j=0; j<26; j++) {
            if (last == j || freq[j] == 0) continue;
            freq[j]--;
            if (*max_element(freq.begin(), freq.end()) > (n-i)/2) {
                freq[j]++;
                continue;
            }

            cout << (char)('A' + j);
            last = j;
            break;
        }
    }
    cout << '\n';

    // it is possible to make a string like that iff. the string with most appearance
    //  does not appear at most floor(n/2) times
}

#include <bits/stdc++.h>
using namespace std;


int main() {
    string s;
    cin >> s;
    map<char, int> conta;
    for (char c : s) {
        conta[c]++;
    }

    for (auto [c, n] : conta) {
        if (n == 1) {
            cout << c << '\n';
        }
    }
}

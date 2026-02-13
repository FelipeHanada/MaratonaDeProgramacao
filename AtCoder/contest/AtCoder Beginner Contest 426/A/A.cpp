#include <bits/stdc++.h>
using namespace std;

int main() {
    map<string, int> m = {
        {"Ocelot", 0},
        {"Serval", 1},
        {"Lynx", 2}
    };
    string a, b;
    cin >> a >> b;
    cout << (m[a] >= m[b] ? "Yes" : "No") << '\n';
}
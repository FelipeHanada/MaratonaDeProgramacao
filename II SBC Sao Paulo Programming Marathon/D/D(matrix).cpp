#include <bits/stdc++.h>
using namespace std;

constexpr int N = 128;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);

    
    int n; cin >> n;
    vector<vector<char>> data(2*n+1, vector<char>(4*n+2, ' '));

    for (int i=0; i<n+1; i++) data[0][n+i] = '_';
    for (int i=0; i<n; i++) data[n][1+i] = '_';
    for (int i=0; i<n+1; i++) data[n][3*n+1+i] = '_';
    for (int i=0; i<n+1; i++) data[2*n][2*n+1+i] = '_';

    for (int i=0; i<n; i++) data[n-i][i] = '/';
    for (int i=0; i<n; i++) data[n-i][3*n-i] = '\\';
    for (int i=0; i<n; i++) data[n+1+i][n+1+i] = '\\';
    for (int i=0; i<n; i++) data[n+1+i][4*n+1-i] = '/';

    for (int i=0; i<=2*n; i++) {
        while (data[i].back() == ' ') data[i].pop_back();
    }

    for (int i=0; i<2*n+1; i++) {
        for (char c : data[i]) cout << c;
        cout << '\n';
    }
}

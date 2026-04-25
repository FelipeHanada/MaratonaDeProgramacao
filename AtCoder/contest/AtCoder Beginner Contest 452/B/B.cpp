#include <bits/stdc++.h>
using namespace std;

#define _ ios::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);
#define f first
#define s second
using ll = long long;


int main() {
    int n, m;
    cin >> n >> m;
    for (int i=0; i<m; i++) cout << "#";
    cout << '\n';
    for (int i=1; i<n-1; i++) {
        cout << "#";
        for (int j=1; j<m-1; j++) cout << ".";
        cout << "#";
        cout << '\n';
    }
    for (int i=0; i<m; i++) cout << "#";
    cout << '\n';
}

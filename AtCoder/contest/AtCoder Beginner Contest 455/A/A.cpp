#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define _ ios::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);


int main() {
    int a, b, c;
    cin >> a >> b >> c;
    if (a != b && b == c)  {
        cout << "Yes";
    } else {
        cout <<"No";
    }
    cout << '\n';
}
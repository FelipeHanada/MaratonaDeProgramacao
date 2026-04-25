#include <bits/stdc++.h>
using namespace std;

#define _ ios::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);
#define f first
#define s second
using ll = long long;


int main() {
    int m, d;
    cin >> m >> d;
    if ((m == 1 && d == 7)
        || (m ==3 && d == 3)
        || (m == 5 && d== 5)
        || (m == 7 && d == 7)
        || (m == 9 && d == 9)
    ) {
        cout << "Yes\n";
    } else {
        cout << "No\n";
    }
}

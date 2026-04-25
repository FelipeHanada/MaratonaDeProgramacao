#include <bits/stdc++.h>
using namespace std;

#define _ ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using ll = long long;

int main() { _
    int tt;
    cin >> tt;
    while (tt--) {
        int n, m;
        cin >> n >> m;
        vector<int> a(n);
        for (int i=0; i<n; i++) cin >> a[i];

        bool ok = 1;
        int last = -1;
        int curr = 0;
        for (int i=0; i<n; i++) {
            if (a[i] == last) curr++;
            else {
                if (curr >= m) ok = 0;
                curr = 1;
            }
            last = a[i];
        }
        if (curr >= m) ok = 0;


        cout << (ok ? "YES" : "NO") << '\n';
    }
}

/*

1* 1 1 1 1 
2 2* 2 2 2 
3 3 3* 3 3 
4 4 4 4* 4 
0 0 0 0 0

1* 1 1
2 2* 2
0 0 0



4* 3 2 1 0 0
0 4* 3 2 1 1
1 0 4* 3 2 2
2 1 0 4* 3 3
3 2 1 0 4* 4
4 3 2 1* 0 0
0 4 3 2 1* 1
1 0 4 3 2 2*


1* 1 2 2 1 1 2 2 
2 2* 0 0 2 2 0 0 
0 0 1* 1 0 0 1 1
1 1 2 2* 1 1 2 2
2 2 0 0 2* 2 0 0
0 0 1 1* 0 0 1 1
1 1 2 2 1* 1 2 2
2 2 0 0 2 2* 0 0
0 0 1 1 0 0 1* 1
1 1 2 2 1 1 2 2*
*/

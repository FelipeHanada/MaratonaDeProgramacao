#include <bits/stdc++.h>
using namespace std;


int main() {
    int tt;
    cin >> tt;
    while (tt--) {
        int n, m, l;
        cin >> n >> m >> l;
        queue<int> a;
        for (int i=0; i<n; i++) {
            int x;
            cin >> x;
            a.push(x);
        }
        vector<int> b(m, 0);
        
        for (int i=1; i<=l; i++) {
            b[min(m-1, int(a.size()))]++;
            sort(b.rbegin(), b.rend());
            
            if (!a.empty() && a.front() == i) {
                a.pop();
                b[0] = 0;
                sort(b.rbegin(), b.rend());
            }
        }
    
        cout << b[0] << '\n';
    }
}
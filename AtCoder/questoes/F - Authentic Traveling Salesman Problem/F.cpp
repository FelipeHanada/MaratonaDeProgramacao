#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int B = sqrt(2e10);

int main() {
    int n; cin >> n;
    vector<vector<pair<int, int>>> a(B);
    for (int i=0; i<n; i++) {
        int x, y; cin >> x >> y;
        a[min(x/B, B-1)].push_back({y, i});
    }

    for (int i=0; i<B; i++) sort(a[i].begin(), a[i].end());

    int id = 0;
    vector<int> ans(n);
    for (int i=0; i<B; i++) {
        if (i & 1) {
            for (int j=a[i].size()-1; j>=0; j--) {
                ans[id++] = a[i][j].second;
            }
        } else {
            for (int j=0; j<a[i].size(); j++) {
                ans[id++] = a[i][j].second;
            }
        }
    }

    int start;
    for (int i=0; i<n; i++) if (ans[i] == 0) start = i;

    for (int i=start; i<n; i++) cout << ans[i] + 1 << ' ';
    for (int i=0; i<start; i++) cout << ans[i] + 1 << ' ';
    cout << '\n';
}

/*
let split the plane in width/B vertical rectangles
    each rectangle is B x height

lets traverse the plane rectangle by rectangle
    by points ordered by y

    for the ith rectangle we go:
    a. upwards (if i is odd)
    b. downwards (else)

in the worst case:
    1. width/B * height                 (upward/downward movement)
    2. (n-1) * B                        (zig-zag movement inside rectangle)
    3. 2 * B * (width/B - 1)            (transition between rectangles)
    4. width + height                   (going back to the first point)

(1) <= 2*10^7/B * 2*10^7
(2) <= 2*10^4 * B
(3) <= 2 * B * width/B = 2 * 2*10^7 = 4*10^7
(4) <= 4*10^7

(1) + (2) + (3) + (4)
<= 4*10^14/B + 2*10^4*B + 8*10^7

queremos a expressão,
    basta minimizar 4*10^14/B + 2*10^4*B

seja x = 4*10^14/B e y = 2*10^4*B
    x * y = constante
    logo, x + y é minimizado quando x = y

temos 4*10^14/B = 2*10^4*B
    B*B = 4*10^14/2*10^4 = 2*10^10
    B = sqrt(2*10^10)



*/

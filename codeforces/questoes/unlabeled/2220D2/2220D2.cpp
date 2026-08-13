#include <bits/stdc++.h>
using namespace std;


int query(int l, int r) {
    if (r - l == 1) return 1;
    cout << "? " << r - l << ' ';
    for (int i=l; i<r; i++) cout << i + 1 << '\n';
    cout << '\n';
    int ans; cin >> ans;
    return ans;
}

int n;
int one, two, three;
int solve1() {
    int l = 0, r = 2*n+1;
    while (r - l > 1) {
        int mid = (l + r) / 2;
        int query_l = query(l, mid),
            query_r = query(mid, r);
        
    }
}
int solve2() {

}
int solve3() {

}

int main() {
    int tt; cin >> tt;
    while (tt--) {
        cin >> n;
        one = solve1();
        two = solve2();
        three = solve3();
    }
}

/*
let split the numbers in half

(...) | (...)

for every pair, it contributes the same for both halves
for the triple, two cases can occur
    I) 3 | 0 (contributes 1 to the side with 3 copies)
    II) 2 | 1 (contributes 1 to the side with 1 copy)

I) 2 | 0
II) 1 | 1


n      n+1
1 1 1 | X X X X
1       0

n         n+1
1 1 1 X | X X X X X
2        1


1 1 2 2 | 1 3 3 4 4
1 1 2 2 | 1 3 3


0 | 3 => - +(mesma paridade do tamanho)
1 | 2 => + -
2 | 1 => - +
3 | 0 => +(par) -


at first glance I and II are indistinguishable
    but since (I) uses 3 spaces


1 1 2 3 4 | 2 3 4 5 5


1 1 1 2 3 4 | 2 3 4 5 5
4 - 3

1 2 3 4 | 1 1 2 3 4
4 - 3

*/

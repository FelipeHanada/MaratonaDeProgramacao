#include <bits/stdc++.h>
using namespace std;


int main() {
    int n; cin >> n;
    vector<int> a(n);
    for (int i=0; i<n; i++) cin >> a[i];


}


/*
toda solução é mapeada para duas seq.
X = { x1, x2, x3, ..., xi, ..., xa }
Y = ...
crescentes tal que x1, x2, x3, ..., são elementos de P e Xi sempre ocorre antes de Xi+1 em P
    (o mesmo pro Y) e X e Y são disjuntos



dp naive faz em O(N^2) o que não passa

1 6 2 7 3 8 4 9 5 10
1 6 7 8 9 10
2 3 4 5


*/


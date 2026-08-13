#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int n, m;
int add(int a, int b) {
    a += b;
    if (a >= m) a -= m;
    return a;
}
int mult(int a, int b) {
    return (ll(a) * b) % md;
}


int main() {
    cin >> n >> m;

    int f = 0;
    int ans = 0;
    for (int i=1; i<=n; i++) {

    }
}

/*
number of permutations of size k
    s.t. no pi = i forall i

we can compute easily the number of permutations of size k (k!)
if we can compute the number of permutations of size k
    s.t. some pi = i
then the answer is simply the difference

we can use the principle of inclusion exclusion



*/

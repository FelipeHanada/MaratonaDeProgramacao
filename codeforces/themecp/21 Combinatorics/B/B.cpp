#include <bits/stdc++.h>
using namespace std;


using ll = long long;

int main() {
#ifdef ONLINE_JUDGE
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
#endif

    int n;
    cin >> n;
    vector<int> a(n);
    for (int i=0; i<n; i++) {
        cin >> a[i];
        a[i] /= abs(a[i]);
    }

    vector<int> prefix(n+1);
    ll pos = 1, neg = 0;
    prefix[0] = 1;
    for (int i=1; i<=n; i++) {
        prefix[i] = prefix[i-1] * a[i-1];
        if (prefix[i] > 0) pos++;
        else neg++;
    }

    cout << (pos * neg) << ' ';
    cout << (pos*(pos-1)/2) + (neg*(neg-1)/2) << '\n';
}

/*
positivo é pos / pos ou neg / neg

negativo é pos / neg

*/

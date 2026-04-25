#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int recur(ll r, int maxS, ll s){
    int newS = ceil((ll)maxS/s) - 1;
    if(r-1 > 0 && (r-1) > newS){
        return recur(r-maxS-1, newS, s);
    }
    else{
        int minS = newS - (r-1) + ceil((r-1)/s);
        return minS;
    }
}


int main() {
    ll tt;
    cin >> tt;
    while (tt--) {
        ll c, s, r;
        cin >> c >> r >> s;

        int ans1;
        ll rr = r % s;
        if (rr) ans1 = c / s;
        else ans1 = (c + s - 1) / s;
        // cout << (max(0LL, (c-r*(s-1))) + s - 1) / s << '\n';

        cout << ans1 << ' ';


        int ans2;
        if (ans1 >= r){
            ans2 = ans1 - r + ceil(r/s);
        }
        else{
            ans2 = recur(r, ans1, s);
        }

        cout << ans2 << ' ';




        // if (r >= (c+s-2)/(s-1)) {
        //     cout << "0\n";
        // } else {
        //     cout << (c + r + s - 1)/s - r << '\n';
        // }


        // int tot = c + r;
        // int spoon = (tot + s - 1) / s;

        // if (spoon <= r) {
        //     int ans2 = 0;
        //     int maxs = ans1;
        //     while (maxs <= r) {
        //         ans2 = maxs / s
        //     }
        //     cout << ans1 / s << '\n';
        // } else {
        //     cout << ans1 - r + (r+spoon-1)/spoon << '\n';
        // }
    }
}
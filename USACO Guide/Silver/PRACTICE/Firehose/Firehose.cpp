#include <bits/stdc++.h>
using namespace std;


constexpr int MAX_H = 1000000;
int h, k;
int houses[MAX_H];

bool check(int d) {
    /*
    check if it is possible to arrange k hydrants 
    so that the maximum length of hose required to
    connect a house to a fire hydrant is as small
    as possible is <= d

    we can greedily get a good arrangement by sorting the houses
    and choosing an initial house. (we need to test for every house)
    then we place a hydrant at the rightmost position
    that satisfies the distance d, we proceed this until
    there is no more hydrants or no more houses
    */

    for (int i=0; i<h; i++) {
        int needed = 0;
        int start = houses[i];
        for (int j=1; j<h; j++) {
            int end = houses[(i+j)%h];
            int dist = (end-start+MAX_H)%MAX_H;
            if (dist > d * 2) {
                // a hydrant at the position start+d will not suffice to satisfy this house
                start = end;
                needed++;
            }
        }
        needed++;

        if (needed <= k) return true;
    }

    return false;
}


int main() {
    cin >> h;
    for (int i=0; i<h; i++) {
        cin >> houses[i];
    }
    sort(houses, houses+h);
    cin >> k;

    int low = -1, high = MAX_H;
    while (high - low > 1) {
        int mid = (low + high) / 2;
        if (!check(mid)) {
            low = mid;
        } else {
            high = mid;
        }
    }

    cout << high << '\n';
}
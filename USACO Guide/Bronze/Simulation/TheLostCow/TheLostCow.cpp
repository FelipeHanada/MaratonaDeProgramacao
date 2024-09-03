#include <bits/stdc++.h>

using namespace std;


int main() {
    freopen("lostcow.in", "r", stdin);
    freopen("lostcow.out", "w", stdout);

    int x, y;
    cin >> x >> y;

    int travel_dist = 1;
    int total_traveled_dist = 0;

    while (true) {
        total_traveled_dist += abs(travel_dist);
        if (min(x, x + travel_dist) <= y && y <= max(x, x + travel_dist)) break;
        total_traveled_dist += abs(travel_dist); // nao encontrou a vaca, volta para a x0

        travel_dist *= -2;
    }

    total_traveled_dist -= abs(x + travel_dist - y);

    cout << total_traveled_dist << endl;
}

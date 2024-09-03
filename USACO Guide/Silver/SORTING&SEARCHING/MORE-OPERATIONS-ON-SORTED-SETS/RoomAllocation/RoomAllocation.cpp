#include <bits/stdc++.h>
using namespace std;


int main() {
    int n;
    cin >> n;

    vector<tuple<int, int, int>> customers;
    for (int i=0; i<n; i++) {
        int arrival, departure;
        cin >> arrival >> departure;
        customers.push_back({arrival, departure, i});
    }
    sort(customers.begin(), customers.end());

    int ans[n];
    priority_queue<pair<int, int>> rooms;
    int last_room = 0;
    for (auto customer : customers) {
        if (rooms.empty()) {
            // first customer case
            last_room++;
            rooms.emplace(make_pair(-get<1>(customer), last_room));
            ans[get<2>(customer)] = last_room;
        } else {
            auto minimum = rooms.top(); // first customer to departure
            if (-minimum.first < get<0>(customer)) {
                // customer arrives after the departure
                rooms.pop();
                rooms.push(make_pair(-get<1>(customer), minimum.second));
                ans[get<2>(customer)] = minimum.second;
            } else {
                // customer arrives before the departure
                // customer needs another room
                last_room++;
                rooms.push(make_pair(-get<1>(customer), last_room));
                ans[get<2>(customer)] = last_room;
            }
        }
    }

    cout << last_room << endl;
    for (int i=0; i<n; i++) {
        cout << ans[i] << " ";
    }
    cout << endl;
}

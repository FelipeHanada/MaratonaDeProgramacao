#include <bits/stdc++.h>
using namespace std;


struct Event {
    int t;
    int cow;
    bool start;

    friend bool operator<(const Event &x, const Event &y) {
        return x.t < y.t;
    }
};

int main() {
    freopen("lifeguards.in", "r", stdin);
    freopen("lifeguards.out", "w", stdout);

    int n;
    cin >> n;

    vector<Event> events;
    for (int i=0; i<n; i++) {
        int a, b;
        cin >> a >> b;
        events.push_back({a, i, true});
        events.push_back({b, i, false});
    }
    sort(events.begin(), events.end());

    vector<int> alone_time(n, 0);
    set<int> cows_in_shift;
    int last_event_t;
    int total_time = 0;
    for (Event e : events) {
        if (cows_in_shift.size() >= 1) {
            int delta_time = e.t - last_event_t;
            if (cows_in_shift.size() == 1) {
                alone_time[*cows_in_shift.begin()] += delta_time;
            }

            total_time += delta_time;
        }

        if (e.start) {
            cows_in_shift.emplace(e.cow);
        } else {            
            cows_in_shift.erase(e.cow);
        }

        last_event_t = e.t;
    }

    int min_alone_time = *min_element(alone_time.begin(), alone_time.end());

    cout << total_time - min_alone_time << endl;
}

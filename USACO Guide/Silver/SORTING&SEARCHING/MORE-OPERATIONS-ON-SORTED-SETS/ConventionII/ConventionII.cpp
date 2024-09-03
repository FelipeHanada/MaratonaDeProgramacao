#include <bits/stdc++.h>
using namespace std;

typedef tuple<int, int, int> cow;


int main() {
    freopen("convention2.in", "r", stdin);
    freopen("convention2.out", "w", stdout);

    int n;
    cin >> n;

    vector<cow> cows;
    // arrival, time eating, seniority
    for (int i=0; i<n; i++) {
        int a, t;
        cin >> a >> t;
        cows.push_back({a, t, i});
    }
    sort(cows.begin(), cows.end());

    auto cmp = [](const cow &c1, const cow &c2) {
        return get<2>(c1) > get<2>(c2);
    };
    priority_queue<cow, vector<cow>, bool (*)(const cow &, const cow &)> cow_queue(cmp);
    // ordered in seniority
    
    int current_t = get<0>(cows[0]);
    auto current_cow = cows.begin();

    int longest_wait = 0;
    while (cow_queue.size() > 0 || current_cow != cows.end()) {
        if (cow_queue.size() > 0) {
            cow first_cow = cow_queue.top();
            cow_queue.pop();
            longest_wait = max(longest_wait, current_t - get<0>(first_cow));
            current_t += get<1>(first_cow);
        } else {
            current_t = get<0>(*current_cow) + get<1>(*current_cow);
            current_cow++;
        }

        while (current_cow != cows.end() && get<0>(*current_cow) <= current_t) {
            cow_queue.emplace(*current_cow);
            current_cow++;
        }
    }

    cout << longest_wait << endl;
}

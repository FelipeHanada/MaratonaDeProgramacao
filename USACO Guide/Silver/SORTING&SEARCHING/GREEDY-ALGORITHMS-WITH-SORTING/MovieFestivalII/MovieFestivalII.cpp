#include <bits/stdc++.h>
using namespace std;


int main() {
    int n, k;
    cin >> n >> k;

    vector<pair<int, int>> movies;
    for (int i=0; i<n; i++) {
        int a, b;
        cin >> a >> b;
        movies.push_back({a, b});
    }
    auto cmp = [&] (const pair<int, int> &x, const pair<int, int> &y) {
        return x.second < y.second;
    };
    sort(movies.begin(), movies.end(), cmp);

    map<int, int> members;
    members.insert({0, k});
    
    int watched = 0;
    for (auto movie : movies) {
        auto ub = members.upper_bound(movie.first);
        if (ub != members.begin()) {
            auto free_member = prev(ub);
            free_member->second--;
            if (free_member->second <= 0) {
                members.erase(free_member);
            }

            if (members.find(movie.second) == members.end()) {
                members.insert({movie.second, 0});
            }
            members[movie.second]++;
            watched++;
        }
    }

    cout << watched << endl;
}
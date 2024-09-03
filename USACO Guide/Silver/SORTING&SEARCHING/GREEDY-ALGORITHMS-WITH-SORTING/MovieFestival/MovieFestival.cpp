#include <bits/stdc++.h>
using namespace std;


int main() {
    int n;
    cin >> n;

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

    int watched = 0;
    int last_end = 0;
    for (auto movie : movies) {
        if (movie.first >= last_end) {
            watched++;
            last_end = movie.second;
        }
    }

    cout << watched << endl;
}

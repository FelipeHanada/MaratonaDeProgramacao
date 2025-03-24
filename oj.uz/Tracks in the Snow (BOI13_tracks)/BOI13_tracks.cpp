#include <bits/stdc++.h>
using namespace std;

char grid[4000][4000];
int h, w;
vector<pair<int, int>> border;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> h >> w;

    for (int i=0; i<h; i++) {
        for (int j=0; j<w; j++) {
            cin >> grid[i][j];
        }
    }

    border.push_back({0, 0});
    char animal = grid[0][0];
    char other = ((animal == 'R') ? 'F' : 'R');
    int ans = 0;
    while (!border.empty()) {
        ans++;
        queue<pair<int, int>> q;
        while (!border.empty()) {
            q.push(border.back());
            border.pop_back();
        }

        while (!q.empty()) {
            pair<int, int> curr = q.front(); q.pop();

            if (grid[curr.first][curr.second] != animal) {
                if (grid[curr.first][curr.second] == other) {
                    border.push_back(curr);
                }
                continue;
            }

            grid[curr.first][curr.second] = '*';
            if (curr.first > 0) q.emplace((pair<int, int>){curr.first - 1, curr.second});
            if (curr.first < h - 1) q.emplace((pair<int, int>){curr.first + 1, curr.second});
            if (curr.second > 0) q.emplace((pair<int, int>){curr.first, curr.second - 1});
            if (curr.second < w - 1) q.emplace((pair<int, int>){curr.first, curr.second + 1});
        }

        tie(animal, other) = make_tuple(other, animal);
    }

    cout << ans << "\n";
}

#include <bits/stdc++.h>
using namespace std;


constexpr int MAX_N = 50, MAX_M = 50;
char maze[MAX_N][MAX_M];
bool seen[MAX_N][MAX_M];
int n, m;

bool place_wall(int i, int j) {
    if (i < 0 || i >= n || j < 0 || j >= m) {
        return true;
    }

    if (maze[i][j] == 'G') {
        return false;
    }
    if (maze[i][j] != 'B') {
        maze[i][j] = '#';
    }
    return true;
}

int main() {
    int t; cin >> t;
    for (int test=0; test<t; test++) {
        cin >> n >> m;

        int good_people = 0;
        vector<pair<int, int>> bad_people;

        for (int i=0; i<n; i++) {
            for (int j=0; j<m; j++) {
                char c;    
                cin >> c;

                switch (c) {
                    case 'G':
                        good_people++;
                        break;
                    case 'B':
                        bad_people.push_back({i, j});
                }
                maze[i][j] = c;
                seen[i][j] = false;
            }
        }

        // tries to block bad people
        bool valid_wall_placement = true;
        for (auto bad_person : bad_people) {
            int i = bad_person.first;
            int j = bad_person.second;
            if (!(
                place_wall(i-1, j) &&
                place_wall(i+1, j) &&
                place_wall(i, j-1) &&
                place_wall(i, j+1)
            )) {
                valid_wall_placement = false;
                break;
            }
        }
        if (!valid_wall_placement) {
            cout << "NO" << endl;
            continue;
        }

        // search good people by the exit
        int can_exit = 0;
        stack<pair<int, int>> ff;
        ff.emplace(make_pair(n-1, m-1));
        while (ff.size() > 0) {
            pair<int, int> curr = ff.top(); ff.pop();
            int i = curr.first, j = curr.second;
            
            if (i < 0 || i >= n || j < 0 || j >= m) {
                continue;
            }
            if (seen[i][j] || maze[i][j] == '#') {
                continue;
            }
            if (maze[i][j] == 'G') {
                can_exit++;
            }

            seen[i][j] = true;
            ff.emplace(make_pair(i-1, j));
            ff.emplace(make_pair(i+1, j));
            ff.emplace(make_pair(i, j-1));
            ff.emplace(make_pair(i, j+1));
        }

        cout << ((can_exit == good_people) ? "YES" : "NO") << endl;
    }
}

#include <bits/stdc++.h>

using namespace std;

int solve(vector<pair<int, int>> queen_positions, set<pair<int, int>> reserved_positions) {
    

    int p_ways = 0;
    for (pair<int, int> queen_pos : free_positions) {

        set<pair<int, int>> f_positions;
        
        for (const pair<int, int> free_position : free_positions) {
            if (
                free_position.first != queen_pos.first &&
                free_position.second != queen_pos.second &&
                free_position.first + free_position.second != queen_pos.first + queen_pos.second &&
                free_position.first - free_position.second != queen_pos.first - queen_pos.second
            ) {
                f_positions.insert(free_position);
            }
        }

        p_ways += solve(f_positions, n-1);
    }

    return p_ways;
}

int main() {
    set<pair<int, int>> free_positions;
    char c;
    for (int i=0; i<8; i++) {
        for (int j=0; j<8; j++) {
            cin >> c;
            if (c == '.') free_positions.insert({i, j});
        }
    }

    cout << solve(free_positions, 8) << endl;
}

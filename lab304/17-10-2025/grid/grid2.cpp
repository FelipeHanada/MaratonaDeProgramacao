#include <bits/stdc++.h>
using namespace std;
#define uint unsigned int
 
array<char, 48> s;
array<char, 48> path;
array<bool, 81> visited = {
    1, 1, 1, 1, 1, 1, 1, 1, 1,
    1, 0, 0, 0, 0, 0, 0, 0, 1,
    1, 0, 0, 0, 0, 0, 0, 0, 1,
    1, 0, 0, 0, 0, 0, 0, 0, 1,
    1, 0, 0, 0, 0, 0, 0, 0, 1,
    1, 0, 0, 0, 0, 0, 0, 0, 1,
    1, 0, 0, 0, 0, 0, 0, 0, 1,
    1, 0, 0, 0, 0, 0, 0, 0, 1,
    1, 1, 1, 1, 1, 1, 1, 1, 1
};
 
vector<int> codes = {'R', 'L', 'D', 'U'};
map<char, uint> mcodes = {{'R', 1}, {'L', 2}, {'D', 4}, {'U', 8}};
vector<pair<int, int>> moves = {{+1, 0}, {-1, 0}, {0, +1}, {0, -1}};
 
long long debug_visited = 0;
long long debug1 = 0, debug2 = 0;
 
int solve(array<char, 48> &path, int n, array<bool, 81> &visited, int pos) {
    if (n == 48) return 1;
 
    // check for bottom-left corner
    if (pos == 64 && n < 48)
        return 0;
 
    // check for split
    if (visited[pos + 1] && visited[pos - 1] &&
        !visited[pos + 9] && !visited[pos - 9]) {
            debug1++;
            return 0;
        }
    if (!visited[pos + 1] && !visited[pos - 1] &&
        visited[pos + 9] && visited[pos - 9]) {
            debug2++;
            return 0;
        }
 
    uint mcode = 0;
    if (s[n] == '?') {
        mcode = 15;  // 1111
    } else {
        mcode = mcodes[s[n]];
    }
 
    visited[pos] = true;
    debug_visited++;
    int ans = 0;
    for (int i=0; i<4; i++) {
        if (!(mcode & (1 << i))) continue;
 
        pair<int, int> move = moves[i];
        int newpos = pos + move.first + move.second * 9;
 
        if (visited[newpos])
            continue;
 
        // checks for deadend
        // bool deadend = false;
        // for (int j=0; j<4; j++) {
        //     move = moves[j];
        //     int deadend = pos + move.first + move.second * 9;
        //     if (visited[deadend] || deadend == 64) continue;
        //     int x = 1;
        //     for (int k=0; k<4; k++) {
        //         move = moves[k];
        //         if (visited[deadend + move.first + move.second * 9])
        //             x++;
        //     }
        //     if (x >= 3) {
        //         deadend = true;
        //         break;
        //     }
        // }
        // if (deadend)
        //     continue;
        
        path[n] = codes[i];
        ans += solve(path, n + 1, visited, newpos);
    }
    visited[pos] = false;
 
    return ans;
}
 
int main() {
    for (int i=0; i<48; i++) {
        cin >> s[i];
    }
 
    int ans = solve(path, 0, visited, 10);
    cout << ans << "\n";
    cout << debug_visited << '\n';
    cout << debug1 << ' ' << debug2 << '\n';
}
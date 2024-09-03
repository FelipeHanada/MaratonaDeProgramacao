#include <bits/stdc++.h>

using namespace std;

bool check_solution(set<pair<int, int>> reserved_positions, int *perm) {
    // check reserved squares
    for (int x=0; x<8; x++) {
        int y = perm[x];
        if (reserved_positions.find({x, y}) != reserved_positions.end())
            return false;
    }

    // check diagonal squares
    for (int x1=0; x1<8; x1++) {
        for (int x2=x1+1; x2<8; x2++) {
            int y1 = perm[x1], y2 = perm[x2];
            if (x1+y1 == x2+y2 || x1-y1 == x2-y2) return false;
        }
    }

    return true;
}


int main() {
    set<pair<int, int>> reserved_positions;
    
    char c;
    for (int i=0; i<8; i++) {
        for (int j=0; j<8; j++) {
            cin >> c;
            if (c == '*') reserved_positions.insert({i, j});
        }
    }

    int q_positions[8] = {0, 1, 2, 3, 4, 5, 6, 7};

    int count = 0;
    do {
        if (check_solution(reserved_positions, q_positions)) count++;
    } while (next_permutation(q_positions, q_positions + 8));

    cout << count << endl;
}

#include <bits/stdc++.h>
using namespace std;


int k;
array<int, 10> groups;

void make_move(string s) {
    cout << "next ";
    for (int i=0; i<s.size()-1; i++) {
        cout << s[i] << " ";
    }
    cout << s[s.size()-1] << endl;

    cin >> k;
    string g;
    for (int i=0; i<k; i++) {
        cin >> g;
        for (char c : g) {
            groups[c - '0'] = i;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // floyd's turtle and hare algorithm
    make_move("01");
    make_move("1");
    while (groups[0] != groups[1]) {
        make_move("01");
        make_move("1");
    }

    while (groups[0] != groups[9]) {
        make_move("0123456789");
    }

    cout << "done" << endl;
}

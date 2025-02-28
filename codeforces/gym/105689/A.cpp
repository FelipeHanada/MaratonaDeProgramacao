#include <bits/stdc++.h>
using namespace std;


string solve(string s) {    
    char side = 'N';
    if (*(s.end() - 1) > 'A') {
        side = *(s.end() - 1);
        s.erase(s.end() - 1);
    }
    int p = atoi(s.c_str());

    if (side == 'N') {
        if (p == 0) return "New moon";
        return "Full moon";
    }

    stringstream ss;
    if (p == 50) {
        ss << ((side == 'R') ? "First" : "Third") << " quarter";
    } else {
        ss << ((side == 'R') ? "Waxing" : "Waning") << " ";
        if (p < 50) ss << "crescent";
        else ss << "gibbous";
    }

    return ss.str();
}

int main() {
    string s;
    cin >> s;

    cout << solve(s) << "\n";
}

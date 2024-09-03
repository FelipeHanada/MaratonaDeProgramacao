#include <bits/stdc++.h>
using namespace std;


int main() {
    string bitstring;
    cin >> bitstring;

    set<int> split_bits = {0, (int) bitstring.size()};
    for (int i=1; i<bitstring.size(); i++) {
        if (bitstring[i] != bitstring[i-1]) {
            split_bits.insert(i);
        }
    }
    multiset<int> intervals;
    for (auto it = split_bits.begin(); it != next(split_bits.end()); it++) {
        intervals.insert(*next(it) - *it);
    }


    int m;
    cin >> m;
    for (int i=0; i<m; i++) {
        int x;
        cin >> x;
        x--;
        
        if (split_bits.find(x) != split_bits.end()) {

        }
    }
    
}

#include <bits/stdc++.h>
using namespace std;


int main() {
    unordered_set<int> s;
    int x;
    for (int i=0; i<10; i++) {
        cin >> x;
        s.insert(x);
    }
    cout << 4 - s.size() << '\n';
}

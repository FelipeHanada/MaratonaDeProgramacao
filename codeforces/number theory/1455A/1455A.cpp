#include <bits/stdc++.h>
using namespace std;


int main() {
    // f(f(x)) removes trailing zeros
    // g(x) = x/f(f(x)) gives power of ten's
    // the first x to give different values of g(x) are
    // g(1) = 1
    // g(10) = 10
    // g(100) = 100
    // ...

    int t;
    cin >> t;
    
    string s;
    for (int i=0; i<t; i++) {
        cin >> s;
        cout << s.size() << "\n";
    }
}

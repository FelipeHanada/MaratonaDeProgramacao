#include <bits/stdc++.h>
using namespace std;


tuple<int, int, int> func() {
    return make_tuple(1, 2, 3);
}

void func2(int& a, int& b, int& c) {
    a = 3;
    b = 2;
    c = 1;
}

int main() {
    int a, b, c;

    tie(a, b, c) = func();
    cout << a << ' ' << b << ' ' << c << '\n';
    
    func2(a, b, c);
    cout << a << ' ' << b << ' ' << c << '\n';
}
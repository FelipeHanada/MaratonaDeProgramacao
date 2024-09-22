#include <bits/stdc++.h>
using namespace std;


int lcm(int a, int b) {
    return a / gcd(a, b) * b;
}

int main() {
    cout << lcm(1, 10) << endl;
    cout << lcm(2, 10) << endl;
    cout << lcm(5, 10) << endl;
    cout << lcm(7, 10) << endl;
}

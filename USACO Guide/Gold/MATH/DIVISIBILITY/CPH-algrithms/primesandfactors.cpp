#include <bits/stdc++.h>
using namespace std;


int main() {
    int n;
    cin >> n;
    
    map<int, int> factors; 
    for (int x = 2; x*x<=n; x++) {
        if (n % x == 0)
            factors.insert({x, 0});
        while (n % x == 0) {
            factors[x]++;
            n /= x;
        }
    }
    if (n > 1) {
        if (factors.find(n) == factors.end())
            factors.insert({n, 0});
        factors[n]++;
    }

    int q = 1, sum = 1;
    for (auto i : factors) {
        q *= i.second + 1;
        sum *= (pow(i.first, i.second + 1) - 1) / (i.first  - 1);
    }
    int prod = pow(n, q / 2);

    cout << "number of factors: " << q << "\n";
    cout << "sum of factors: " << sum << "\n";
    cout << "product of factors: " << prod << "\n";
}
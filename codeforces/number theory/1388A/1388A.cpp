#include <bits/stdc++.h>
using namespace std;


int main() {
    int t, n;
    cin >> t;
    
    for (int i=0; i<t; i++) {
        cin >> n;
        // the task is equivalent to find atleast 3 nearly primes number lower that sum lower than n
        // the first 3 nearly prime numbers are 6, 10, 14
        // then the minimum number that they sum are 30
        // therefore all number <= 30 (except 36, 40 and 44) can be expressed as 6 + 10 + 14 + x
        // 36 = 6 + 10 + 15 + 5
        // 40 = 6 + 10 + 15 + 9
        // 44 = 6 + 10 + 15 + 13

        if (n <= 30) {
            cout << "NO\n";
            continue;
        } 

        cout << "YES\n";
        if (n == 36 || n == 40 || n == 44) {
            cout << "6 10 15 " << n - 31 << "\n";
        } else {
            cout << "6 10 14 " << n - 30 << "\n";
        }
    }
}
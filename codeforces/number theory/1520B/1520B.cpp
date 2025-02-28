#include <bits/stdc++.h>
using namespace std;


int solve(int n) {
    vector<int> digits;
    while (n) {
        digits.push_back(n % 10);
        n /= 10;
    }

    int b = digits.size();
    int first_d = digits.back();
    bool incr = true;
    for (int i=b-2; i>=0 && incr && digits[i] <= first_d; i--) {
        if (digits[i] < first_d)
            incr = false;
    }

    return first_d - 1 + ((incr) ? 1 : 0) + 9*(b-1);
}

int main() {
    int t;
    cin >> t;

    for (int i=0; i<t; i++) {
        int n;
        cin >> n;
        cout << solve(n) << "\n";
    }
}
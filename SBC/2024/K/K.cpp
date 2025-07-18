#include <bits/stdc++.h>
using namespace std;


int main() {
    int n;
    cin >> n;

    int sum = 0;
    vector<int> a(n);
    for (int i=0; i<n; i++) {
        cin >> a[i];
        sum += a[i];
    }

    int half = sum / 2; 

    vector<int> dp(1 + half, -1);
    
    // dp[i] = last element added to add i (-1 if it is not possible)
    for (int i=0; i<a.size(); i++) {
        dp[a[i]] = i;

        for (int j=half; j>=a[i]; j--) {
            if (dp[j] >= 0) continue;
            
            if (dp[j - a[i]] >= 0) {
                dp[j] = i;
            }
        }
    }

    if (dp[half] == -1) {
        cout << "-1\n";
    } else {
        set<int> alice;
        for (int curr=half; curr > 0; curr = curr - a[dp[curr]])
            alice.insert(dp[curr]);
        
        vector<int> bob;
        for (int i=0; i<n; i++) {
            if (alice.find(i) == alice.end())
                bob.push_back(i);
        }

        int alice_sum = 0, bob_sum = 0;
        while (!alice.empty() || !bob.empty()) {
            int x;
            
            if (alice_sum < bob_sum) {
                x = a[(*alice.begin())];
                alice.erase(alice.begin());
                alice_sum += x;
            } else {
                x = a[bob.back()];
                bob.pop_back();
                bob_sum += x;
            }

            cout << x << ' ';
        }
        cout << '\n';
    }
}

#include <bits/stdc++.h>
using namespace std;

#define ll long long
constexpr int MAX_N = 3e4;
ll prefix[2*MAX_N+1];
int maxSubarraySumCircular(vector<int>& nums) {
    if (nums.size() == 1) return nums[0];

    for (int i=1; i<=nums.size(); i++) {
        prefix[i] = prefix[i-1] + nums[i-1];
    }

    for (int i=1; i<=nums.size(); i++) {
        prefix[nums.size()+i] = prefix[nums.size()+i-1] + nums[i-1];
    }

    ll best = INT32_MIN;
    multiset<ll> sw;
    for (int i=1; i<=nums.size(); i++) {
        sw.insert(prefix[i]);
    }

    best = max(best, *sw.rbegin() - prefix[0]);
    for (int i=1; i<=nums.size(); i++) {
        sw.extract(prefix[i]);
        sw.insert(prefix[nums.size()+i]);
        best = max(best, *sw.rbegin() - prefix[i]);
    }

    return best;
}

int main() {
    vector<int> v = {-3, -2, -3};
    cout << maxSubarraySumCircular(v) << '\n';
}
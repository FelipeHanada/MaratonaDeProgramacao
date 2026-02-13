#include <bits/stdc++.h>
using namespace std;

int maxSubarraySumCircular(vector<int>& nums){
    int n = nums.size();
    int best = nums[0];
    int curr = nums[0];
    for (int i=1; i<n; i++) {
        curr = max(curr + nums[i], nums[i]);
        best = max(best, curr);
    }

    vector<int> prefix(n), suffix(n);
    prefix[0] = nums[0];
    for (int i=1; i<n; i++) {
        prefix[i] = prefix[i-1] + nums[i];
    }

    vector<int> best_suffix(n);
    suffix[n-1] = nums[n-1];
    best_suffix[n-1] = nums[n-1];
    for (int i=n-2; i>=0; i--) {
        suffix[i] = suffix[i+1] + nums[i];
        best_suffix[i] = max(best_suffix[i+1], suffix[i]);
    }

    int best_spe = INT32_MIN;
    for (int i=0; i<n-1; i++) {
        best_spe = max(best_spe, prefix[i] + best_suffix[i+1]);
    }

    return max(best, best_spe);
}

int main() {
    vector<int> v = {5, -3, 5};
    cout << maxSubarraySumCircular(v) << '\n';
}

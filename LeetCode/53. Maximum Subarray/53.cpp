#include <bits/stdc++.h>
using namespace std;

int maxSubArray(vector<int>& nums) {
    // using Kadane's Algorithm

    int curr = 0, best = 0;
    for (int i=0; i<nums.size(); i++) {
        curr = max(curr + nums[i], nums[i]);
        best = max(curr, best);
    }

    return best;
}

int main() {
    vector<int> v = {-2,1,-3,4,-1,2,1,-5,4};
    cout << maxSubArray(v);
}
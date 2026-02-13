#include <bits/stdc++.h>
using namespace std;


int maxProduct(vector<int>& nums) {
    int big=1, small=1;
    int best=INT32_MIN;
    for (int i=0; i<nums.size(); i++) {
        int a = big * nums[i], b = small * nums[i];
        big = max(nums[i], max(a, b));
        small = min(nums[i], min(a, b));
        best = max(best, big);
        if (!nums[i]) big = small = 1;
    }

    return best;
}

int main() {
    vector<int> v = {3,-1,4};
    cout << maxProduct(v) << '\n';
}

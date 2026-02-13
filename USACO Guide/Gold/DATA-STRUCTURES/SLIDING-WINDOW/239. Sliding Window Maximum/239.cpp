#include <bits/stdc++.h>
using namespace std;


vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    multiset<int> ms;
    for (int i=0; i<k; i++) ms.insert(nums[i]);
    
    vector<int> ans;
    ans.push_back(*ms.rbegin());
    for (int i=0; i+k<nums.size(); i++) {
        ms.extract(nums[i]);
        ms.insert(nums[i+k]);
        ans.push_back(*ms.rbegin());
    }

    return ans;
}

int main() {
    vector<int> v = {1,3,-1,-3,5,3,6,7};
    vector<int> out = maxSlidingWindow(v, 3);
    for (int i=0; i<out.size(); i++)
        cout << out[i] << ' ';
    cout << '\n';
}


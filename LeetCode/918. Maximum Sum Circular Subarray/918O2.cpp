#include <bits/stdc++.h>
using namespace std;


int kadane(const deque<int>& dq) {
    int curr = dq[0];
    int best = dq[0];

    for (int i=1; i<dq.size(); i++) {
        curr = max(curr + dq[i], dq[i]);
        best = max(best, curr);
    }

    return best;
}

int maxSubarraySumCircular(vector<int>& nums) {
    deque<int> dq(nums.begin(), nums.end());

    int best = INT32_MIN;
    for (int i=0; i<nums.size(); i++) {
        best = max(best, kadane(dq));
        dq.push_front(dq.back());
        dq.pop_back();
    }

    return best;
}

int main() {
    vector<int> v = {5, -3, 5};
    cout << maxSubarraySumCircular(v);
}
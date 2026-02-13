#include <bits/stdc++.h>
using namespace std;


vector<int> getRow(int rowIndex) {
    vector<int> ans;
    ans.push_back(1);

    for (int i=1; i<=rowIndex; i++) {
        int back = ans.back();
        for (int i=ans.size()-1; i>0; i--) {
            ans[i] += ans[i-1];
        }
        if (!(i%2)) {
            ans.push_back(back * 2);
        }
    }

    int n = ans.size();
    if (rowIndex % 2) ans.push_back(ans.back());
    for (int i=n-2; i>=0; i--) {
        ans.push_back(ans[i]);
    }

    return ans;
}

int main() {
    vector<int> ans = getRow(3);
    for (int i=0; i<ans.size(); i++) {
        cout << ans[i] << ' ';
    }
    cout << '\n';
}

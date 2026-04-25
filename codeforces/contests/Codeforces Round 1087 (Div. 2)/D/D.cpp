#include <bits/stdc++.h>
using namespace std;


using ll = long long;

int main() {
    int tt;
    cin >> tt;
    while (tt--) {
        int r, g, b;
        cin >> r >> g >> b;
        int tot[3] = {r, g, b};
        vector<vector<array<int,8>>> dp;

        dp.push_back({array<int,8>({ -1, -1, -1, -1, 0, 0, 0, -1 })});

        while (!dp.back().empty()) {
            vector<array<int,8>> novo;
            for (int i=0; i<dp.back().size(); i++) {
                auto curr = dp.back()[i];
                for (int c=0; c<3; c++) if (c != curr[1] && c != curr[3]) {
                    array<int,8> nstate = { curr[1], curr[2], curr[3], c, curr[4], curr[5], curr[6], i };
                    nstate[4 + c]++;
                    if (nstate[4 + c] > tot[c]) continue;
                    novo.push_back(nstate);
                }
            }
            dp.push_back(novo);
        }
        
        int i = dp.size()-2;
        auto curr = dp[i--][0];

        stack<int> ans;
        while (curr[7] != -1) {
            ans.push(curr[3]);
            curr = dp[i--][curr[7]];
        }

        while (!ans.empty()) {
            cout << "RGB"[ans.top()];
            ans.pop();
        }
        cout << '\n';
    }
}

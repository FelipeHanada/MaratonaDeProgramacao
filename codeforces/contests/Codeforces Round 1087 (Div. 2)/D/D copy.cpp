#include <bits/stdc++.h>
using namespace std;


typedef array<int,6> State;
using ll = long long;

int main() {
    int tt;
    cin >> tt;
    while (tt--) {
        int r, g, b;
        cin >> r >> g >> b;
        int tot[3] = {r, g, b};

        vector<map<State, State>> dp;
        dp.push_back(map<State, State>());
        dp[0][State({-1, -1, -1, 0, 0, 0})] = State({-1, -1, -1, -1, -1, -1});

        while (!dp.back().empty()) {
            map<State, State> novo;

            for (pair<State, State> curr : dp.back()) {
                State state = curr.first;

                for (int c=0; c<3; c++) if (c != state[0] && c != state[2]) {
                    State nstate = { state[1], state[2], c, state[3], state[4], state[5] };
                    nstate[3 + c]++;
                    if (nstate[3 + c] > tot[c]) continue;
                    
                    novo[nstate] = state;
                }

            }

            dp.push_back(novo);
        }
        
        int i = dp.size()-2;
        auto p = (*(dp[i--].begin()));
        State curr = p.first;
        State prev = p.second;

        stack<int> ans;
        while (curr[2] != -1) {
            ans.push(curr[2]);

            curr = State(prev);
            prev = dp[i--][curr];
        }

        while (!ans.empty()) {
            cout << "RGB"[ans.top()];
            ans.pop();
        }
        cout << '\n';
    }
}

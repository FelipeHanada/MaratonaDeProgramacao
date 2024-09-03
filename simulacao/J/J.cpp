#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;
    vector<vector<int>> adj(N, vector<int>());
    for(int i = 0; i<N-1; i++){
        int a, b;
        cin >> a >> b;
        adj[a-1].push_back(b-1);
        adj[b-1].push_back(a-1);
    }

    for(int i = 0; i<N; i++){
        int maxM = -1;

        for(int j = 0; j<adj[i].size(); j++){
            maxM = max(maxM, adj[i][j]);
        }

        if(maxM>i) cout << maxM+1 << " ";
        else cout << i+1 << " ";
    }
}
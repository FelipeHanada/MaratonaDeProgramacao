#include <bits/stdc++.h>
using namespace std;


// the number of minimum routes needed is equal to the number of independent componentes - 1

int main() {
    int n, m;
    cin >> n >> m;

    vector<set<int>> adj(n, set<int>());
    for (int i=0; i<m; i++) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        adj[a].insert(b);
        adj[b].insert(a);
    }

    set<int> unseen;
    for (int i=0; i<n; i++)
        unseen.insert(i);
    vector<set<int>> components;
    while (unseen.size() > 0) {
        set<int> component;
        stack<int> to_see;
        to_see.emplace(*unseen.begin());

        while (to_see.size() > 0) {
            int start = to_see.top();
            to_see.pop();

            unseen.erase(start);
            component.insert(start);
            for (int x : adj[start]) {
                if (unseen.find(x) != unseen.end()) {
                    to_see.emplace(x);
                }
            }
        }

        components.push_back(component);
    }

    cout << components.size() - 1 << endl;
    for (int i=0; i<components.size()-1; i++) {
        cout << *(components[i].begin()) + 1 << " " << *(components[i+1].begin()) + 1 << endl;
    }
}

#include <bits/stdc++.h>
using namespace std;

string INPUT_FILE_NAME = "input/B_1";
string OUTPUT_FILE_NAME = "output_temp";

void solution() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> adj(n + m);  // last n nodes are movies
    for (int i=0; i<n; i++) {
        int k; cin >> k;
        for (int j=0; j<k; j++) {
            int x; cin >> x; x--;
            adj[m + i].push_back(x);
            adj[x].push_back(m + i);
        }
    }

    vector<int> roots;
    vector<int> components(n + m, -1);
    vector<pair<int, int>> paths(n + m, {-1, -1});
    int q;
    cin >> q;

    for (int i=0; i<q; i++) {
        int x, y;
        cin >> x >> y; x--; y--;

        if (components[x] < 0) {
            int curr_comp = roots.size();
            roots.push_back(x);
            components[x] = curr_comp;
            paths[x] = { x, 0 };

            queue<int> bfs;
            bfs.push(x);
            while (!bfs.empty()) {
                int curr = bfs.front(); bfs.pop();
                
                for (auto a : adj[curr]) {
                    if (components[a] >= 0) continue;
                    components[a] = curr_comp;
                    paths[a] = { curr, paths[curr].second + 1 };
                    bfs.push(a);
                }
            }
        }

        if (components[x] != components[y]) {
            cout << -1 << '\n';
            continue;
        }

        int component = components[x];
        int root = roots[component];
        // find a path from x to root[component] to y
        cout << (paths[x].second + paths[y].second) / 2 + 1 << '\n';

        int curr = x;
        bool actor = true;

        while (curr != root) {
            cout << curr + (actor ? 0 : -m) + 1 << ' ';
            curr = paths[curr].first;
            actor = !actor;
        }

        cout << root + 1 << ' ';
        
        stack<int> pathstack;
        curr = y;
        while (curr != root) {
            pathstack.push(curr);
            curr = paths[curr].first;
        }
        actor = false;
        while (!pathstack.empty()) {
            cout << pathstack.top() + (actor ? 0 : -m) + 1 << ' ';
            pathstack.pop();
            actor = !actor;
        }
        cout << '\n';
    }
}

bool check_solution() {
    // builds adjacency list for graph in input
    // checks output_file to validade the solutions
    ifstream input(INPUT_FILE_NAME);
    ifstream output(OUTPUT_FILE_NAME);

    if (!input.is_open() || !output.is_open()) {
        cerr << "Error opening input or output file.\n";
        return false;
    }

    int n, m;
    input >> n >> m;

    vector<set<int>> adj(n + m);  // last n nodes are movies
    for (int i = 0; i < n; i++) {
        int k;
        input >> k;
        for (int j = 0; j < k; j++) {
            int x;
            input >> x;
            x--;
            adj[m + i].insert(x);
            adj[x].insert(m + i);
        }
    }

    int q; input >> q;

    bool valid = true;
    for (int i = 0; i < q; i++) {
        int x, y;
        input >> x >> y; x--; y--;

        int d;
        output >> d;

        if (d > -1) {
            // verify path
            int curr;
            output >> curr; curr--;
            if (curr != x) {
                valid = false;
                break;
            }
            bool actor = false;
            for (int j=1; j<2*d - 1; j++) {
                int prox; output >> prox; prox--;
                
                if (!actor)
                    prox += m;
                
                if (adj[curr].find(prox) == adj[curr].end()) {
                    valid = false;
                    break;
                }
                curr = prox;
                actor = !actor;
            }
    
            if (curr != y) {
                valid = false;
                break;
            }
        } else {
            // run bfs on x, if y is atingible, then it is false
            queue<int> bfs;
            vector<bool> visited(n + m, false);
            bfs.push(x);
            visited[x] = true;

            while (!bfs.empty()) {
                int curr = bfs.front(); bfs.pop();

                if (curr == y) {
                    valid = false;
                    break;
                }

                for (int neighbor : adj[curr]) {
                    if (!visited[neighbor]) {
                        visited[neighbor] = true;
                        bfs.push(neighbor);
                    }
                }
            }
        }
    }

    input.close();
    output.close();
    return valid;
}

int main() {
    for (int i=1; i<=44; i++) {
        while (INPUT_FILE_NAME.back() != '_')
            INPUT_FILE_NAME.pop_back();
        INPUT_FILE_NAME.append(to_string(i));
        freopen(INPUT_FILE_NAME.c_str(), "r", stdin);
        freopen(OUTPUT_FILE_NAME.c_str(), "w", stdout);
    
        auto start = chrono::high_resolution_clock::now();
        solution();
        auto end = chrono::high_resolution_clock::now();
    
        fclose(stdin);
        fclose(stdout);
    
        chrono::duration<double> elapsed = end - start;
        cerr << (check_solution() ? "PASSED" : "FAILED") << " - ";
        cerr << "Elapsed time: " << elapsed.count() << " seconds\n";
    }

}

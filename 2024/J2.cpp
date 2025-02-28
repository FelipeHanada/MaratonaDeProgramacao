#include <bits/stdc++.h>
using namespace std;


constexpr int MAX_N = 1000;
constexpr int MAX_M = 1000;

tuple<int, int, int> edges[MAX_M];
vector<int> incidents[MAX_N];
//  incidents[i] = arestas que incidem no vertice i
int d[MAX_N][MAX_M + 1];
//  d[i][0] = grau do vertice i
//  d[i][c] = numero de arestas de cor c incidentes a i
int n, m, k;

bool seen[MAX_M];  // arestas visitadas
bool hierholzer(vector<int> &eulerian_edge_circuit) {
    for (int i=0; i<n; i++) {
        //  condicao 1 - para todo vertice, o grau deve ser par
        if (d[i][0] % 2) return false;

        //  condicao 2 - nenhum vertice pode ter mais do que d(v)/2 arestas de mesma cor incidentes
        for (int j=1; j<=k; j++)
            if (d[i][j] > d[i][0] / 2) return false;
    }

    for (int start_e : incidents[0]) {
        vector<int> edge_circuit;
        int added_edges = 1;

        auto edge = edges[start_e];

        stack<int> curr_path;
        curr_path.push(0);
        curr_path.push(get<0>(edge) + get<1>(edge));
        
        stack<int> curr_edge_path;
        curr_edge_path.push(-1);
        curr_edge_path.push(start_e);

        fill_n(seen, m, false);
        seen[start_e] = true;

        while (!curr_edge_path.empty()) {
            int curr_vertex = curr_path.top();
            int next_edge = -1;
            for (int e : incidents[curr_vertex]) {
                if (
                    seen[e] ||
                    (curr_edge_path.top() >= 0 && get<2>(edges[e]) == get<2>(edges[curr_edge_path.top()]))
                )
                    continue;
                seen[e] = true;
                next_edge = e;
                break;
            }

            if (next_edge == -1) {
                edge_circuit.push_back(curr_edge_path.top());
                added_edges++;
                
                curr_path.pop();
                curr_edge_path.pop();
            } else {
                auto edge = edges[next_edge];
                curr_path.push(get<0>(edge) + get<1>(edge) - curr_vertex);
                curr_edge_path.push(next_edge);
            }
        }

        if (added_edges < m) continue;

        edge_circuit.pop_back();
        if (get<2>(edges[edge_circuit.front()]) != get<2>(edges[edge_circuit.back()])) {
            eulerian_edge_circuit = edge_circuit;
            return true;
        }
    }

    return false;
}

int main() {
    freopen("j.in", "r", stdin);
    freopen("j.out", "w", stdout);

    cin >> n >> m >> k;

    for (int i=0; i<m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        a--; b--;
        d[a][0]++; d[a][c]++;
        d[b][0]++; d[b][c]++;

        edges[i] = { a, b, c };
        incidents[a].push_back(i);
        incidents[b].push_back(i);
    }

    vector<int> eulerian_edge_circuit;
    if (hierholzer(eulerian_edge_circuit)) {
        cout << 1 << endl;
        for (int e : eulerian_edge_circuit)
            cout << e + 1 << " ";
        cout << endl;
    } else {
        cout << -1 << endl;
    }
}

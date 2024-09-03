#include <bits/stdc++.h>

using namespace std;

int N, M, K;

bool solve(int cow1, const vector<int> &m, const map<int, int> &p) {
    vector<int> cows(N, 0);

    for (const auto &fcow : p)
        cows[fcow.second] = fcow.first;

    if (cows[cow1] != 0) return false;
    cows[cow1] = 1;

    queue<int> qm;  // fila de vacas ordem
    for (auto cow: m) qm.push(cow);

    for (int i=0; i<N && qm.size() > 0; i++) {
        if (p.find(qm.front()) != p.end()) { // verifica se vaca fixa
            if (cows[i] == qm.front()) qm.pop();
            continue;
        }

        if (cows[i] != 0) continue;
        cows[i] = qm.front();
        qm.pop();
    }

    if (qm.size() > 0) return false;

    return true;
}

int main() {
    freopen("milkorder.in", "r", stdin);
    freopen("milkorder.out", "w", stdout);

    cin >> N >> M >> K;

    vector<int> m(M);
    for (int i=0; i<M; i++) cin >> m[i];

    map<int, int> p;
    int ci, pi;
    for (int i=0; i<K; i++){
        cin >> ci >> pi;
        p.insert({ci, pi - 1});
    }
    
    if (p.find(1) != p.end()) {
        cout << p[1] + 1 << endl;
    } else {
        for (int cow1=0; cow1<N; cow1++) {
            if (solve(cow1, m, p)) {
                cout << cow1 + 1 << endl;
                break;
            }
        }
    }
}

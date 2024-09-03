#include <bits/stdc++.h>

using namespace std;

const vector<string> COW_NAMES = []() {
    vector<string> tmp = {
        "Bessie", "Buttercup", "Belinda", "Beatrice",
        "Bella", "Blue", "Betsy", "Sue"
    };
    sort(tmp.begin(), tmp.end());
    
    return tmp;
}();

const map<string, int> COW_IDS = [](){
    map<string, int> tmp;
    for (int i=0; i<COW_NAMES.size(); i++)
        tmp.insert({COW_NAMES[i], i});

    return tmp;
}();

#define N_COWS 8

int main() {
    freopen("lineup.in", "r", stdin);
    freopen("lineup.out", "w", stdout);

    int n;
    cin >> n;

    string c1, c2, s;
    int cid1, cid2;
    vector<vector<int>> adj_matrix(N_COWS);

    for (int i=0; i<n; i++) {
        cin >> c1 >> s >> s >> s >> s >> c2;
        cid1 = COW_IDS.at(c1);
        cid2 = COW_IDS.at(c2);
        adj_matrix[cid1].push_back(cid2);
        adj_matrix[cid2].push_back(cid1);
    }

    vector<int> order;
    vector<bool> seen(N_COWS, false);
    for (int c=0; c<N_COWS; c++) {
        // sem espaço na esquerda
        // só é possível adicionar se adj_matrix[c].size() < 2

        if (seen[c]) continue;

        if (adj_matrix[c].size() < 2) {
            order.push_back(c);
            seen[c] = true;

            if (adj_matrix[c].size() == 1) {
                // começo de cadeia de vaca
                // adiciona todas as vacas da cadeia

                int cow = adj_matrix[c][0];
                while (adj_matrix[cow].size() == 2) {
                    // enquanto a vaca for uma vaca do meio
                    order.push_back(cow);
                    seen[cow] = true;

                    // avança para o próximo nó da cadeia
                    int a = adj_matrix[cow][0], b = adj_matrix[cow][1];
                    cow = seen[a] ? b : a;
                }

                order.push_back(cow);
                seen[cow] = true;
            }
        }
    }

    for (int cow : order) {
        cout << COW_NAMES[cow] << endl;
    }
}
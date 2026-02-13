#include <bits/stdc++.h>
using namespace std;


#define pii pair<int, int>
#define f first
#define s second

int main() {
    int n;
    cin >> n;
    unordered_map<string, int> freq;
    unordered_map<string, pii> dict;
    for (int i=0; i<n; i++) {
        string s; int x, y;
        cin >> s >> x >> y;
        dict[s] = make_pair(x, y);
        freq[s] = i;
    }

    int m;
    cin >> m;
    vector<string> knowledge(m);
    for (int i=0; i<m; i++) {
        cin >> knowledge[i];
    }

    int q, k;
    cin >> q >> k;
    while (q--) {
        int f;
        cin >> f;
        deque<string> query;
        for (int i=0; i<f; i++) {
            string s;
            cin >> s;
            query.push_back(s);
            if (query.size() > k) query.pop_front();
            cout << s << ' ';
        }

        bool candidates = false;
        int sum_x = 0, sum_y = 0;
        while (!candidates && !query.empty()) {
            for (int i=0; i+query.size()<knowledge.size(); i++) {
                bool ok = true;
                for (int j=0; ok && j<query.size(); j++) {
                    if (query[j] != knowledge[i+j]) {
                        ok = false;
                    }
                }

                if (ok) {
                    candidates = true;
                    sum_x += dict[knowledge[i + query.size()]].f;
                    sum_y += dict[knowledge[i + query.size()]].s;
                }
            }

            query.pop_front();
        }

        if (!candidates) {
            cout << "*\n";
            continue;            
        }

        string best;
        int Sbest = INT32_MIN;
        for (auto [word, vet] : dict) {
            int S = sum_x * vet.f + sum_y * vet.s;

            if (S > Sbest || (S == Sbest && freq[word] < freq[best])) {
                best = word;
                Sbest = S;
            }
        }

        cout << best << '\n';
    }
}
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
 
        multiset<string> candidates;
        while (candidates.empty() && !query.empty()) {
            for (int i=0; i+query.size()<knowledge.size(); i++) {
                bool ok = true;
                for (int j=0; ok && j<query.size(); j++) {
                    if (query[j] != knowledge[i+j]) {
                        ok = false;
                    }
                }
 
                if (ok) candidates.insert(knowledge[i + query.size()]);
            }
 
            query.pop_front();
        }
 
        if (candidates.empty()) {
            cout << "*\n";
            continue;            
        }
 
        string best;
        int Sbest = INT32_MIN;
        for (auto [word, vet] : dict) {
            int S = 0;
            for (auto c : candidates) {
                S += dict[c].f * vet.f + dict[c].s * vet.s;
            }
 
            if (S > Sbest || (S == Sbest && freq[word] < freq[best])) {
                best = word;
                Sbest = S;
            }
        }
 
        cout << best << '\n';
    }
}
#include <bits/stdc++.h>

using namespace std;


int main() {
    freopen("circlecross.in", "r", stdin);
    freopen("circlecross.out", "w", stdout);

    set<int> seen;
    stack<int> s;
    stack<int> aux;

    int count = 0;
    char c;
    for (int i=0; i<52; i++) {
        cin >> c;
        if (seen.find(c) != seen.end()) {
            while (s.top() != c) {
                aux.emplace(s.top());
                s.pop();
            }
            s.pop();

            while (aux.size() != 0) {
                s.emplace(aux.top());
                aux.pop();
                count++;
            }
        } else {
            seen.insert(c);
            s.emplace(c);
        }
    }

    cout << count << endl;
}

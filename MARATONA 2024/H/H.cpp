#include <bits/stdc++.h>
using namespace std;


string m, n;
queue<int> m_stars, n_stars;
int n_int;
bool solved = false;

bool is_divisible() {
    int remainder = 0;    
    for (char c : m) {
        remainder = remainder * 2 + (c - '0');
        remainder %= n_int;
    }
    return remainder == 0;
}

bool solve() {
    if (m_stars.empty() && n_stars.empty()) {
        return is_divisible();
    }

    if (!m_stars.empty()) {
        int i = m_stars.front();
        m_stars.pop();
        
        m[i] = '0';
        if (solve()) return true;

        m[i] = '1';
        if (solve()) return true;
        
        m_stars.push(i);
    } else {
        int i = n_stars.front();
        n_stars.pop();
        
        if (solve()) return true;

        n_int += (1<<(n.size()-i-1));
        if (solve()) return true;
        n_int -= (1<<(n.size()-i-1));

        n_stars.push(i);
    }

    return false;
}

int main() {
    cin >> m >> n;
    for (int i=0; i<m.size(); i++) {
        if (m[i] == '*') m_stars.push(i);
    }
    for (int i=0; i<n.size(); i++) {
        if (n[i] == '*') n_stars.push(i);
    }

    n_int = 0;
    for (int i=0; i<n.size(); i++) {
        n_int <<= 1;
        if (n[i] == '1') n_int |= 1;
    }

    solve();
    cout << m << '\n';
}

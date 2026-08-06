#include <bits/stdc++.h>
using namespace std;

constexpr int md = int(1e9)+7;
int add(int a, int b) {
    a += b;
    if (a >= md) a -= md;
    return a;
}
string s;
int d;


int main() {
    cin >> s >> d;
    int n = s.size();

    vector<int> loose(d, 0), tight(d, 0);
    tight[0] = 1;

    for (int i=0; i<n; i++) {
        vector<int> next_loose(d, 0), next_tight(d, 0);
        for (int j=0; j<d; j++) {
            for (int x=0; '0'+x < s[i]; x++) {
                next_loose[(j+x)%d] = add(next_loose[(j+x)%d], add(loose[j], tight[j]));
            }

            next_loose[(j+s[i]-'0')%d] = add(next_loose[(j+s[i]-'0')%d], loose[j]);
            next_tight[(j+s[i]-'0')%d] = add(next_tight[(j+s[i]-'0')%d], tight[j]);

            for (int x=s[i]-'0'+1; x<10; x++) {
                next_loose[(j+x)%d] = add(next_loose[(j+x)%d], loose[j]);
            }
        }

        swap(next_loose, loose);
        swap(next_tight, tight);
    }

    cout << (add(loose[0], tight[0]) - 1 + md) % md << '\n';
}

#include <bits/stdc++.h>
using namespace std;

#define ll long long

void precompute() {

}

void solve() {
    int n, q;
    cin >> n >> q;
    string s;
    cin >> s;
    vector<vector<int>> ops(3, vector(3, 0));
    for (int i=0; i<q; i++) {
    	char a, b;
    	cin >> a >> b;
    	ops[a-'a'][b-'a']++;
    }
    
    // we can greedily make s lex. minimal by doing the following changes in order of priority
    /*
    	[b] -> [a] by b->a or b->c->a
    	[c] -> [a] by c->a or c->b->a
		for a prefix p of s with k' and k'' b's and c's, the p can be turned
			into only a's if the following occurs:
			for some k <= ops[1][0]
				k' <= ops[1][0] - k + min(ops[1][2], ops[2][0])
				k'' <= ops[2][0] + min(ops[2][1], k)

			since k is the number of c->b transitions used
			we want to find the minimum k that solves these inequalities
				while maximizing the size of p
			
			we can do bin search on the size of p?
			we can run prefix sums to count the k' and k''?

    	[c] -> [b] by c->b
    	the problem is to choose the best transitions to use
    */
    
	int i=0;
	while (i < n) {
		for (; i<n; i++) {
			if (s[i] == 'b') {
				if (ops[1][2] && ops[2][0]) {
					s[i] = 'a';
					ops[1][2]--;
					ops[2][0]--;
				} else {
					break;
				}
			} else if (s[i] == 'c') {
				if (ops[2][1] && ops[1][0]) {
					s[i] = 'a';
					ops[2][1]--;
					ops[1][0]--;
				} else {
					break;
				}
			}
		}

		for (; i<n; i++) {
			if (s[i] == 'b') {
				if (ops[1][0]) {
					s[i] = 'a';
					ops[1][0]--;
				} else {
					break;
				}
			} else if (s[i] == 'c') {
				if (ops[2][1]) {
					s[i] = 'b';
					ops[2][1]--;
				} else {
					break;
				}
			}
		}
	}
	
    cout << s << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    precompute();
    int tt;
    cin >> tt;
    while (tt--) solve();    
    return 0;
}

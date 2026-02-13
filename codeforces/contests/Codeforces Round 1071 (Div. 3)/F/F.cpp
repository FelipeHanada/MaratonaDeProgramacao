#include <bits/stdc++.h>
using namespace std;

#define ll long long


void solve1() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n);
    for (int i=0; i<m; i++) {
    	int x, y;
    	cin >> x >> y;
    	x--; y--;
    	adj[x].push_back(y);
    	adj[y].push_back(x);
    }
    
    queue<array<int, 2>> bfs;
    bfs.push({0, 0});
    vector<int> color(n, -1); color[0] = 0;
    
    while (!bfs.empty()) {
    	auto [curr, d] = bfs.front();
    	bfs.pop();
    	for (int neighbor : adj[curr]) {
    		if (color[neighbor] != -1) continue;
    		color[neighbor] = (d+1)%3;
    		bfs.push({neighbor, (d+1)%3});
    	}
    }
    
    for (int i=0; i<n; i++) {
    	if (color[i] == 0) cout << 'r';
    	else if (color[i] == 1) cout << 'g';
    	else cout << 'b';
    }
    cout << '\n';
}

void solve2() {
	int q;
	cin >> q;
	
	while (q--) {
		int d;
		cin >> d;
		string c;
		cin >> c;
		
		map<char, int> colors;
		for (int i=0; i<d; i++) {
			colors[c[i]] = i;
		}
		
		if (colors.size() == 1) {
			cout << "1\n";
		} else {
			int r = colors.count('r'),
				g = colors.count('g'),
				b = colors.count('b');
			if (r && b) {
				cout << colors['r'] + 1 << '\n';
			} else if (g && r) {
				cout << colors['g'] + 1 << '\n';
			} else if (b && g) {
				cout << colors['b'] + 1 << '\n';
			}
		}
	}
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
	string run;
	cin >> run;
	bool first = !run.compare("first");
	
	int tt;
	cin >> tt;
	
	if (first) while (tt--) solve1();
	else while (tt--) solve2();
	
    return 0;
}

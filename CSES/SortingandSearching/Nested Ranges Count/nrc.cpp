#include <bits/stdc++.h>
using namespace std;


struct SegTree {
	int size;
	vector<int> tree;
	SegTree(int n) {
		size = 1;
		while (size < n) size *= 2;
		tree.assign(size * 2, 0);
	}
	void add(int i, int x, int lx, int rx) {
		if (rx - lx == 1) {
			tree[x]++;
			return;
		}
		int mid = (lx + rx) / 2;
		if (i < mid) {
			add(i, 2*x+1, lx, mid);
		} else {
			add(i, 2*x+2, mid, rx);
		}
		tree[x] = tree[2*x+1] + tree[2*x+2];
	}
	void add(int i) { add(i, 0, 0, size); }
	int get(int l, int r, int x, int lx, int rx) {
		if (lx >= l && rx <= r) return tree[x];
		if (lx >= r || rx <= l) return 0;
		int mid = (lx + rx) / 2;
		return get(l, r, 2*x+1, lx, mid) + get(l, r, 2*x+2, mid, rx);
	}
	int get(int l, int r) { return get(l, r, 0, 0, size); }
};

int n;
void solve(const vector<array<int,3>> &ranges) {
	vector<int> ans(n, 0);
	SegTree segtree(2*n);
	
	for (int i=n-1; i>=0; i--) {
		ans[ranges[i][2]] = segtree.get(0, ranges[i][1]*-1 + 1);
		segtree.add(ranges[i][1]*-1);
	}
	
	for (int i=0; i<n; i++) {
		cout << ans[i] << ' ';
	}
	cout << '\n';
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> n;
	set<int> s;
	vector<array<int,3>> ranges(n);
	for (int i=0; i<n; i++) {
		cin >> ranges[i][0] >> ranges[i][1];
		ranges[i][2] = i;
		s.insert(ranges[i][0]);
		s.insert(ranges[i][1]);
	}
	{
		map<int, int> comp;
		int i=0;
		for (int x : s) {
			comp[x] = i++;
		}
		for (int i=0; i<n; i++) {
			ranges[i][0] = comp[ranges[i][0]];
			ranges[i][1] = comp[ranges[i][1]] * -1;
		}
	}
	
	sort(ranges.begin(), ranges.end());
	solve(ranges);
	
	for (int i=0; i<n; i++) {
		tie(ranges[i][0], ranges[i][1]) = make_tuple(ranges[i][1]*-1, ranges[i][0]*-1);
	}
	sort(ranges.begin(), ranges.end());
	solve(ranges);
}
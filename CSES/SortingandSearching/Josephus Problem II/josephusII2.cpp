#include <bits/stdc++.h>
using namespace std;



struct Segtree {
	int size;
	vector<int> cnt;
	Segtree(int n) {
		size = 1;
		while (size < n) size *= 2;
		cnt.assign(size*2, 0);
	}
	void set(int v, int i, int x, int lx, int rx) {
		if (rx - lx == 1) {
			cnt[x] = v;
			return;
		}
		int mid = (lx + rx) / 2;
		if (i < mid) {
			set(v, i, 2*x+1, lx, mid);
		} else {
			set(v, i, 2*x+2, mid, rx);
		}
		cnt[x] = cnt[2*x+1] + cnt[2*x+2];
	}
	void set(int v, int i) { set(v, i, 0, 0, size); }
	int get(int k, int x, int lx, int rx) {
		if (rx - lx == 1) return lx;
		int mid = (lx + rx) / 2;
		if (cnt[2*x+1] >= k) return get(k, 2*x+1, lx, mid);
		else return get(k - cnt[2*x+1], 2*x+2, mid, rx);
	}
	int get(int k) { return get(k, 0, 0, size); }
};

int main() {
	int n, k;
	cin >> n >> k;
	
	Segtree segt(n);
	for (int i=0; i<n; i++) segt.set(1, i); // nlogn
	int curr = 0;
	for (int i=n; i>0; i--) {
		curr = (curr + k) % i;
		int j = segt.get(curr + 1);
		cout << j + 1 << ' ';
		segt.set(0, j);
	}
	cout << '\n';
}

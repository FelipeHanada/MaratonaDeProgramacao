#include <bits/stdc++.h>
using namespace std;

struct segtree{
    int size;
    vector<int> elems;
    vector<int> counts;

    void init(int n){
        size = 1;
        while(size < n) size *= 2;

        elems.assign(size*2, INT32_MAX);
        counts.assign(size*2, 1);
    }

    void set(int i, int v, int x, int lx, int rx){
        if(rx - lx==1){
            elems[x] = v;
            return;
        }
        int m = (lx + rx) / 2;

        if(i < m){
            set(i, v, x*2 + 1, lx, m);
        } else{
            set(i, v, x*2 + 2, m, rx);
        }
        
        elems[x] = min(elems[x*2+1], elems[x*2 + 2]);
        counts[x] = 0;
        if(elems[x*2+1] == elems[x]) counts[x] += counts[x*2+1];
        if(elems[x*2+2] == elems[x]) counts[x] += counts[x*2+2];
    }

    void set(int i, int v){
        set(i,v,0,0,size);
    }

    pair<int,int> solve(int l, int r, int x, int lx, int rx){
        if(lx >= l && rx <= r) {
            return make_pair(elems[x], counts[x]);
        }
        if(rx <= l || lx >= r) {
            return make_pair(INT_MAX, 0);
        }
        int m = (lx + rx) / 2;
        pair<int,int> left = solve(l, r, x*2 + 1, lx, m);
        pair<int,int> right = solve(l, r, x*2 + 2, m, rx);
        int mn = min(left.first, right.first);
        int cnt = 0;
        if(left.first == mn) cnt += left.second;
        if(right.first == mn) cnt += right.second;
        return make_pair(mn, cnt);
    }

    pair<int,int> solve(int l, int r){
        return solve(l, r, 0, 0, size);
    }
};


int main(){
    int n, m;
    cin >> n >> m;

    segtree st;
    st.init(n);
    for(int i = 0; i < n; i++){
        int v;
        cin >> v;
        st.set(i,v);
    }

    for(int i = 0; i < m; i++){
        int mode;
        cin >> mode;
        if(mode == 1){
            int i, v;
            cin >> i >> v;
            st.set(i,v);
        } else{
            int l, r;
            cin >> l >> r;
            pair<int,int> ans = st.solve(l, r);
            cout << ans.first << " " << ans.second << "\n";
        }
    }
}

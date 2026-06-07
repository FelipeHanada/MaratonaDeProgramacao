#include <bits/stdc++.h>
using namespace std;

#define ll long long

struct segtree{
    int size;
    vector<ll> elems;

    void init(int n){
        size = 1;
        while(size < n) size*=2;

        elems.assign(2* size, 0);
    }


    void set(int i, int v, int x, int lx, int rx){
        int m = (lx + rx)/2;

        if(rx - lx == 1){
            elems[x] = v;
            return ;
        }


        if(i<m){
            set(i, v, 2*x + 1, lx, m);

        } else {
            set(i, v, 2*x + 2, m, rx);
        }
        elems[x] = elems[x*2 + 1] + elems[x*2 + 2];
    }

    void set(int i, int v){
        set(i, v, 0, 0, size);
    }

    ll sum(int l, int r, int x, int lx, int rx){
        if(lx >= l && rx <= r){
            //nó x é responsável por um intervalo contido em [l,r)
            return elems[x];
        } else if (l >= rx || r <= lx){
            return 0;
        } else{
            int m = (lx + rx)/2;
            return sum(l, r, 2*x + 1, lx, m) + sum(l, r, 2*x + 2, m, rx);
        }
    }

    ll sum(int l, int r){
        return sum(l, r, 0, 0, size);
    }
};


int main(){
    int n, m;

    cin >> n >> m;

    segtree st;
    st.init(n);

    for(int i = 0; i < n; i++){
        int value;
        cin >> value;
        st.set(i, value);
    }

    for(int i = 0; i < m; i++){
        int op;
        cin >> op;

        if(op == 1){ //set elem
            int i, v;

            cin >> i >> v;
            st.set(i,v);


        } else if(op == 2){ //print sum
            int l, r;
            cin >> l >> r;
            cout << st.sum(l,r) << endl;
        }   
    }

}
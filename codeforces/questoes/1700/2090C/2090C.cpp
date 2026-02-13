#include <bits/stdc++.h>
using namespace std;


#define _1 first
#define _2 second


constexpr int N4 = 50000;
constexpr int T = 2000; // the first 4*N cells may be on the first 2000^2 tables
pair<int, int> cells[N4];
bool available[N4];
bool occupied[T*T];

int get_table(pair<int, int> &cell) {
    return (cell._1/3)*T + (cell._2/3);
}


void precompute() {
    // let d(x, y) = x + y + 2 [x mod 3 = y mod 3 = 2]
    // I) 3a+1 + 3b+1 = 3a + 3b + 2
    // II) 3a+2 + 3b+1 = 3a + 3b + 3
    // III) 3a+1 + 3b+2 = 3a + 3b + 3
    // IV) 3a+2 + 3b+2 + 2 = 3a + 3b + 6

    int d = 2;
    int i = 0;
    while (i<N4) {
        for (int x3=0; d-2-x3>=0 && i<N4; x3+=3) {
            int y3;

            if ((y3=d-2-x3)>=0 && !(y3%3)) {
                cells[i++] = {x3+1, y3+1};
            }

            if ((y3=d-3-x3)>=0 && !(y3%3) && i<N4) {
                cells[i++] = {x3+1, y3+2};
            }

            if ((y3=d-6-x3)>=0 && !(y3%3) && i<N4) {
                cells[i++] = {x3+2, y3+2};
                // this y3 is smaller than the next
            }

            if ((y3=d-3-x3)>=0 && !(y3%3) && i<N4) {
                cells[i++] = {x3+2, y3+1};
            }
        }
        d++;
    }
}

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i=0; i<n; i++) {
        cin >> a[i];
    }

    fill_n(available, N4, true);
    fill_n(occupied, T*T, false);

    int curr = 0, curr_sp = 0;
    for (int i=0; i<n; i++) {
        while (!available[curr]) curr++;
        while (!available[curr_sp] || occupied[get_table(cells[curr_sp])]) curr_sp++;

        if (a[i]) {
            available[curr] = false;
            occupied[get_table(cells[curr])] = true;

            cout << cells[curr]._1 << ' ' << cells[curr]._2 << '\n';
            curr++;
        } else {            
            available[curr_sp] = false;
            occupied[get_table(cells[curr_sp])] = true;

            cout << cells[curr_sp]._1 << ' ' << cells[curr_sp]._2 << '\n';
            curr_sp++;
        }
    }
}

int main() {
    #ifdef ONLINE_JUDGE
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    #endif

    int t;
    cin >> t;
    precompute();
    while (t--) {
        solve();
    }
}

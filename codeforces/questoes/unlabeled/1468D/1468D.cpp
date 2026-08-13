#include <bits/stdc++.h>
using namespace std;


int main() {
    int tt; cin >> tt;
    while (tt--) {
        int n, m, a, b;
        cin >> n >> m >> a >> b;
        priority_queue<int> pq;
        for (int i=0; i<m; i++) {
            int x; cin >> x;
            pq.push(x);
        }

        int limit, time;
        if (a < b) {
            limit = b - a - 1;
            time = b - 2;
        } else {
            limit = a - b - 1;
            time = n-1-b;
        }
        int ans = 0;
        for (int i=0; i<limit && !pq.empty(); i++) {
            while (!pq.empty() && pq.top() > time) pq.pop();
            if (!pq.empty() && pq.top() <= time) {
                pq.pop();
                ans++;
            }

            time--;
        }

        cout << ans << '\n';
    }
}

/*
we can light atmost b - a - 1 fireworks
and wait b  - 2 seconds 

3

7 2 3 6
1 4
x x A x x B x

7 2 5 2
1 4
x B x x A x x
*/

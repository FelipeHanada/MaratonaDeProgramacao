#include <bits/stdc++.h>
using namespace std;

#define pii pair<int, int>
#define f first
#define s second

pii points[(int)2e5];
bool cmpX(const int &a, const int &b) { return points[a] < points[b]; }
bool cmpY(const int &a, const int &b) { return pii(points[a].s, points[a].f) < pii(points[b].s, points[b].f); }
set<int, bool(*)(const int &a, const int &b)> h(cmpX);
set<int, bool(*)(const int &a, const int &b)> v(cmpY);

int evl(int p1, int p2) { return abs(points[p1].f - points[p2].f) + abs(points[p1].s - points[p2].s); }

int n;
void solve() {
    cin >> n;

    h.clear();
    for (int i=0; i<n; i++) {
        cin >> points[i].f >> points[i].s;
        h.insert(i);
        v.insert(i);
    }

    while (h.size() > 0) {
        int left1 = *h.begin(), left2 = *h.begin();
        int right1 = *h.rbegin(), right2 = *h.rbegin();
        int top1 = *v.begin(), top2 = *h.begin();
        int bot1 = *v.rbegin(), bot2 = *v.rbegin();

        int left = points[*h.begin()].f, right = points[*h.rbegin()].f,
            top = points[*v.begin()].s, bot = points[*v.rbegin()].s;

        for (auto it = h.begin(); it != h.end() && points[*it].f == left; it++) {
            if (points[*it].s < points[left1].s) left1 = *it;
            if (points[*it].s > points[left2].s) left2 = *it;
        }

        for (auto it = h.rbegin(); it != h.rend() && points[*it].f == right; it++) {
            if (points[*it].s < points[right1].s) right1 = *it;
            if (points[*it].s > points[right2].s) right2 = *it;
        }

        for (auto it = v.begin(); it != v.end() && points[*it].s == top; it++) {
            if (points[*it].f < points[top1].f) top1 = *it;
            if (points[*it].f > points[top2].f) top2 = *it;
        }

        for (auto it = v.rbegin(); it != v.rend() && points[*it].s == bot; it++) {
            if (points[*it].f < points[bot1].f) bot1 = *it;
            if (points[*it].f > points[bot2].f) bot2 = *it;
        }

        vector<pii> candidates = {
            {left1, right2},
            {left1, top2},
            {left1, bot2},
            {left2, right1},
            {left2, top2},
            {left2, bot2},
            {right1, top1},
            {right1, bot1},
            {right2, top1},
            {right2, bot1},
            {top1, bot2},
            {top2, bot1}
        };

        pii bestpair = candidates.front();
        int best = evl(bestpair.f, bestpair.s);
        int curr;
        for (int i=1; i<candidates.size(); i++) {
            curr = evl(candidates[i].f, candidates[i].s);
            if (curr > best) {
                bestpair = candidates[i];
                best = curr;
            }
        }

        cout << bestpair.f+1 << ' ' << bestpair.s+1 << '\n';
        h.erase(bestpair.f);
        h.erase(bestpair.s);
        v.erase(bestpair.f);
        v.erase(bestpair.s);
    }
}


int main() {
    freopen("input", "r", stdin);

    int t; cin >> t;
    
    for (int i=0; i<t; i++) {
        solve();
    }
}
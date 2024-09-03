#include <bits/stdc++.h>
using namespace std;


int main() {
    int n;
    cin >> n;

    vector<pair<int, int>> tasks;
    for (int i=0; i<n; i++) {
        int a, d;
        cin >> a >> d;
        tasks.push_back({a, d});
    }
    sort(tasks.begin(), tasks.end());

    long long reward = 0;
    long long t = 0;
    for (auto task : tasks) {
        t += task.first;
        reward += task.second - t;
    }

    cout << reward << endl;
}

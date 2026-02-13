#include <bits/stdc++.h>
using namespace std;


int main(){
    int n;
    cin >> n;

    vector<int> v(n);
    for(int i = 0; i < n; i++) cin >> v[i];

    set<int> s;

    int i = 0, j = 0;
    s.emplace(v[0]);
    int best = 1;

    j++;
    while(j < n){
        int elem = v[j];

        while(s.count(elem) == 1){
            s.erase(v[i]);
            i++;
        }

        s.emplace(elem);
        best = max(best, (int) s.size());
        j++;
    }
    cout << best << '\n';
}
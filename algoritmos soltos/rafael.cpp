#include <bits/stdc++.h>
using namespace std;


int main() {
    multiset<int> ms;
    ms.insert(1);
    ms.insert(1);
    ms.insert(2);
    ms.insert(3);
    ms.insert(3);
    ms.insert(4);

    cout << distance(ms.begin(), lower_bound(ms.begin(), ms.end(), 3)) << '\n';
    cout << distance(ms.begin(), upper_bound(ms.begin(), ms.end(), 3)) << '\n';
}
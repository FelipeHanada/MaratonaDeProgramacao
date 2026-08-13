#include <bits/stdc++.h>
using namespace std;


int main() {
    int n = 3;
    cin >> n;

    for (int i=0; i<n; i++) cout << ' ';
    for (int i=0; i<n+1; i++) cout << '_'; cout << '\n';

    for (int i=n-1; i>0; i--) {
        for (int j=0; j<i; j++) cout << ' ';
        cout << '/';
        for (int j=0; j<n-i-1; j++) cout << ' ';
        for (int j=0; j<n+1; j++) cout << ' ';
        for (int j=0; j<n-i-1; j++) cout << ' ';
        cout << char(92);
        cout << '\n';
    }

    cout << '/';
    for (int j=0; j<n; j++) cout << char(95);
    for (int j=0; j<2*n-1; j++) cout << ' ';
    cout << char(92);
    for (int i=0; i<n+1; i++) cout << char(95);
    cout << '\n';

    for (int i=1; i<n; i++) {
        for (int j=0; j<n; j++) cout << ' ';

        for (int j=0; j<i; j++) cout << ' ';
        cout << char(92);
        for (int j=0; j<n-i-1; j++) cout << ' ';
        
        for (int j=0; j<n+3; j++) cout << ' ';

        for (int j=0; j<n-i-1; j++) cout << ' ';
        cout << '/';
        cout << '\n';
    }

    for (int i=0; i<2*n; i++) cout << ' ';
    cout << char(92);
    for (int i=0; i<n+1; i++) cout << char(95);
    cout << '/' << '\n';
}
#include <bits/stdc++.h>
using namespace std;


void cout_mask(int mask, int n) {
    for (int i=n-1; i>=0; i--) {
        cout << (mask & (1<<i) ? 1 : 0);
    }
}

int main() {
    int n = 4;
    int mask = 5; // = 0101

    for (int submask=mask; submask != 0; submask=(submask-1)&mask) {
        int subset = mask ^ submask;
        cout_mask(subset, n); cout << ' '; cout_mask(submask, n); cout << '\n';
    }

}

/*
5 = 0101 -> 4 = 0101
4 = 0100 -> 3 = 0011

*/

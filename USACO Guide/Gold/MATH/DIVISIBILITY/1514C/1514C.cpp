#include <bits/stdc++.h>
using namespace std;


#define _1 first
#define _2 second

/*
1. the sequence cannot have any number that isnt coprime with n
    the product prod of the sequence would not be coprime with n
    then gcd(prod, n) != 1
    since gcd(prod, n) = gcd(prod%n, n), gcd(prod%n, n) != 1
    then prod%n > 1

2. let a sequence P be all the numbers <n that are coprime with n
    if the product prod of P is such that prod%n = p
    p is coprime with n*, and therefore is in the sequence P
    remove p to make the sequence such that prod%n = 1

* we can prove this by contradiction

suppose that prod%n = p where p isnt coprime with n
then gcd(prod%n, n) > 1
since gcd(prod%n, n) = gcd(prod, n)
    gcd(prod, n) > 1
this implies that there is some number in the sequence P
    that is not coprime with P
*/


#define ll long long

int main() {
    int n;
    cin >> n;

    vector<int> coprimes;
    int prod = 1;
    for (int i=2; i<n; i++) {
        if (__gcd(i, n) == 1) {
            coprimes.push_back(i);
            prod = ((ll)prod * i) % n;
        }
    }

    cout << coprimes.size() - (prod>1 ? 1 : 0) << '\n';
    for (int p : coprimes) if (p != prod) {
        cout << p << ' ';
    }
    cout << '\n';
}
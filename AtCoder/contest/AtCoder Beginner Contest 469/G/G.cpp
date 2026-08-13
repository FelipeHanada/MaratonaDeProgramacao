#include <bits/stdc++.h>
using namespace std;


int k; vector<string> s;
int n; string t;
struct elem {
    int a;
    int b;
    elem() : a(0), b(0) { }
    elem(int a, int b) : a(a), b(b) { }
};
elem operator+(const elem& x, const elem& y) {
    if (x.b) return { (x.a - y.a) % n, x.b ^ y.b };
    else return { (x.a + y.a) % n, x.b ^ y.b };
}



int main() {
    cin >> k;
    s.resize(k);
    for (int i=0; i<k; i++) cin >> s[i];
    cin >> n >> t;

    if (n <= k) {
        deque<char> dq(t.begin(), t.end());
        bool rev = 0;
        for (char c : s[n-1]) {
            if (c == 'a') {
                if (rev) {
                    dq.push_front(dq.back());
                    dq.pop_back();
                } else {
                    dq.push_back(dq.front());
                    dq.pop_front();
                }
            } else {
                rev = !rev;
            }
        }

        if (rev) reverse(dq.begin(), dq.end());

        for (char c : dq) cout << c;
        cout << '\n';
        return 0;
    }

    vector<elem> a(k);
    for (int i=0; i<k; i++) {
        bool b_flag = 0;
        int delta = 0;
        for (char c : s[i]) {
            if (c == 'a') {
                if (b_flag) delta--;
                else delta++;
            } else {
                b_flag = !b_flag;
            }
        }

        a[i] = { delta, b_flag };
    }

    vector<int> b(k+1);
    b[0] = 0;
    for (int i=0; i<k; i++) b[0] ^= a[i].b;
    for (int i=1; i<k; i++) b[i] = b[i-1] ^ a[i-1].b;
    b[k] = b[k-1] ^ b[0];

    
}


/*
se n < |s1| + |s2| + ... + |sk|


s1
s2
s3
...
sk
sk s{k-1} ... s1
sk s{k-1} ... s1 | sk ... s2
sk s{k-1} ... s1 sk ... s2 | sk s{k-1} ... s1 | sk ... s3
sk s{k-1} ... s1 sk ... s2 sk s{k-1} ... s1 sk ... s3 | sk s{k-1} ... s1 sk ... s2 | sk s{k-1} ... s1 | sk ... s4


t = abc
reverse = false

a) usando um deque é O(1)
b) flipa flag reverse em O(1)


operar usando Si é o mesmo resultado de operar
    Si-1, Si-2, ..., Si-k


a...a = nada
(n vezes)

bb = nada

aaba
xyz => yzx => zxy => yxz => xzy

xyz => yzx => zxy => yzx => xzy
    para todo a com quantidade par de b, move o primeiro pro final
    para todo a com quantidade impar de b, mode o ultimo pro começo
    se a quantidade de b for ímpar, reverte no final

no final do dia, o que importa é
    a quantidade de a's com quantidade par de b's antes
                e a's com quantidade impar de b's antes

se pa da pra rodar binexpo usando algelin

3
a => (1, 0)
aa => (2, 0)
b => (0, 1)
5
abc

s1 = <1, 0>
s2 = <2, 0>
s3 = <0, 1>
s4 = <0, 1> | <2, 0> | <1, 0> = <-3, 1>
s5 = <-3, 1> | <0, 1> | <2, 0> = <-1, 0>


<a, b> | <c, d> = <a + c * (-1)^b, b ^ d>
(b, d \in { 0, 1 })


fib2
start:
[f1, f0]
[f0, 0]
trans:
[a b]
[b 0]

fib3
start:
[f2 f1 f0]
[f1 f0 0]
[f0 0 0]
trans
[]
[]
[]

*/

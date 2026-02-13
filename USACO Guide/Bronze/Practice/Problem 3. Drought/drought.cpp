#include <bits/stdc++.h>
using namespace std;


/*
3
8 10 5


A B C D E F

x x y D E F

6
4 6 4 4 6 4
^ ^ ^
=> 4 4 2 4 6 4
     ^ ^ ^
=> 2 2 2 4 6 4
       ^ ^ ^
=> 2 2 2 2 4 4
         ^ ^ ^
         

4 6 7 8 9 10
^ ^ ^

4 4 5 3 9 10
  ^ ^ ^

4 4 4 2 9 10
  ^ ^ ^

4 4 4 2 9 10
    ^ ^ ^
    
*/

#define ll long long

int main() {
	int tt;
	cin >> tt;
	while (tt--) {
		int n;
		cin >> n;
		vector<int> a(n);
		for (int i=0; i<n; i++) {
			cin >> a[i];
		}
		
		ll ans = 0;
		ll curr = a[0];
		for (int i=0; i+2<n; i++) {
			
		}
	}
}
#include <bits/stdc++.h>
using namespace std;
#define ll  long long

ll binpow(ll a, ll b){
    if(b == 0){
        return 1;
    }
    else{
        int result;
        result = binpow(a, b/2);

        if(b%2){
            return result * result * a;
        }

        else{
            return result *result;
        }
    }
}


int main(){
    int a, b;
    cin >> a >> b;

    cout << binpow(a, b) << '\n';
}

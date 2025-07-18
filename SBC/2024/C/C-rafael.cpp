#include <bits/stdc++.h>
using namespace std;


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //dado N e N inteiros

    int N;
    cin >> N;

    vector<int> v(N);
    vector<int> dp(N, 0);

    for(int i = 0; i < N; i++){
        cin >> v[i];
    }

    long long sum = 0;
    for(int i = 0; i < N; i++){
        for(int j = N-1; j > i; j--){
            if(v[i] == v[j]){
                dp[j] = 1 + dp[max(j-1,0)];
                dp[max(j-1,0)] = 0;
                sum += dp[j]; 
            } else dp[j] = 0;
        }
    }
    // sum /= commonDivisor;
    // N /= commonDivisor;
    sum *= 2;
    for(int i = 1; i <= N; i++) sum += i;
    N = N*N;
    long long commonDivisor = gcd(sum, N);
    // commonDivisor = gcd(sum, N);
    sum /= commonDivisor;
    N /= commonDivisor;
    cout << sum << "/" << N << endl;
}

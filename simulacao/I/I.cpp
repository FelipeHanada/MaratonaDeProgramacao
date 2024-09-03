#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string s;
    cin >> s;
    int N, countIndiv = 0, countInter = 0;
    cin >> N;
    
    for(int i = 0; i<s.length(); i++){
        for(int j = i+1; j<s.length(); j++){
            if(s[j]<s[i]) countIndiv++;
        }
    }
    for(int i = 0; i<s.length(); i++){
        for(int j = 0; j<s.length(); j++){
            if(s[j]<s[i]) countInter++;
        }
    }
    int ans = N*countIndiv;
    for(int i = 0; i<N; i++) ans += countInter*i;
    cout << ans << endl;


}
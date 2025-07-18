#include <bits/stdc++.h>
using namespace std;


/*

a = 1001100 -> numero q é pra ser menor
b = 0010100 -> numero q é pra ser maior

!a = 0110011
b =  0010100
!(!a | b) = 1001000


a | b = 1011100




a b  !a->b a->b  !a b   !a OR b
0 0  0     1      1 0     1
0 1  0     1      1 1     1
1 0  1     0      0 0     0
1 1  0     1      0 1     1


*/

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //dado N e N inteiros


    int N;
    cin >> N;

    vector<int> v(N);
    vector<int> bits(32, 0);

    for (int i = 0; i < N; i ++){
        int num;
        cin >> num;
        for(int bit = 0; bit < 32; bit++) if(num & (1 << bit)) bits[bit]++;
    }

    for(int i = 0; i < N; i++){
        int ans = 0;
        for(int bit = 0; bit < 32; bit++){
            if (bits[bit]>0){
                ans = ans + (1 << bit);
                bits[bit]--;
            }
        }
        cout << ans << " ";
    }
    


}
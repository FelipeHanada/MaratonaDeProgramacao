#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int N, altura, count = 0;
    cin >> N >> altura;
    for(int i = 0; i<N; i++){
        int valor;
        cin >> valor;
        if(valor<=altura) count++;
    }
    cout << count << endl;
}
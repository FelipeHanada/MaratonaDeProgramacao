#include <bits/stdc++.h>
using namespace std;



constexpr int MAX_NM = 1000;
int n, m;
int ma[MAX_NM][MAX_NM];

void floodFill(int i, int j){
    if(i > 0 && ma[i][j] + 1 < ma[i-1][j]){
        ma[i-1][j] = ma[i][j]+1;
        floodFill(i-1, j);
    }
    if(i < n-1 && ma[i][j] + 1 < ma[i+1][j]){
        ma[i+1][j] = ma[i][j]+1;
        floodFill(i+1, j);
    }
    if(j > 0 && ma[i][j] + 1 < ma[i][j-1]){
        ma[i][j-1] = ma[i][j]+1;
        floodFill(i, j-1);
    }
    if(j < m-1 && ma[i][j] + 1 < ma[i][j+1]){
        ma[i][j+1] = ma[i][j]+1;
        floodFill(i, j+1);
    }
}
void printPath(int i, int j){
    int value = ma[i][j];
    if(i > 0 && ma[i-1][j] >= 0 && value == ma[i-1][j]+1){
        cout << 'U';
        printPath(i-1, j);
    } else if(i < n-1 && ma[i+1][j] >= 0 && value == ma[i+1][j]+1){
        cout << 'D';
        printPath(i+1, j);
    } else if(j > 0 && ma[i][j-1] >= 0 && value == ma[i][j-1]+1){
        cout << 'L';
        printPath(i, j-1);
    } else if(j < m-1 && ma[i][j+1] >= 0 && value == ma[i][j+1]+1){
        cout << 'R';
        printPath(i, j+1);
    }
}
int main(){
    cin >> n >> m;

    int startI, startJ, endI, endJ;
    getchar();
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            int ch = getchar();
            if(ch == '#') ma[i][j] = -1;
            else if (ch == 'B') {
                startI = i;
                startJ = j;

                ma[i][j] = 0;
            }
            else if (ch == 'A') {
                endI = i;
                endJ = j;
                ma[i][j] = INT_MAX;
            }
            else ma[i][j] = INT_MAX;
        }
        getchar();
    }
    floodFill(startI, startJ);
    
    if(ma[endI][endJ] != INT_MAX){
        cout << "YES" << endl;
        cout << ma[endI][endJ] << endl;
        printPath(endI, endJ);
    } else cout << "NO" << endl;
}

#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, m, k;
    cin >> n >> m >> k;

    vector<int> ans(n);
    for(int i = 0; i < n; i++) cin >> ans[i];

    vector<int> operationStart(m), operationEnd(m), operationValue(m);
    for(int i = 0; i < m; i++){
        int start, end, value;
        cin >> start >> end >> value;
        operationStart[i] = start - 1;
        operationEnd[i] = end;
        operationValue[i] = value;
    }

    vector<pair<int,int>> querries(k, make_pair(0,0));
    for(int i = 0; i < k; i++){
        int start, end;
        cin >> start >> end;

        querries[i].first = start-1;
        querries[i].second = end;
    }

    vector<int> operationDiff(m+1, 0);
    for(int i = 0; i < k; i++){
        int start = querries[i].first, end = querries[i].second;
        operationDiff[start]++;
        operationDiff[end]--;
    }

    int aux = 0;
    for(int i = 0; i < m; i++){
        aux += operationDiff[i];
        operationDiff[i] = aux;
    }

    vector<int> ansDiff(n+1, 0);
    for(int op = 0; op < m; op++){
        int start = operationStart[op], end = operationEnd[op], value = operationValue[op];
        ansDiff[start] = ansDiff[start] + value*operationDiff[op];
        ansDiff[end] = ansDiff[end] + value*operationDiff[op];
    }

    aux = 0;
    for(int i = 0; i < n; i++){
        aux += ansDiff[i];
        ans[i]+=aux;
    }

    for(int i = 0; i < n; i++){
        cout << ans[i] << " ";
    }

}
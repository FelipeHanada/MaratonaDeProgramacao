#include <bits/stdc++.h>
using namespace std;


int main() {
    string str;
    cin >> str;
    set<int> s1, s2, s3, s4;
    int q1 = 0, q2 = 0, q3 = 0, q4 = 0;
    for (int i=0; i+2 < str.size(); i+=3) {
        int n = (str[i]-'0')*10 + (str[i+1]-'0');
        
        if (str[i+2] == 'C') {
            s1.insert(n);
            q1++;
        } else if (str[i+2] == 'E') {
            s2.insert(n);
            q2++;
        } else if (str[i+2] == 'U') {
            s3.insert(n);
            q3++;
        } else {
            s4.insert(n);
            q4++;
        }
    }

    if (q1 > s1.size()) cout << "erro";
    else cout << 13 - s1.size();
    cout << '\n';

    if (q2 > s2.size()) cout << "erro";
    else cout << 13 - s2.size();
    cout << '\n';

    if (q3 > s3.size()) cout << "erro";
    else cout << 13 - s3.size();
    cout << '\n';

    if (q4 > s4.size()) cout << "erro";
    else cout << 13 - s4.size();
    cout << '\n';
}
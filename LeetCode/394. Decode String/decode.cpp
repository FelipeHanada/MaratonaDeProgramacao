#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    void decode(const string &s, string &out, int curr) {
        for (; curr < s.size() && s[curr] != ']'; curr++) {
            if (s[curr] >= '0' && s[curr] <= '9') {
                int num = 0;
                for (; s[curr] >= '0' && s[curr] <= '9'; curr++)
                    num = num * 10 + (s[curr] - '0');
                
                while (num--) decode(s, out, curr + 1);
                
                int depth = 1;
                while (depth) {
                    curr++;
                    if (s[curr] == '[') depth++;
                    else if (s[curr] == ']') depth--;
                }
            } else {
                out.push_back(s[curr]);
            }
        }
    }
    string decodeString(string s) {
        string t;
        decode(s, t, 0);
        cout << t << '\n';
        return t;
    }
};

int main() {
    string s = "3[a]2[bc]";
    Solution sol;
    cout << sol.decodeString(s) << '\n';
}

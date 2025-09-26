#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        string current;
        helperFunc(res, current, 0, 0, n);
        return res;
    }
    
    void helperFunc(vector<string>& res, string& current, int openN, int closedN, int n) {
        if (openN == n && closedN == n) {
            res.push_back(current);
            return;
        }
        if (openN < n) {
            current += '(';
            helperFunc(res, current, openN + 1, closedN, n);
            current.pop_back();
        }
        if (closedN < openN) {
            current += ')';
            helperFunc(res, current, openN, closedN + 1, n);
            current.pop_back();
        }
    }
};

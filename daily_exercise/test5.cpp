//5. 编写一个函数，接收一个string对象作为参数，返回该字符串的所有排列组合。例如，对于字符串"abc"，其排列组合为"abc", "acb", "bac", "bca", "cab", "cba"。注意，不需要考虑重复排列。
#include<iostream>
using namespace std;

class Solution 
{
public:
    vector<string> rec;
    vector<int> vis;

    void backtrack(const string& s, int i, int n, string& perm) {
        if (i == n) {
            rec.push_back(perm);
            return;
        }        for (int j = 0; j < n; j++) {
            if (vis[j] || (j > 0 && !vis[j - 1] && s[j - 1] == s[j])) {
                continue;
            }
            vis[j] = true;
            perm.push_back(s[j]);
            backtrack(s, i + 1, n, perm);
            perm.pop_back();
            vis[j] = false;
        }
    }

    vector<string> permutation(string s) {
        int n = s.size();
        vis.resize(n);
        sort(s.begin(), s.end());
        string perm;
        backtrack(s, 0, n, perm);
        return rec;
    }
};

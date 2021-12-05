/**
 * leetcode [44.] 通配符匹配
 *
给定一个字符串 (s) 和一个字符模式 (p) ，实现一个支持 '?' 和 '*' 的通配符匹配。

'?' 可以匹配任何单个字符。
'*' 可以匹配任意字符串（包括空字符串）。
两个字符串完全匹配才算匹配成功。

说明:

s 可能为空，且只包含从 a-z 的小写字母。
p 可能为空，且只包含从 a-z 的小写字母，以及字符 ? 和 *。

输入:
s = "aa"
p = "a"
输出: false
解释: "a" 无法匹配 "aa" 整个字符串。

链接：https://leetcode-cn.com/problems/wildcard-matching
 */
#include <bits/stdc++.h>

using namespace std;
class Solution
{
    /* 题解：DP
        如果模式和匹配字符串的长度为 0 则相等或是匹配的
        然后向上推 字符串匹配的列，我们知道 只有当该点的模式字符是“*” 时，则继续匹配
        如果j - 1处模式是“*”，可以继续匹配，将它等于 dp[i-1][j] 
        如果我们使用“*”的空字符串，则它等于dp[i][j-1]
        如果j-1处的模式不是“*” 那么检查字符是否相等，或者j-1处是否为‘？‘ 然后dp[i][j] = dp[i-1][j-1]
     */
public:
    bool isMatch(string s, string p) {
        int n = s.length();
        int m = p.length();
        if (m == 0)
            return (n == 0);
        vector<vector<int> > dp(n + 1, vector<int>(m + 1, 0));
        dp[0][0] = 1;
        // 字符等于 * 的情况 是能匹配上的
        for (int i = 1; i <= m; i++) {
            if (p[i - 1] == '*')
                dp[0][i] = 1;
            else
                break;
        }

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (p[j - 1] == '*') {
                    dp[i][j] = dp[i - 1][j] || dp[i][j - 1];
                // 如果相等 或者 是 ？ 能匹配上的 取 上一个的结果
                } else if (p[j - 1] == s[i - 1] || p[j - 1] == '?') {
                    dp[i][j] = dp[i - 1][j - 1];
                }
            }
        }
        return dp[n][m];
    }
}
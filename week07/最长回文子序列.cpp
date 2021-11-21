/**
 * leetcode [516.] 最长回文子序列
 *
输入：s = "bbbab"
输出：4
解释：一个可能的最长回文子序列为 "bbbb" 。

链接：https://leetcode-cn.com/problems/longest-palindromic-subsequence/
 */
#include <bits/stdc++.h>

using namespace std;
class Solution
{
    /* 题解：DP
        转移方程：dp[i][j] = max(dp[i+1][j], dp[i][j-1]);
        初始值：dp[0][0] = 0; 目标值： dp[0][n-1]
     */
public:
    int longestPalindromeSubseq(string s) {
        int n = s.size();
        vector<vector<int> > dp(n, vector<int>(n, 0));
        for (int i = 0; i < n; i++)
            dp[i][i] = 1;
        for (int len = 2; len <= n; len++)
        {
            for (int i = 0; i + len - 1 < n; i++) {
                int j = i + len - 1;
                if (s[i] == s[j])
                    dp[i][j] = dp[i + 1][j - 1] + 2;
                else {
                    dp[i][j] = max(dp[i + 1][j], dp[i][j - 1]);
                }
            }
        }
        return dp[0][n - 1];
    }
}
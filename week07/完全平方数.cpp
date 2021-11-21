/**
 * leetcode [279.] 完全平方数
 *
 *
 * 输入：n = 12
输出：3
解释：12 = 4 + 4 + 4
链接：https://leetcode-cn.com/problems/perfect-squares/
 */
#include <bits/stdc++.h>

using namespace std;
class Solution
{
    /* 题解：完全背包
     */
public:
    int numSquares(int n) {
        long long val = sqrt(n);
        if (val * val == n)
            return 1;
        int num = floor(sqrt(n));
        vector<vector<int> > dp(num + 10, vector<int>(n + 10, 0));
        for (int i = 0; i <= num; i++) {
            for (int j = 0; j <= n; j++) {
                if (i == 0) {
                    dp[i][j] = INT_MAX;
                } else {
                    // 没有超过背包体积
                    if (j < i * i) {
                        dp[i][j] = dp[i - 1][j];
                    } else if (j == (i * i)) {
                        dp[i][j] = 1;
                    } else {
                        // 计算公式 如果有增加数量 
                        dp[i][j] = min(dp[i - 1][j], 1 + dp[i][j - (i * i)]);
                    }
                }
            }
        }
        return dp[num][n];
    }
}
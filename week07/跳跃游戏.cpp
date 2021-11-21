/**
 * leetcode [55.] 跳跃游戏
 *
 *
输入：nums = [2,3,1,1,4]
输出：true
解释：可以先跳 1 步，从下标 0 到达下标 1, 然后再从下标 1 跳 3 步到达最后一个下标。
链接：https://leetcode-cn.com/problems/jump-game/
 */
#include <bits/stdc++.h>

using namespace std;
class Solution
{
    /* 题解：简单的DP
        dp[i] 代表了下标为i的数组最远能够到达的位置，状态转移方程
        dp[i] = max(dp[i - 1], nums[i] + i)
        如果dp[i-1]>= n-1则说明前一个位置可以直接到达最后一个位置，返回 true
        如果dp[i-1]<i  则说明前一个位置无法到达当前位置 返回 false
     */
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        if (n == 1)
            return true;
        vector<int> dp(n, 0);
        dp[0] = nums[0];
        for (int i = 1; i < n; i++) {
            if (dp[i - 1] < i) { // 说明无法到达第i个位置
                return false;
            } else if (dp[i - 1] >= n - 1) { // 说明可以到达最后一个位置
                return true;
            } else {
                dp[i] = max(i + nums[i], dp[i - 1]);
            }
        }
        return false;
    }
}
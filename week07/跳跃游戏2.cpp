/**
 * leetcode [45.] 跳跃游戏2
 *
 输入: nums = [2,3,1,1,4]
输出: 2
解释: 跳到最后一个位置的最小跳跃数是 2。
     从下标为 0 跳到下标为 1 的位置，跳 1 步，然后跳 3 步到达数组的最后一个位置。

链接：https://leetcode-cn.com/problems/jump-game-ii
 */
#include <bits/stdc++.h>

using namespace std;
class Solution
{
    /* 题解：DP
        nums = [2,3,1,1,4]
        到达第0阶梯，无需跳跃，所以dp[0] = 0;
        到达第1阶梯，只能从第0阶梯跨一步，所以dp[1] = 1
        达到第2阶梯，因为0阶可以跨2步，1阶可以跨3步，所以从 0，1 都能到达2 怎么选 dp[2] = min（dp[0]，dp[1]）
        到达第3阶梯，1阶可以跨3步，所以从 1，2 都能到达3，怎么选dp[3] = min（dp[1]， dp[2]）
        所以总而言之，如何取得i阶梯的dp？就是从能到达i阶梯的途径中选出跳跃数最少的路径
     */
public:
    bool jump(vector<int>& nums) {
        int n = nums.size();
        if (n == 1)
            return 0;
        vector<int> dp(n, 0);
        dp[0] = nums[0];
        dp[1] = 1;
        for (int i = 2; i < n; i++) {
            // 创建一个变量来记录最小跳跃数
            int minb = 1e9;
            for (int j = 0; j < i; j++) {
                if (i - j <= nums[j]) {
                    dp[i] = min(dp[j] + 1, minb);
                    break;
                }
            }
        }
        return dp[n - 1];
    }
}
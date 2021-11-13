/**
 * [673.] 最长递增子序列的个数
 *
 *
 * 输入: [1,3,5,4,7]
输出: 2
解释: 有两个最长递增子序列，分别是 [1, 3, 4, 7] 和[1, 3, 5, 7]。
链接：https://leetcode-cn.com/problems/number-of-longest-increasing-subsequence/
 */
#include <bits/stdc++.h>

using namespace std;
class Solution
{
    /* 题解：动态规划   j 一直 在 追赶着 i ^_^
        1.定义状态
            dp[i]:到nums[i] 为止的最长递增子序列长度
            count[i]: 到nums[i]为止的最长递增子序列个数
        2.初始化状态
            dp = [1] * n：代表最长递增子序列的长度至少为1
            count = [1] * n：代表最长递增子序列的个数至少为1
        3.状态转移
            对于每一个数nums[i]，看在它之前的数 nums[j] （0 <= j < i）是否比当前nums[i]小
            如果nums[i] > nums[j], 那么相当于nums[j] 为止的最长递增子序列到nums[i]加了1
            到nums[i]为止的最长递增子序列长度就变成了 dp[i] = dp[j] + 1；
            但是因为满足nums[i] > nums[j] 的 nums[j] 不止一个，dp[i]应该是这些dp[j] + 1 的最大值
            并且这些dp[j] + 1 还会有相等的情况，一旦相等，到nums[i] 为止的最长递增子序列个数就应该增加了
            因此，具体的状态转移如下：在 nums[i] > nums[j] 的大前提下
                如果 dp[j] + 1 > dp[i] 说明最长递增子序列的长度增加了，dp[i] = dp[j] + 1，长度增加
                数量不变
                如果 dp[j] + 1 == dp[i] 说明最长递增子序列的长度没有增加，但是出现了长度一样的情况
                数量增加 count[i] += count[j]
        4.记录最长递增子序列的最大长度 max_lenght
        5.遍历dp数组，如果dp数组记录的最大长度dp[i] 等于 max_lenght 将对应的数量 count[i] 加入到 结果 res 中
     */
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n = nums.size();
        if (n == 1)
            return 1;
        vector<int> dp(n, 1);
        vector<int> count(n, 1);

        int maxLenght = 0;
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (nums[i] > nums[j]) {
                    if (dp[j] + 1 > dp[i]) {
                        dp[i] = dp[j] + 1;
                        count[i] = count[j];
                    } else if (dp[j] + 1 == dp[i]) {
                        count[i] += count[j];
                    }
                }
            }
            maxLenght = max(maxLenght, dp[i]);
        }
        int res = 0;
        for (int i = 0; i < n; i++) {
            if (dp[i] == maxLenght) {
                res += count[i];
            }
        }
        return res;
    }
}
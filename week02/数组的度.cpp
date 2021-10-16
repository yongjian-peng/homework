/**
 * 数组的度 leetcode 697  
 */
#include <bits/stdc++.h>

using namespace std;

class FindShortestSubArray{
    pubic:
        int findShortestSubArray(vector<int>& nums) {
            // 数组的度频率计数
            unordered_map<int, int> m;
            // 记录数组的元素开始的位置
            unordered_map<int, int> m1;
            // 数组的度初始化
            int degree = 0;
            // 返回结果初始化
            int ans = 0;
            for (int i = 0; i < nums.size(); i++) {
                if (m1.find(nums[i]) == m1.end()) {
                    m1[nums[i]] = i;
                }
                // 数组的度 ++
                m[nums[i]]++;

                // 如果数组的度有新增 则更新数组的度 更新 最短连续子数组的长度 
                if (m[nums[i]] > degree) {
                    degree = m[nums[i]];
                    // i 是最新的下标 下标相减 等于 子数组的长度 （妙）
                    ans = i - m1[nums[i]] + 1;
                } else if (m[nums[i]] == degree) {
                    // 如果数组的度 相等 则去最短连续子数组的 长度 因为数组的下标是从 0 开始的，所以 + 1
                    ans = min(ans, i - m1[nums[i]] + 1);
                }
            }
            return ans;
    }
};
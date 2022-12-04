/**
 * leetcode [239.] 滑动窗口最大值
 *
给你一个整数数组 nums，有一个大小为 k 的滑动窗口从数组的最左侧移动到数组的最右侧。你只可以看到在滑动窗口内的 k 个数字。滑动窗口每次只向右移动一位。

返回滑动窗口中的最大值。

输入：nums = [1,3,-1,-3,5,3,6,7], k = 3
输出：[3,3,5,5,6,7]
解释：
滑动窗口的位置                最大值
---------------               -----
[1  3  -1] -3  5  3  6  7       3
 1 [3  -1  -3] 5  3  6  7       3
 1  3 [-1  -3  5] 3  6  7       5
 1  3  -1 [-3  5  3] 6  7       5
 1  3  -1  -3 [5  3  6] 7       6
 1  3  -1  -3  5 [3  6  7]      7

链接：https://leetcode-cn.com/problems/sliding-window-maximum

 */
#include <bits/stdc++.h>

using namespace std;
class Solution
{
    /* 题解：有序集合 红黑树
     */
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> ans;
        if (nums.empty())
            return ans;
        // 将[0, 0+k-1]的k-1个元素加入到multiset中
        multiset<int> window(nums.begin(), nums.begin() + k - 1);
        for (int i = k - 1; i < nums.size(); i++) {
            // 插入，此时窗口有k个元素
            window.insert(nums[i]);
            // multiset 默认递增序列，获得最大值，存入ans
            ans.push_back(*window.rbegin());
            // 创建完集合后，集合的大小固定了，必须删除元素才能插入元素
            // (0, ..., i-k, [i-(k-1), ..., i-1, i], i+1, ..., n-1)
            // nums[i-k+1] 是窗口位置的第i个元素，需要被移除窗口
            // 10 - 8 = 2 ：..., 8, 9, 10, ...; i - (i-k+1) = k - 1
            window.erase(window.find(nums[i - (k - 1)]));
        }
        return ans;
    }
}
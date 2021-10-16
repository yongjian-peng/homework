/**
 * 和为k的子数组 leetcode 560
 */
#include <bits/stdc++.h>

using namespace std;

class SubarraySum{
    public:
        int subarraySum(vector<int>& nums, int k) {
            // 使用前缀和
            // 使用 map 和记录key 出现的频率记录为 值
            unordered_map<int, int> mp;
            mp[0] = 1;
            int count = 0, pre = 0;

            for (int i = 0; i < nums.size(); i++) {
                // 计算前缀和
                pre += nums[i];
                // 例：和 - k 就是之前循环中 和（出现的次数）
                if (mp.find(pre - k) != mp.end()) {
                    count += mp[pre - k];
                }
                // 以 和 为key 以出现的频率记录为 值
                mp[pre]++;
            }
            return count;
        }
};
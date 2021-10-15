#include <bits/stdc++.h>

using namespace std;

class TwoSum{
    public:
        vector<int> twoSum(vector<int>& nums, int target) {
            // 存储 值 和 下标数组 排序后原数组的下标会变 所以记录原数组的下标
            vector<pair<int, int> > pairs;
            for (int i = 0; i < nums.size(); i++) {
                pairs.push_back({nums[i], i});
            }

            // 使用双指针扫描方法，首先对记录数组排序
            sort(pairs.begin(), pairs.end());
            int j = nums.size() - 1;
            for (int i = 0; i < nums.size(); i++) {
                while (i < j && pairs[i].first + pairs[j].first > target)
                    j--;
                if (i < j && pairs[i].first + pairs[j].first == target)
                {
                    return {pairs[i].second, pairs[j].second};
                }
            }
            return {};
        }
};
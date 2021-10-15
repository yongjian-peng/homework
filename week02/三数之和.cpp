#include <bits/stdc++.h>

using namespace std;

class ThreeSum{
    public:
        vector<vector<int>> threeSum(vector<vector<int>>& nums, int target) {
            // 
            sort(nums.begin(), nums.end());
            vector<vector<int>> ans;
            int j = nums.size() - 1;

            for (int i = 0; i < nums.size(); i++) {
                if (i > 0 && nums[i] == nums[i - 1]) continue;
                // 得到两数相加的结果
                vector<vector<int>> jks = twoSum(nums, i + 1, -nums[i]);
                for (vector<vector<int>> jk : jks) {
                    ans.push_back({nums[i], jk[0], jk[1]});
                }

            }
            return ans;

        }

    private:
        vector<vector<int>> twoSum(vector<int> numbers, int start, int target) {
            // 记录结果 使用双指针扫描方式
            vector<vector<int>> ans;
            int j = numbers.size() - 1;
            for (int i = start; i < numbers.size(); i++) {
                // 去处重复的结果
                if (i > start && numbers[i] == numbers[i - 1]) continue;
                // 如果 两数相加的和 大于 target 那么 数组是有序的，则指针移动
                while (i < j && numbers[i] + numbers[j] > target) j--;
                if (i < j && numbers[i] + numbers[j] == target) {
                    ans.push_back({numbers[i],numbers[j]});
                }

            }
            return ans;
        }
};

/**
 * [154.] 寻找旋转排序数组中的最小值 II
输入: nums = [3,3,1,3]
输出: 1
链接：https://leetcode-cn.com/problems/find-minimum-in-rotated-sorted-array-ii/
 */
#include <bits/stdc++.h>

using namespace std;
class Solution
{
    
public:
    int findMin(vector<int>& nums) {
        int left = 0, right = nums.size() - 1;
        while (left < right) {
            int mid = (left + right) >> 1;
            if (nums[mid] < nums[right]) {
                right = mid;
            } else if (nums[mid] > nums[right]) {
                left = mid + 1;
            } else {
                right--;
            }
        }
        return nums[right];
    }
}
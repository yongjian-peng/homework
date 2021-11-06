/**
 * [74.] 搜索二维矩阵
输入：matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]], target = 3
输出：true

链接：https://leetcode-cn.com/problems/search-a-2d-matrix/
 */
#include <bits/stdc++.h>

using namespace std;
class Solution
{

public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if (!matrix.size())
            return false;
        m = matrix.size();
        n = matrix[0].size();
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                arrays.push_back(matrix[i][j]);
            }
        }
        int left = 0, right = arrays.size() - 1;
        while (left <= right) {
            int mid = (left + right) >> 1;
            if (arrays[mid] == target) {
                return true;
            } else if (arrays[mid] < target) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return false;
    }

private:
    int m, n;
    vector<int> arrays;
}
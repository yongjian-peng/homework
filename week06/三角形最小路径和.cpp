/**
 * [120.] 三角形最小路径和
 *
 * 输入：triangle = [[2],[3,4],[6,5,7],[4,1,8,3]]
输出：11
解释：如下面简图所示：
   2
  3 4
 6 5 7
4 1 8 3
自顶向下的最小路径和为 11（即，2 + 3 + 5 + 1 = 11）。
链接：https://leetcode-cn.com/problems/triangle
 */
#include <bits/stdc++.h>

using namespace std;
class Solution
{
    /* 题解：动态规划
        公式：f[i][j] = min(f[i + 1][j],f[i + 1][j + 1]) + triangle[i][j]
     */
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        // 三角形从下到上 可以省去数组的越界判断
        for (int i = triangle.size() - 2; i >= 0; i--) {
            for (int j = 0; j <= i; j++) {
                triangle[i][j] += min(triangle[i + 1][j], triangle[i + 1][j + 1]);
            }
        }
        return triangle[0][0];
    }
}
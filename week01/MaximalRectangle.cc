#include <bits/stdc++.h>

using namespace std;

class MaximalRectangle {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        // 先转换成柱状图，然后求柱状图中的最大的矩形
        // 操作当前柱，取左边最高 和 右边最高 然后 取最小高度 乘以宽度
        // 宽度如果是连续的，是对应增加的
        // 求 行 列
        int m = matrix.size();
        if (m == 0) {
            return 0;
        }
        int n = matrix[0].size();
        vector<vector<int>> left(m, vector<int>(n,0));

        for(int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (matrix[i][j] == '1') {
                    left[i][j] = (j == 0 ? 0 : left[i][j - 1]) + 1;
                }
            }
        }
        int ret = 0;
        for (int j = 0; j < n; j++) { // 对于每一列 使用基于柱状图的方法
            vector<int> up(m,0), down(m, 0);
            stack<int> stk;
            // 求左边最大值
            for (int i = 0; i < m; i++) {
                while (!stk.empty() && left[stk.top()][j] >= left[i][j]) {
                    stk.pop();
                }
                
                up[i] = stk.empty() ? -1 : stk.top();
                stk.push(i);
            }
            
            stk = stack<int>();
            // 求右边最大值
            for (int i = m - 1; i >= 0; i--) {
                while (!stk.empty() && left[stk.top()][j] >= left[i][j]) {
                    stk.pop();
                }
                down[i] = stk.empty() ? -1 : stk.top();
                
                stk.push(i);
            }

            for (int i = 0; i < m; i++) {   
                int height = down[i] - up[i] - 1;
                int area = height * left[i][j];
                // 取最大的面积
                ret = max(ret, area);
            }
        }

        return ret;
    }
};
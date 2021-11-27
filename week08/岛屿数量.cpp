/**
 * leetcode [200.] 岛屿数量
 *
输入：grid = [
  ["1","1","1","1","0"],
  ["1","1","0","1","0"],
  ["1","1","0","0","0"],
  ["0","0","0","0","0"]
]
输出：1
链接：https://leetcode-cn.com/problems/number-of-islands

 */
#include <bits/stdc++.h>

using namespace std;
class Solution
{
    /* 题解：使用并查集 是否在同一个集合里面（带头大哥）
     */
public:
    int numIslands(vector<vector<char>>& grid) {
        if (!grid.size())
            return 0;
        rows = grid.size();
        cols = grid[0].size();
        // 定义方向数组
        const int dx[4] = {-1, 0, 0, 1};
        const int dy[4] = {0, -1, 1, 0};
        // 初始化并查集
        fa = vector<int>(rows * cols + 1, 0);
        for (int i = 0; i < rows * cols + 1; i++)
            fa[i] = i;
        for (int i = 0; i < rows; i++)
            for (int j = 0; j < cols; j++) {
                if (grid[i][j] == '0')
                    continue;
                for (int k = 0; k < 4; k++) {
                    int ni = i + dx[k];
                    int nj = j + dy[k];
                    // 是否越界
                    if (ni >= rows || nj >= cols || ni < 0 || nj < 0)
                        continue;
                    if (grid[ni][nj] == '1') {
                        unioSet(num(i, j), num(ni, nj));
                    }
                }
            }

        int ans = 0;
        for (int i = 0; i < rows; i++)
            for (int j = 0; j < cols; j++) {
                // 如果是 1 并且父类指向的是自己，那么就是新区域
                if (grid[i][j] == '1' && fa[num(i, j)] == num(i, j))
                    ans++;
            }

        return ans;
    }

private:
    int find(int x) {
        if (x == fa[x])
            return x;
        return fa[x] = find(fa[x]);
    }
    void unioSet(int x, int y) {
        x = find(x), y = find(y);
        if (x != y)
            fa[x] = y;
    }
    // 二维矩阵转数组
    int num(int i, int j) {
        return i * cols + j;
    }
    int rows, cols;
    vector<int> fa;
}
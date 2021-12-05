/**
 * leetcode [1091.] 二进制矩阵中的最短路径
 *
给你一个 n x n 的二进制矩阵 grid 中，返回矩阵中最短 畅通路径 的长度。如果不存在这样的路径，返回 -1 。

二进制矩阵中的 畅通路径 是一条从 左上角 单元格（即，(0, 0)）到 右下角 单元格（即，(n - 1, n - 1)）的路径，该路径同时满足下述要求：

路径途经的所有单元格都的值都是 0 。
路径中所有相邻的单元格应当在 8 个方向之一 上连通（即，相邻两单元之间彼此不同且共享一条边或者一个角）。
畅通路径的长度 是该路径途经的单元格总数。

输入：grid = [[0,1],[1,0]]
输出：2

链接：https://leetcode-cn.com/problems/shortest-path-in-binary-matrix
 */
#include <bits/stdc++.h>

using namespace std;
class Solution
{
    /* 题解：双向 BFS
     */
public:
    int shortestPathVinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size() - 1;
        if (grid[0][0] != 0 || grid[n][n] != 0)
            return -1;
        if (grid.size() == 1)
            return 1;
        // 8个方向数组
        int vec[8][2] = {{0, -1}, {1, -1}, {1, 0}, {1, 1}, {0, 1}, {-1, 1}, {-1, 0}, {-1, -1}};

        int count = 2;
        queue<Point> q1, q2;
        q1.push(Point(0, 0));
        grid[0][0] = 2;
        q2.push(Point(n, n));
        grid[n][n] = 3;
        Point cur;
        Point next;
        int layer_num = 0;

        while (!q1.empty() && !q2.empty()) {
            layer_num = q1.size();
            for (int i = 0; i < layer_num; i++) {
                cur = q1.front();
                q1.pop();
                for (int j = 0; j < 8; j++) {
                    next.x = cur.x + vec[j][0];
                    next.y = cur.y + vec[j][1];
                    if (next.x >= 0 && next.x <= n && next.y >= 0 && next.y <= n) {
                        // 如果相遇了，则直接返回
                        if (grid[next.x][next.y] == 3) {
                            return count;
                        }
                        if (grid[next.x][next.y] == 0) {
                            q1.push(next);
                            grid[next.x][next.y] = 2;
                        }
                    }
                }
            }
            count++;
            layer_num = q2.size();
            for (int i = 0; i < layer_num; i++) {
                cur = q2.front();
                q2.pop();
                for (int j = 0; j < 8; j++) {
                    next.x = cur.x + vec[j][0];
                    next.y = cur.y + vec[j][1];
                    if (next.x >= 0 && next.x <= n && next.y >= 0 && next.y <= n) {
                        // 如果相遇了则 直接返回
                        if (grid[next.x][next.y] == 2) {
                            return count;
                        }
                        if (grid[next.x][next.y] == 0) {
                            q2.push(next);
                            grid[next.x][next.y] = 3;
                        }
                    }
                }
            }
            count++;
        }
        return -1;
    }

private:
    struct Point {
        int x, y;
        Point() {}
        Point(int val_x, int val_y) : x(val_x), y(val_y) {}
    };
}
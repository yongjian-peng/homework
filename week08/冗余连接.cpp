/**
 * leetcode [684.] 冗余连接
 *
输入: edges = [[1,2], [1,3], [2,3]]
输出: [2,3]

链接：https://leetcode-cn.com/problems/redundant-connection/
 */
#include <bits/stdc++.h>

using namespace std;
class Solution
{
    /* 题解：使用并查集
     */
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        // 并查集题解方法
        int n = edges.size();
        // 初始化并查集
        fa = vector<int>(n + 1, 0);
        for (int i = 0; i < n; i++)
            fa[i] = i;
        for (auto& edge : edges) {
            if (find(edge[0]) == find(edge[1]))
                return edge;
            else
                unioSet(edge[0], edge[1]);
        }

        return edges[0];
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
    vector<int> fa;
}
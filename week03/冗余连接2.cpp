
/**
 * [685.] 冗余连接 II  
 * https://leetcode-cn.com/problems/redundant-connection-ii/
 */
#include <bits/stdc++.h>

using namespace std;

/**
输入：edges = [[1,2],[2,3],[3,4],[4,1],[1,5]]
输出：[4,1]
输入：edges = [[2,1],[3,1],[4,2],[1,4]]
输出：[2, 1]
    */
class Solution
{
public:
    vector<int> findRedundantDirectedConnection(vector<vector<int>>& edges) {
        int intDegeree[N] = {0}; // 记录节点的入度
        n = edges.size(); // 边的数量
        for (int i = 0; i < n; i++) {
            intDegeree[edges[i][1]]++; // 统计入度
        }
        vector<int> vec; // 记录入度为2的边 （如果有的话就是两条边）
        // 找入度为2的节点所对应的边，主要要倒序，因为优先返回最后出现在二维数组中的答案
        for (int i = n - 1; i >= 0; i--) {
            if (intDegeree[edges[i][1]] == 2) {
                vec.push_back(i);
            }
        }
        // 如果有入度为2的节点，那么一定是两条边里删除一个，看删除哪个可以构成树
        if (vec.size() > 0) {
            if (isTreeAfterRemoveEdge(edges, vec[0]))
            {
                return edges[vec[0]];
            }
            else
            {
                return edges[vec[1]];
            }
        }
        // 明确没有入度为2的情况，那么一定有有向环，找到构成环的边 返回就可以了
        return getRemoveEdge(edges);
    }

private:
    static const int N = 1010;
    int father[N];
    int n; // 边的数量
    // 并查集初始化
    void init() {
        for (int i = 1; i <= n; ++i) {
            father[i] = i;
        }
    }
    // 并查集里寻根的过程 寻找带头大哥
    int find(int u) {
        return u == father[u] ? u : father[u] = find(father[u]);
    }
    // 将v->u 这条边加入并查集
    void join(int u, int v) {
        u = find(u);
        v = find(v);
        if (u == v) {
            return;
        }
        father[v] = u; // v 的父亲 u 合并帮派 
    }
    // 判断 u 和 v 是否在同一个根中 是否在同一个帮派中
    bool same(int u, int v) {
        u = find(u);
        v = find(v);
        return u == v;
    }
    // 在有向图里找到删除的那条边 使其变成树
    vector<int> getRemoveEdge(const vector<vector<int>>& edges) {
        init(); // 初始化并查集
        for (int i = 0; i < n; i++) {
            if (same(edges[i][0], edges[i][1])) { 
                return edges[i];
            }
            join(edges[i][0], edges[i][1]);
        }
        return {};
    }
    // 删一条边之后判断是不是树
    bool isTreeAfterRemoveEdge(const vector<vector<int>>& edges, int deleteEdge) {
        init(); // 初始化并查集
        for (int i = 0; i < n; i++) {
            if (i == deleteEdge)
                continue;
            if (same(edges[i][0], edges[i][1])) {
                return false;
            }
            join(edges[i][0], edges[i][1]);
        }
        return true;
    }
}
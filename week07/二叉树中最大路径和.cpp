/**
 * leetcode [124.] 二叉树中最大路径和
 *
输入：root = [1,2,3]
输出：6
解释：最优路径是 2 -> 1 -> 3 ，路径和为 2 + 1 + 3 = 6

https://leetcode-cn.com/problems/binary-tree-maximum-path-sum/
 */
#include <bits/stdc++.h>

using namespace std;
class Solution
{
    /* 题解：DP
        转移方程：dp[i][j] = max(dp[i+1][j], dp[i][j-1]);
        初始值：dp[0][0] = 0; 目标值： dp[0][n-1]
     */
    /**
     * Definition for a binary tree node.
     * struct TreeNode {
     *     int val;
     *     TreeNode *left;
     *     TreeNode *right;
     *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
     * };
     */
public:
    int maxPathSum(TreeNode* root) {
        val = INT_MIN;

        dfs(root);
        return val;
    }

private:
    int dfs(TreeNode* root) {
        if (root == nullptr)
            return 0;
        int left = max(0, dfs(root->left));
        int right = max(0, dfs(root->right));

        int lmr = left + root->val + right;
        // 返回路径中的最大和 单支 路径中只能走一边（包括自己）
        int ret = root->val + max(0, max(left, right));
        // 节点的最大和
        val = max(val, max(lmr, ret));
        return ret;
    }
    int val;
}
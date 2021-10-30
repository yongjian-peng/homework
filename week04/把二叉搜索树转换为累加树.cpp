/**
 * [538.] 把二叉搜索树转换为累加树 先遍历右子树 根 左子树顺序 就是倒序 
 * 链接：https://leetcode-cn.com/problems/convert-bst-to-greater-tree
 */
#include <bits/stdc++.h>

using namespace std;

/**
输入：[4,1,6,0,2,5,7,null,null,null,3,null,null,null,8]
输出：[30,36,21,36,35,26,15,null,null,null,33,null,null,null,8]
    */
class Solution
{
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
    TreeNode *convertBST(TreeNode *root)
    {
        if (root == nullptr) {
            return nullptr;
        }
        convertBST(root->right);
        curr_sum += root->val;
        root->val = curr_sum;
        convertBST(root->left);
        return root;
    }

private:
    int curr_sum = 0;
}
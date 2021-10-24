
/**
 * [106.] 从中序与后序遍历序列构造二叉树
 */
#include <bits/stdc++.h>

using namespace std;

/**
 输入：
 中序遍历 inorder = [9,3,15,20,7]
后序遍历 postorder = [9,15,7,20,3]
 输出：[3,9,20,null,null,15,7]
 */
class Solution
{
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        this->inorder = inorder;
        this->postorder = postorder;
        return build(0, inorder.size() - 1, 0, postorder.size() - 1);
    }

private:
    TreeNode* build(int l1, int r1, int l2, int r2) {
        if (l1 > r1 || l2 > r2)
            return nullptr;
        // 后序遍历 最后一个元素是根
        TreeNode *root = new TreeNode(postorder[r2]);

        // 求根在的位置
        int mid = l1;
        while (inorder[mid] != root->val)
            mid++;
        
    // l1~mid-1 左子树的中序
    // mid+1~r2 右子树的中序
        root->left = build(l1, mid - 1, l2, l2 + mid - l1 - 1);
        root->right = build(mid + 1, r1, r2 - (r1 - mid), r2 - 1);
        return root;
    }
    vector<int> inorder;
    vector<int> postorder;
}
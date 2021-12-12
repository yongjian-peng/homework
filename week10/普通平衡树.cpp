/**
 * acwing [253.] 普通平衡树
 *
您需要写一种数据结构（可参考题目标题），来维护一些数，其中需要提供以下操作：

插入数值 x。
删除数值 x(若有多个相同的数，应只删除一个)。
查询数值 x 的排名(若有多个相同的数，应输出最小的排名)。
查询排名为 x 的数值。
求数值 x 的前驱(前驱定义为小于 x 的最大的数)。
求数值 x 的后继(后继定义为大于 x 的最小的数)。
注意： 数据保证查询的结果一定存在。

输入格式
第一行为 n，表示操作的个数。

接下来 n 行每行有两个数 opt 和 x，opt 表示操作的序号(1≤opt≤6)。

输出格式
对于操作 3,4,5,6 每行输出一个数，表示对应答案。

数据范围
1≤n≤100000,所有数均在 −107 到 107 内。

输入样例：
8
1 10
1 20
1 30
3 20
4 2
2 10
5 25
6 -1
输出样例：
2
20
20
20

链接：https://www.acwing.com/problem/content/description/255/
 */
#include <bits/stdc++.h>

using namespace std;

struct Node {
    Node *left; // 左孩子
    Node *right; // 右孩子
    int key, val; // 节点关键码（原始数组）随机权值
    int cnt, size; // 副本数、子树大小

    Node(int data) {
        key = data;
        val = rand();
        cnt = size = 1;
        left = right = nullptr;
    }
};

class Treap {
public:
    Treap() {
        // 建立一个空 Treap 包含两个保护节点
        root = new Node(-1e9);
        root->right = new Node(1e9);
        update(root);
    }
    // 插入
    void Insert(int data) {
        root = Insert(root, data);
    }
    // 删除
    void Remove(int data) {
        root = Remove(root, data);
    }
    // 查询target的排名
    int GetRankByVal(int target) {
        // 有保护节点所以 减 1
        return GetRankByVal(root, target) - 1;
    }
    // 查询排第rank名的元素
    int GetValByRank(int rank) {
        // 有保护节点，所以减1
        return GetValByRank(root, rank + 1);
    }
    // 查找target的前驱（小于target的最大的数）
    int GetPre(int target) {
        int ans = -1e9;
        Node *p = root;
        while (p)
        {
            if (target == p->key)
            {
                // 检索到了target且有左子树，因该在左子树中一路向右走
                if (p->left)
                {
                    p = p->left;
                    while (p->right)
                        p = p->right;
                    ans = p->key;
                }
                break;
            }
            //  若最终检索不到target 答案就在途中的节点中（小于target的最大数）
            if (p->key < target && p->key > ans)
                ans = p->key;
            p = target < p->key ? p->left : p->right;
        }
        return ans;
    }
    // 查找target的后继（大于target的最小数）
    int GetNext(int target) {
        int ans = 1e9;
        Node *p = root;
        while (p) {
            if (target == p->key) {
                // 检索到了 target 且有右子树，应该在右子树一直向左走
                if (p->right) {
                    p = p->right;
                    while (p->left)
                        p = p->left;
                    ans = p->key;
                }
                break;
            }
            // 若最终检索不到target 答案就在途中的节点中 （大于target的最小数
            if (p->key > target && p->key < ans)
                ans = p->key;
            p = target < p->key ? p->left : p->right;
        }
        return ans;
    }

private:
    // 在以p为根的左子树中查询target的排名
    int GetRankByVal(Node* p, int target) {
        int left_size = p->left ? p->left->size : 0;
        if (p->key == target)
            return left_size + 1;
        else if (target < p->key)
            return GetRankByVal(p->left, target);
        else
            return left_size + p->cnt + GetRankByVal(p->right, target);
    }
    // 在以p为根的子树中查询排 rank 名的排序
    int GetValByRank(Node* p, int rank) {
        int left_size = p->left ? p->left->size : 0;
        if (rank <= left_size)
            return GetValByRank(p->left, rank);
        else if (rank <= left_size + p->cnt)
            return p->key;
        else
            return GetValByRank(p->right, rank - left_size - p->cnt);
    }
    // 在以p为根的左子树中插入 data 返回新的根
    Node* Insert(Node* p, int data) {
        if (p == nullptr) {
            return new Node(data);
        }
        if (data == p->key) {
            p->cnt++;
        } else if (data < p->key) {
            p->left = Insert(p->left, data);
            if (p->val < p->left->val)
                p = zig(p);
        } else {
            p->right = Insert(p->right, data);
            if (p->val < p->right->val)
                p = zag(p);
        }
        update(p);
        return p;
    }
    // 在以p为根的左子树中 删除 data 返回新的根
    Node* Remove(Node* p, int data) {
        if (p == nullptr)
            return nullptr;
        if (data == p->key) {
            if (p->cnt > 1)
                p->cnt--;
            else {
                if (!p->left && !p->right) {
                    delete p;
                    return nullptr;
                }
                if (!p->right || (p->left && p->left->val > p->right->val)) {
                    p = zig(p);
                    p->right = Remove(p->right, data);
                } else {
                    p = zag(p);
                    p->left = Remove(p->left, data);
                }
            }
        } else if (data < p->key) {
            p->left = Remove(p->left, data);
        } else {
            p->right = Remove(p->right, data);
        }
        if (p)
            update(p);
        return p;
    }
    // p的左孩子绕p向右旋转
    Node* zig(Node* p) {
        Node *q = p->left;
        p->left = q->right;
        q->right = p;
        update(p);
        update(q);
        return q;
    }
    // p的右孩子绕p左旋转
    Node* zag(Node* p) {
        Node *q = p->right;
        p->right = q->left;
        q->left = p;
        update(p);
        update(q);
        return q;
    }
    // 更新节点p的附加信息（本题中的size）
    void update(Node* p) {
        int left_size = p->left ? p->left->size : 0;
        int right_size = p->right ? p->right->size : 0;
        p->size = left_size + right_size + p->cnt;
    }
    Node *root;
};

int main()
{
    Treap treap;
    int n;
    cin >> n;
    while (n--) {
        int opt, x;
        scanf("%d%d", &opt, &x);
        switch (opt)
        {
            case 1:
                treap.Insert(x);
                break;
            case 2:
                treap.Remove(x);
                break;
            case 3:
                printf("%d\n",treap.GetRankByVal(x));
                break;
            case 4:
                printf("%d\n", treap.GetValByRank(x));
                break;
            case 5:
                printf("%d\n", treap.GetPre(x));
                break;
            case 6:
                printf("%d\n", treap.GetNext(x));
                break;
            default:
                printf("default");
                break;
            }
    }
}
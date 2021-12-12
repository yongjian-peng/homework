/**
 * leetcode [1206.] 设计跳表
 *
不使用任何库函数，设计一个跳表。

跳表是在 O(log(n)) 时间内完成增加、删除、搜索操作的数据结构。跳表相比于树堆与红黑树，其功能与性能相当，并且跳表的代码长度相较下更短，其设计思想与链表相似。
跳表中有很多层，每一层是一个短的链表。在第一层的作用下，增加、删除和搜索操作的时间复杂度不超过 O(n)。跳表的每一个操作的平均时间复杂度是 O(log(n))，空间复杂度是 O(n)。

在本题中，你的设计应该要包含这些函数：

bool search(int target) : 返回target是否存在于跳表中。
void add(int num): 插入一个元素到跳表。
bool erase(int num): 在跳表中删除一个值，如果 num 不存在，直接返回false. 如果存在多个 num ，删除其中任意一个即可。
Skiplist skiplist = new Skiplist();

skiplist.add(1);
skiplist.add(2);
skiplist.add(3);
skiplist.search(0);   // 返回 false
skiplist.add(4);
skiplist.search(1);   // 返回 true
skiplist.erase(0);    // 返回 false，0 不在跳表中
skiplist.erase(1);    // 返回 true
skiplist.search(1);   // 返回 false，1 已被擦除

链接：https://leetcode-cn.com/problems/design-skiplist
 */
#include <bits/stdc++.h>

using namespace std;

struct Node {
    Node *right, *down;
    int val;
    Node(Node *right, Node *down, int val): right(right), down(down), val(val) {}
}

class Skiplist
{
public:
    Skiplist() {
        head = new Node(nullptr, nullptr, 0);
    }

    bool search(int target) {
        Node *p = head;
        while (p) {
            while (p->right && p->right->val < target)
                p = p->right;
            if (!p->right || p->right->val > target)
                p = p->down;
            else
                return true;
        }
        return false;
    }

    void add(int num) {
        insertPoints.clear();
        Node *p = head;
        while (p) {
            while (p->right && p->right->val < num)
                p = p->right;
            insertPoints.push_back(p);
            p = p->down;
        }
        Node *downNode = nullptr;
        bool insertUp = true;
        while (insertUp && insertPoints.size()) {
            Node *ins = insertPoints.back();
            insertPoints.pop_back();

            ins->right = new Node(ins->right, downNode, num);
            downNode = ins->right;

            insertUp = (rand() & 1) == 0;
        }
        if (insertUp) {
            head = new Node(new Node(nullptr, downNode, num), head, 0);
        }
    }
    bool earse(int num) {
        Node *p = head;
        bool seen = false;
        while (p) {
            while (p->right && p->right->val < num)
                p = p->right;
            if (!p->right || p->right->val > num)
                p = p->down;
            else {
                seen = true;
                p->right = p->right->right;
                p = p->down;
            }
        }
        return seen;
    }

private:
    Node *head;
    vector<Node *> insertPoints;
}
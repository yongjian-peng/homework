#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr){}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class MergeTwoLists
{
    public:
        ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
            // 创建保护节点
            ListNode *pre = new ListNode(-1);
            ListNode *res = pre;
            // 循环链表
            while (l1 != nullptr && l2 != nullptr) {
                // 取小值 放入到新的链表中，然后向后移动指针
                if (l1->val < l2->val) {
                    res->next = l1;
                    l1 = l1->next;
                } else {
                    res->next = l2;
                    l2 = l2->next;
                }
                // 移动存储链表
                res = res->next;
            }

            // 
            res->next = l1 == nullptr ? l2 : l1;

            return pre->next;
        }
};
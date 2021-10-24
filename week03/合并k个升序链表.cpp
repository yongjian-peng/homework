/**
 * [23.] 合并K个升序链表
 */
#include <bits/stdc++.h>

using namespace std;

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
    public:
        ListNode* mergeKLists(vector<ListNode*>& lists) {
            return merge(lists, 0, lists.size() - 1);
        }

    private:
        ListNode* merge(vector<ListNode*>& lists, int l, int r) {
            if (l == r)
                return lists[l];
            if (l > r)
                return nullptr;
            int mid = (l + r) >> 1; // 分治解法 左边到中间点  中间点到右边
            return mergeTwoLists(merge(lists, l, mid), merge(lists, mid + 1, r));
        }

        // 合并两个链表
        ListNode* mergeTwoLists(ListNode* a, ListNode* b) {
            if ((!a) || (!b))
                return a ? a : b;
            ListNode head, *tail = &head, *aPtr = a, *bPtr = b;
            while (aPtr && bPtr) {
                if (aPtr->val < bPtr->val) {
                    tail->next = aPtr;
                    aPtr = aPtr->next;
                } else {
                    tail->next = bPtr;
                    bPtr = bPtr->next;
                }
                tail = tail->next;
            }
            tail->next = (aPtr ? aPtr : bPtr);
            return head.next;
        }
}
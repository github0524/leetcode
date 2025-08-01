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

#include "datatype.h"
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* tmp = nullptr;
        tmp = head;
        while (tmp!=nullptr)
        {
            ListNode *newnode = new ListNode(tmp->val, prev);
            tmp = tmp->next;
            prev = newnode;
        }
        return prev;
    }
};
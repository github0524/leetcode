#include <iostream>
#include "datatype.h"

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
//1 2 3 4  1  3  2 4
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        ListNode* tmp2 = nullptr;
        ListNode* tmp = nullptr;

        ListNode* newhead = new ListNode(0, head);
        ListNode* cur = newhead;
        while (cur->next != nullptr)
        {
            //两个节点
            if (cur->next->next != nullptr)
            {
                tmp = cur->next;//保留2
                tmp2 = cur->next->next->next;//保留4
                cur->next = cur->next->next;//1 3
                cur->next->next = tmp;//3 2 
                cur->next->next->next = tmp2;//2 4
                cur = cur->next->next;
            }
            else//一个节点
            {
                break;
            }
        }
        return newhead->next;
    }
};
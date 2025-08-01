#include "datatype.h"
#include <stack>
#include <vector>

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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* prev = nullptr;
        ListNode* cur = head;
        stack<ListNode*> stk;
        while (cur != nullptr)
        {
            stk.push(cur);
            cur = cur->next;
        }
        while (n)
        {
            cur = stk.top();
            stk.pop();
            n--;
            if (n==0)
            {
                if (stk.size() != 0) {
                    prev = stk.top();
                    prev->next = cur->next;
                    return head;
                }
                else
                {
                    return cur->next;
                }
            }
        }
        return head;
    }
};

int main()
{
    vector<int> arr{ 1,2,3,4,5 };
    Solution so;
    ListNode* head = new ListNode(0, nullptr);
    ListNode* cur = head;
    for (int i = 0; i < arr.size(); i++)
    {
        cur->next = new ListNode(arr[i], nullptr);
        cur = cur->next;
    }
    so.removeNthFromEnd(head->next, 2);
    return 0;
}
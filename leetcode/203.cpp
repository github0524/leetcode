#include <vector>
#include <iostream>
#include "datatype.h"

class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        if (head == nullptr) {
            return head;
        }
        head->next = removeElements(head->next, val);//可以理解为我的next（传入），是next还是next->next，看下一句，有两种返回可能
        return head->val == val ? head->next : head;
    }
};

using namespace std;

void printList(ListNode* head) {
    while (head != nullptr) {
        std::cout << head->val << " ";
        head = head->next;
    }
    std::cout << std::endl;
}

int main()
{
    Solution so;
    int arr[] = { 1, 2, 6, 3, 4, 5, 6 };
    int n = sizeof(arr) / sizeof(arr[0]);

    // 尾插法创建链表（使用哑节点简化操作）
    ListNode* dummy = new ListNode(0); // 创建哑节点
    ListNode* tail = dummy;            // 尾指针初始指向哑节点

    for (int i = 0; i < n; ++i) {
        tail->next = new ListNode(arr[i]); // 创建新节点并链接
        tail = tail->next;                 // 移动尾指针
    }

    ListNode* head = dummy->next; // 真实头节点
    printList(head);              // 输出: 1 2 6 3 4 5 6
    printList(head);              // 输出: 1 2 6 3 4 5 6
    so.removeElements(head, 6);
    return 0;
}
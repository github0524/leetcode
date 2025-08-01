#include <vector>
#include <iostream>
#include "datatype.h"

class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        if (head == nullptr) {
            return head;
        }
        head->next = removeElements(head->next, val);//�������Ϊ�ҵ�next�����룩����next����next->next������һ�䣬�����ַ��ؿ���
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

    // β�巨��������ʹ���ƽڵ�򻯲�����
    ListNode* dummy = new ListNode(0); // �����ƽڵ�
    ListNode* tail = dummy;            // βָ���ʼָ���ƽڵ�

    for (int i = 0; i < n; ++i) {
        tail->next = new ListNode(arr[i]); // �����½ڵ㲢����
        tail = tail->next;                 // �ƶ�βָ��
    }

    ListNode* head = dummy->next; // ��ʵͷ�ڵ�
    printList(head);              // ���: 1 2 6 3 4 5 6
    printList(head);              // ���: 1 2 6 3 4 5 6
    so.removeElements(head, 6);
    return 0;
}
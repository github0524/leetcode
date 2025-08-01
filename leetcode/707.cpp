#include "datatype.h"
#include <iostream>

using namespace std;

class MyLinkedList {
public:
    MyLinkedList() {
        this->len = 0;
        this->head = nullptr;
    }

    int get(int index) {
        ListNode* tmphead = head;
        if (index < 0||index>len-1) return -1;
        while (index > 0)
        {
            tmphead = tmphead->next;
            index--;
        }
        return tmphead->val;
    }

    void addAtHead(int val) {
        ListNode* newhead = new ListNode(val,this->head);
        head = newhead;
        (this->len)++;
    }

    void addAtTail(int val) {
        ListNode* tmphead = head;
        ListNode* tail = new ListNode(val , nullptr);
        if (len==0)
        {
            head = tail;
            len++;
            return;
        }
        while (tmphead->next != nullptr)
        {
            tmphead = tmphead->next;
        }
        tmphead->next = tail;
        len++;
    }

    void addAtIndex(int index, int val) {
        ListNode* tmphead = head;
        if (index <= 0) {
            addAtHead(val);
            return;
        }
        if (index>len)
        {
            return;
        }
        if (index==len)
        {
            addAtTail(val);
            return;
        }
        ListNode *newNode = new ListNode(val, nullptr);
        while (index > 1)
        {
            tmphead = tmphead->next;
            index--;
        }
        ListNode* next = tmphead->next;
        tmphead->next = newNode;
        newNode->next = next;
        len++;

    }

    void deleteAtIndex(int index) {
        ListNode* tmphead = head;
        if (index<0||index>len-1)
        {
            return;
        }
        if (index==0)
        {
            head = head->next;
            len--;
        }
        else
        {
            while (index > 1) {
                tmphead = tmphead->next;
                index--;
            }
            tmphead->next = tmphead->next->next;
            len--;
        }
    }

    int len;
    ListNode *head;
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */

int main()
{
    //1270
    MyLinkedList* obj = new MyLinkedList();
    obj->addAtHead(7);
    obj->addAtHead(2);
    obj->addAtHead(1);
    obj->addAtIndex(3, 0);
    obj->deleteAtIndex(2);
    obj->addAtHead(6);
    obj->addAtTail(4);
    int param_2 = obj->get(4);

    return 0;
    //obj->addAtTail(3);
    //obj->addAtIndex(1, 2);
    //obj->deleteAtIndex(1);
    //int param_2 = obj->get(1);
}
//#define   _CRT_SECURE_NO_WARNINGS 

#include <chrono>
#include <iostream>
#include <vector>
#include <stack>
using namespace std;

struct ListNode {
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
 };
 
/*�ܽ�*/
/*�ٷ�����ж�����Ŀյ��ж�����Ȼ�ļ�Լ�ģ�ֱ�Ӵ�����Ϳ�ʼ�ж��Ƿ���������Ϊ�գ�˳������߼���ȥ����*/
/*�����Լ���Ĭ�ϵ�һ����Ϊ�գ��ӵڶ�����ʼ�жϣ�����Ū�ɳɷ�*/
/*ListNode��ʼ�����ƣ�new��ʹ��*/
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        /**/
        int plus = 0;/*��Ӵ���10*/
        ListNode* l3 = new ListNode();
        ListNode* l = l3;
        int sum = 0;
        int a1, a2;
        /*�ǿ������һ�����*/
        sum = l1->val + l2->val;
        plus = sum >= 10 ? 1 : 0;
        l3->val = sum % 10;
        while (l1->next != nullptr || l2->next != nullptr) {
            a1 = 0;
            a2 = 0;
            if (l1->next != nullptr) {
                l1 = l1->next;
                a1 = l1->val;
            }            
            if (l2->next != nullptr) {
                l2 = l2->next;
                a2 = l2->val;
            }

            sum = a1 + a2;
            if (plus == 1) {/*����ûʲô���ж��ģ�ֱ��������+��û�о�+0*/
                sum += 1;
                plus = 0;
            }
            plus = sum >= 10 ? 1 : 0;/*ֱ��/10*/
            //ListNode* temp = new ListNode(sum % 10);
            //l3->next = temp;
            //l3 = l3->next;
            //l3->val = sum % 10;
            l3->next = new ListNode(sum % 10);
            l3 = l3->next;
        }
        if (plus==1)
        {
            l3->next = new ListNode(1);
        }

        return l;
    }
};

/*�ٷ����*/
class Solution1 {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* head = nullptr, * tail = nullptr;
        int carry = 0;
        while (l1 || l2) {
            int n1 = l1 ? l1->val : 0;
            int n2 = l2 ? l2->val : 0;
            int sum = n1 + n2 + carry;
            if (!head) {
                head = tail = new ListNode(sum % 10);
            }
            else {
                tail->next = new ListNode(sum % 10);
                tail = tail->next;
            }
            carry = sum / 10;
            if (l1) {
                l1 = l1->next;
            }
            if (l2) {
                l2 = l2->next;
            }
        }
        if (carry > 0) {
            tail->next = new ListNode(carry);
        }
        return head;
    }
};

int main()
{
    // ��ȡ����ʼʱ��
    auto start = std::chrono::high_resolution_clock::now();
    // �������岿��
    ListNode* head = new ListNode(2);          // ��һ���ڵ㣬ֵΪ2
    head->next = new ListNode(4);              // �ڶ����ڵ㣬ֵΪ3
    head->next->next = new ListNode(3);       // �������ڵ㣬ֵΪ3
    ListNode* l2 = new ListNode(5);          // ��һ���ڵ㣬ֵΪ2
    l2->next = new ListNode(6);              // �ڶ����ڵ㣬ֵΪ3
    l2->next->next = new ListNode(4);       // �������ڵ㣬ֵΪ3
    Solution1 so;
    so.addTwoNumbers(head,l2);
    // ��ȡ�������ʱ��
    auto end = std::chrono::high_resolution_clock::now();

    // ����ʱ���
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);

    // �������ʱ�䣨�룩
    std::cout << "��������ʱ��: " << duration.count() << "΢��" << std::endl;
    return 0;
}
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
 
/*总结*/
/*官方题解中对链表的空的判断是自然的简约的，直接从输入就开始判断是否两个都不为空，顺着这个逻辑下去做事*/
/*我们自己的默认第一个不为空，从第二个开始判断，反而弄巧成繁*/
/*ListNode初始化复制，new的使用*/
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        /**/
        int plus = 0;/*相加大于10*/
        ListNode* l3 = new ListNode();
        ListNode* l = l3;
        int sum = 0;
        int a1, a2;
        /*非空链表第一次相加*/
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
            if (plus == 1) {/*这里没什么好判读的，直接在上面+，没有就+0*/
                sum += 1;
                plus = 0;
            }
            plus = sum >= 10 ? 1 : 0;/*直接/10*/
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

/*官方题解*/
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
    // 获取程序开始时间
    auto start = std::chrono::high_resolution_clock::now();
    // 程序主体部分
    ListNode* head = new ListNode(2);          // 第一个节点，值为2
    head->next = new ListNode(4);              // 第二个节点，值为3
    head->next->next = new ListNode(3);       // 第三个节点，值为3
    ListNode* l2 = new ListNode(5);          // 第一个节点，值为2
    l2->next = new ListNode(6);              // 第二个节点，值为3
    l2->next->next = new ListNode(4);       // 第三个节点，值为3
    Solution1 so;
    so.addTwoNumbers(head,l2);
    // 获取程序结束时间
    auto end = std::chrono::high_resolution_clock::now();

    // 计算时间差
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);

    // 输出运行时间（秒）
    std::cout << "程序运行时间: " << duration.count() << "微妙" << std::endl;
    return 0;
}
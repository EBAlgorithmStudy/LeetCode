/**
21. 合并两个有序链表
将两个升序链表合并为一个新的 升序 链表并返回。新链表是通过拼接给定的两个链表的所有节点组成的。



示例：

输入：1->2->4, 1->3->4
输出：1->1->2->3->4->4
 */
#include <string>
#include <stack>
#include <iostream>
using namespace std;


struct ListNode
{
    int val;
    ListNode *next;
    ListNode()
        : val(0), next(nullptr)
    {}
    ListNode(int x)
        : val(x), next(nullptr)
    {}
    ListNode(int x, ListNode *next)
        : val(x), next(next)
    {}
};

class Solution
{
public:
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2)
    {
        ListNode* l3 = nullptr;
        ListNode** tmp3 = &l3;
        while (l1 || l2)
        {
            if(!l1)
            {
                l3 ? (*tmp3)->next = l2 : (*tmp3) = l2;
                return l3;
            }
            else if(!l2)
            {
                l3 ? (*tmp3)->next = l1 : (*tmp3) = l1;
                return l3;
            }
            else{
                if(l1->val < l2->val)
                {
                    (*tmp3)->next = l1;
                    tmp3 = &(*tmp3)->next;
                    l1 = l1->next;
                }
                else
                {
                    (*tmp3)->next = l2;
                    tmp3 = &(*tmp3)->next;
                    l2 = l2->next;
                }
            }
        }
        return l3;
    }
};

int main(int argc, char *argv[])
{

    return 0;
}

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
#include <vector>
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
    static ListNode* GenerateListNode(std::vector<int> node_list);
};


class Solution
{
public:
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2)
    {
        ListNode* l3 = new ListNode();
        ListNode** tmp3 = &l3;
        while (l1 || l2)
        {
            if(!l1)
            {
                (*tmp3)->next = l2 ;
                if(l3)
                {
                    auto tmp = l3;
                    l3 = l3->next;
                    delete tmp;
                }
                return l3;
            }
            else if(!l2)
            {
                (*tmp3)->next = l1;
                if(l3)
                {
                    auto tmp = l3;
                    l3 = l3->next;
                    delete tmp;
                }
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
        if(l3)
        {
            auto tmp = l3;
            l3 = l3->next;
            delete tmp;
        }
        return l3;
    }
};

int main(int argc, char *argv[])
{
    auto node_list_1 = ListNode::GenerateListNode(vector<int>{1,2,4});
    auto node_list_2 = ListNode::GenerateListNode(vector<int>{1,3,4});
    Solution so;
    auto node_list_3 =  so.mergeTwoLists(node_list_1,node_list_2);


    return 0;
}


ListNode *ListNode::GenerateListNode(std::vector<int> node_list)
{
   if(node_list.empty())
   {
       return nullptr;
   }
   ListNode* node = nullptr;
   node = new ListNode(node_list[0]);
   ListNode** tmp_node = &node;
   if(node_list.size() == 1)
   {
       return node;
   }
   for(int i = 1;i<node_list.size();++i)
   {
       (*tmp_node)->next = new ListNode(node_list[i]);
       tmp_node = &(*tmp_node)->next;
   }
   return node;
}
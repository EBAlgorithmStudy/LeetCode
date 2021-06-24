//给你一个链表，删除链表的倒数第 n 个结点，并且返回链表的头结点。 
//
// 进阶：你能尝试使用一趟扫描实现吗？ 
//
// 
//
// 示例 1： 
//
// 
//输入：head = [1,2,3,4,5], n = 2
//输出：[1,2,3,5]
// 
//
// 示例 2： 
//
// 
//输入：head = [1], n = 1
//输出：[]
// 
//
// 示例 3： 
//
// 
//输入：head = [1,2], n = 1
//输出：[1]
// 
//
// 
//
// 提示： 
//
// 
// 链表中结点的数目为 sz 
// 1 <= sz <= 30 
// 0 <= Node.val <= 100 
// 1 <= n <= sz 
// 
// Related Topics 链表 双指针 
// 👍 1398 👎 0


using namespace std;
#include "vector"
//leetcode submit region begin(Prohibit modification and deletion)
// Definition for singly-linked list.
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
#define FIRST_SOLVE 1
#if FIRST_SOLVE
class Solution
{
public:
	ListNode *removeNthFromEnd(ListNode *head, int n)
	{
		ListNode *arr[30];
		int num = 0;//计算的是next不为空的总个数，比实际个数少1
		ListNode *cur_node = head;
		while (cur_node)
		{
			arr[num] = cur_node;
			cur_node = cur_node->next;
			++num;
		}
		if (num == 1)//只有一个，直接返回空
		{
			return nullptr;
		}
		else if (n == 1)//最后一个，则
		{
			arr[num - n - 1]->next = nullptr;
		}
		else if(n == num)//删除的是第一个
		{
			return head->next;
		}
		else
		{
			arr[num - n - 1]->next = arr[num - n]->next;
		}
		return head;
	}
};
//leetcode submit region end(Prohibit modification and deletion)



#else
class Solution {
public:
    int getLength(ListNode* head) {
        int length = 0;
        while (head) {
            ++length;
            head = head->next;
        }
        return length;
    }

    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* dummy = new ListNode(0, head);
        int length = getLength(head);
        ListNode* cur = dummy;
        for (int i = 1; i < length - n + 1; ++i) {
            cur = cur->next;
        }
        cur->next = cur->next->next;
        ListNode* ans = dummy->next;
        delete dummy;
        return ans;
    }
};

#endif
ListNode *TransArrToListNode(vector<int> vec)
{
	ListNode *cur = nullptr;
	ListNode *head = nullptr;
	for (auto iter : vec)
	{
		ListNode *tmp = new ListNode;
		tmp->val = iter;
		tmp->next = nullptr;
		if (!head)
		{
			head = tmp;
		}
		if (!cur)
		{
			cur = tmp;
		}
		else
		{
			cur->next = tmp;
			cur = cur->next;
		}
	}
	return head;
}
int main(int argc, char *argv[])
{
	ListNode *head = TransArrToListNode(vector < int > {1, 2});
	Solution sol;
	head = sol.removeNthFromEnd(head, 2);
	int ab = 1123;
	return 0;
}
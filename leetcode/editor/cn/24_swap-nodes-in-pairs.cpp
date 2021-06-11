//给定一个链表，两两交换其中相邻的节点，并返回交换后的链表。 
//
// 你不能只是单纯的改变节点内部的值，而是需要实际的进行节点交换。 
//
// 
//
// 示例 1： 
//
// 
//输入：head = [1,2,3,4]
//输出：[2,1,4,3]
// 
//
// 示例 2： 
//
// 
//输入：head = []
//输出：[]
// 
//
// 示例 3： 
//
// 
//输入：head = [1]
//输出：[1]
// 
//
// 
//
// 提示： 
//
// 
// 链表中节点的数目在范围 [0, 100] 内 
// 0 <= Node.val <= 100 
// 
//
// 
//
// 进阶：你能在不修改链表节点值的情况下解决这个问题吗?（也就是说，仅修改节点本身。） 
// Related Topics 递归 链表 
// 👍 938 👎 0


using namespace std;
#include "vector"
//leetcode submit region begin(Prohibit modification and deletion)
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
ListNode *GenListNode(const std::vector<int> &vec)
{
	if (vec.empty())
	{
		return nullptr;
	}
	ListNode *head = nullptr;
	ListNode *node = nullptr;
	for (auto iter : vec)
	{
		ListNode *tmp = new ListNode;
		tmp->next = nullptr;
		tmp->val = iter;
		if (!head)
		{
			head = tmp;
		}
		if (!node)
		{
			node = tmp;
		}
		else
		{
			node->next = tmp;
			node = node->next;
		}
	}
	return head;
}
class Solution
{
public:
	ListNode *swapPairs(ListNode *head)
	{
		if (!head)
		{
			return nullptr;
		}
		int count = 0;
		ListNode *node = head;
		ListNode *preNode = nullptr;
		if(node && node->next){
			head = node->next;
			ListNode* tmp = node->next->next;
			node->next->next = node;
			node->next = tmp;
			preNode = node;
			node = node->next;
		}
		else{
			return head;
		}
		while (node && node->next)
		{
			preNode->next = node->next;
			ListNode* tmp = node->next->next;
			node->next->next = node;
			node->next = tmp;
			preNode = node;
			node = node->next;
		}
		return head;
	}
};
//leetcode submit region end(Prohibit modification and deletion)


#include "iostream"
int main(int argc, char *argv[])
{
	Solution sol;
	ListNode* head = GenListNode(vector<int>{1,2,3,4});
	head =  sol.swapPairs(head);
	while (head){
		cout<<head->val<<"  ";
		head = head->next;
	}
	return 0;
}
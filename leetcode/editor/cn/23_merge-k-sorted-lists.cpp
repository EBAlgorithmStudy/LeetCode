//给你一个链表数组，每个链表都已经按升序排列。 
//
// 请你将所有链表合并到一个升序链表中，返回合并后的链表。 
//
// 
//
// 示例 1： 
//
// 输入：lists = [[1,4,5],[1,3,4],[2,6]]
//输出：[1,1,2,3,4,4,5,6]
//解释：链表数组如下：
//[
//  1->4->5,
//  1->3->4,
//  2->6
//]
//将它们合并到一个有序链表中得到。
//1->1->2->3->4->4->5->6
// 
//
// 示例 2： 
//
// 输入：lists = []
//输出：[]
// 
//
// 示例 3： 
//
// 输入：lists = [[]]
//输出：[]
// 
//
// 
//
// 提示： 
//
// 
// k == lists.length 
// 0 <= k <= 10^4 
// 0 <= lists[i].length <= 500 
// -10^4 <= lists[i][j] <= 10^4 
// lists[i] 按 升序 排列 
// lists[i].length 的总和不超过 10^4 
// 
// Related Topics 堆 链表 分治算法 
// 👍 1340 👎 0


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
private:
	ListNode *findOneNode(vector<ListNode *> &head_list)
	{
		if (head_list.empty())
		{
			return nullptr;
		}
		ListNode  ** node = nullptr;
		for (auto iter = head_list.begin(); iter != head_list.end();)
		{
			if (!*iter)
			{
				iter = head_list.erase(iter);
				continue;
			}
			if(!node){
				node = &*iter;
			}
			else if ((*node)->val > (*iter)->val)
			{
				node = &*iter;
			}
			++iter;
		}
		if(!node){
			return nullptr;
		}
		auto tmp = *node;
		*node = (*node)->next;
		return tmp;
	}
public:
	ListNode *mergeKLists(vector<ListNode *> &lists)
	{
//		vector < ListNode * > head_list;
//		for (auto iter : lists)
//		{
//			head_list.push_back(iter);
//		}
		ListNode *head = nullptr;
		ListNode *flag = nullptr;
		if (lists.empty())
		{
			return nullptr;
		}


		do
		{
			auto node = findOneNode(lists);
			if (!node)
			{
				break;
			}
			if (head == nullptr)
			{
				head = node;
			}
			if (flag == nullptr)
			{
				flag = node;
			}
			else
			{
				flag->next = node;
				flag = flag->next;
			}
		}
		while (1);
		return head;
	}
};
//leetcode submit region end(Prohibit modification and deletion)


#include "iostream"
int main(int argc, char *argv[])
{
	ListNode *a = GenListNode(vector < int > {1, 4, 5});
	ListNode *b = GenListNode(vector < int > {1, 3, 4});
	ListNode *c = GenListNode(vector < int > {2, 6});
	auto vec = vector < ListNode * > {a, b, c};
	Solution sol;
	auto node = sol.mergeKLists(vec);
	while (node){
		cout<<node->val<<"->";
		node = node->next;
	}
	return 0;
}
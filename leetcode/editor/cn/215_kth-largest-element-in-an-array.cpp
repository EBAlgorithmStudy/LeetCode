//在未排序的数组中找到第 k 个最大的元素。请注意，你需要找的是数组排序后的第 k 个最大的元素，而不是第 k 个不同的元素。 
//
// 示例 1: 
//
// 输入: [3,2,1,5,6,4] 和 k = 2
//输出: 5
// 
//
// 示例 2: 
//
// 输入: [3,2,3,1,2,4,5,5,6] 和 k = 4
//输出: 4 
//
// 说明: 
//
// 你可以假设 k 总是有效的，且 1 ≤ k ≤ 数组的长度。 
// Related Topics 堆 分治算法 
// 👍 1132 👎 0


using namespace std;
#include "vector"
#include "iostream"
//leetcode submit region begin(Prohibit modification and deletion)
class Solution
{
private:
	void Swap(vector<int> &nums, int i, int j)
	{
		int tmp = nums[i];
		nums[i] = nums[j];
		nums[j] = tmp;
	}
	void MaxHeapfi(vector<int> &nums, int index, int remain_size)
	{
		int l = 2 * index + 1;
		int r = l + 1;
		int largest = index;
		if (l < remain_size && nums[l] > nums[largest])
		{
			largest = l;
		}
		if (r < remain_size && nums[r] > nums[largest])
		{
			largest = r;
		}
		if (largest != index)
		{
			Swap(nums, largest, index);
			MaxHeapfi(nums, largest, remain_size);
		}
	}
	void BuildMaxHeap(vector<int> &nums)
	{
		for (int i = nums.size() / 2 - 1; i >= 0; --i)
		{
			MaxHeapfi(nums, i, nums.size());
		}
	}
public:
	int findKthLargest(vector<int> &nums, int k)
	{
		BuildMaxHeap(nums);
		if(nums.size() == 1)
		{
			return nums[0];
		}
		int a = nums.size() - k;
		for (int i = nums.size() - 1; i >= a; --i)
		{
			Swap(nums, 0, i);
			MaxHeapfi(nums, 0, i);
		}
		return nums[a];
	}
};
//leetcode submit region end(Prohibit modification and deletion)



int main(int argc, char *argv[])
{
	Solution sol;
//	vector<int> vec = {3, 2, 3, 1, 2, 4, 5, 5, 6};
//	cout << sol.findKthLargest(vec, 4);
	vector<int> vec = {2,1};
	cout<<sol.findKthLargest(vec,2);
	cout << endl;
	for (auto iter : vec)
	{
		cout << iter << "-";
	}
	return 0;
}
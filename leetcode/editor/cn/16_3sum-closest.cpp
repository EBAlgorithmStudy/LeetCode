//给定一个包括 n 个整数的数组 nums 和 一个目标值 target。找出 nums 中的三个整数，使得它们的和与 target 最接近。返回这三个数的和
//。假定每组输入只存在唯一答案。 
//
// 
//
// 示例： 
//
// 输入：nums = [-1,2,1,-4], target = 1
//输出：2
//解释：与 target 最接近的和是 2 (-1 + 2 + 1 = 2) 。
// 
//
// 
//
// 提示： 
//
// 
// 3 <= nums.length <= 10^3 
// -10^3 <= nums[i] <= 10^3 
// -10^4 <= target <= 10^4 
// 
// Related Topics 数组 双指针 
// 👍 788 👎 0


using namespace std;
#include <iostream>
#include "vector"
#include "math.h"
//leetcode submit region begin(Prohibit modification and deletion)
class Solution
{
private:
	//从小到大排序
	inline void sort(vector<int> &nums)
	{
		for (int i = 0; i < nums.size(); ++i)
		{
			for (int j = i + 1; j < nums.size(); ++j)
			{
				if (nums[i] > nums[j])
				{
					int tmp = nums[i];
					nums[i] = nums[j];
					nums[j] = tmp;
				}
			}
		}
	}
public:

	int threeSumClosest(vector<int> &nums, int target)
	{
		sort(nums);
		int min_diff = INT_MAX;
		int min_sum = 0;
		for (int i = 0; i < nums.size(); ++i)
		{
			int left = i + 1;
			int right = nums.size() - 1;
			while (left < right)
			{
				int sum = nums[i] + nums[left] + nums[right];
				int diff = 0;
				if (sum > target)
				{
					diff = sum - target;
					//
					if (diff < min_diff)
					{
						min_diff = diff;
						min_sum = sum;
					}
					--right;
				}
				else
				{
					diff = target - sum;
					if (diff < min_diff)
					{
						min_diff = diff;
						min_sum = sum;
					}
					++left;
				}
			}
		}
		return min_sum;
	}
};
//leetcode submit region end(Prohibit modification and deletion)


int main(int argc, char *argv[])
{
	Solution sol;
	vector<int> v{1, 1, 1, 0};
	cout << "min diff :" << sol.threeSumClosest(v, -100) << std::endl;
	return 0;
}
//给你一个包含 n 个整数的数组 nums，判断 nums 中是否存在三个元素 a，b，c ，使得 a + b + c = 0 ？请你找出所有和为 0 且不重
//复的三元组。 
//
// 注意：答案中不可以包含重复的三元组。 
//
// 
//
// 示例 1： 
//
// 
//输入：nums = [-1,0,1,2,-1,-4]
//输出：[[-1,-1,2],[-1,0,1]]
// 
//
// 示例 2： 
//
// 
//输入：nums = []
//输出：[]
// 
//
// 示例 3： 
//
// 
//输入：nums = [0]
//输出：[]
// 
//
// 
//
// 提示： 
//
// 
// 0 <= nums.length <= 3000 
// -105 <= nums[i] <= 105 
// 
// Related Topics 数组 双指针 
// 👍 3377 👎 0


using namespace std;
#include <iostream>
#include "vector"
#include "math.h"
//leetcode submit region begin(Prohibit modification and deletion)
class Solution
{
private:
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
	vector<vector<int>> threeSum(vector<int> &nums)
	{
		sort(nums);
		int i = 0, j = nums.size() - 1;
		vector<vector<int>> res;
		for (int i = 0; i < nums.size(); ++i)
		{
			int left = i + 1, right = nums.size() - 1;
			while (left < right)
			{
				if (-nums[i] == (nums[left] + nums[right]))
				{
					bool need_insert = true;
					for (int j = 0; j < res.size(); ++j)
					{
						if (res[j][0] == nums[i] &&
						    res[j][1] == nums[left] &&
						    res[j][2] == nums[right])
						{
							need_insert = false;
							break;
						}
					}

					if (need_insert)
					{
						res.push_back(vector < int > {nums[i], nums[left], nums[right]});
					}
					++left;
					--right;
				}
				else if ((-nums[i]) < (nums[left] + nums[right]))
				{
					--right;
				}
				else
				{
					++left;
				}
			}
		}
		return res;
	}
};
//leetcode submit region end(Prohibit modification and deletion)


int main(int argc, char *argv[])
{
	//[3,0,-2,-1,1,2]
	vector<int> d = vector < int > {3, 0, -2, -1, 1, 2};
	Solution sol;
	vector<vector<int>> res = sol.threeSum(d);
	int i = 2;
	cout << "10^5" << pow(10, 5);
	return 0;
}
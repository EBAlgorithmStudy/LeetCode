/**
 *35. 搜索插入位置
给定一个排序数组和一个目标值，在数组中找到目标值，并返回其索引。如果目标值不存在于数组中，返回它将会被按顺序插入的位置。

你可以假设数组中无重复元素。

示例 1:

输入: [1,3,5,6], 5
输出: 2
示例 2:

输入: [1,3,5,6], 2
输出: 1
示例 3:

输入: [1,3,5,6], 7
输出: 4
示例 4:

输入: [1,3,5,6], 0
输出: 0
 */

using namespace std;
#include <vector>
#include <iostream>

class Solution
{
public:
    int searchInsert(vector<int> &nums, int target)
    {
        size_t left_index = 0;
        size_t right_index = nums.size() - 1;
        while (left_index <= right_index) {
            size_t middle_index = (right_index + left_index) / 2;
            if (nums[middle_index] < target) {
                if (nums.size() - 1 == middle_index) {
                    return nums.size();
                }
                else if (nums[middle_index + 1] >= target) {
                    return middle_index + 1;
                }
                else {
                    left_index = middle_index + 1;
                    continue;
                }
            }
            else if (nums[middle_index] > target) {
                if (middle_index == 0) {
                    return 0;
                }
                else if (nums[middle_index - 1] < target) {
                    return middle_index;
                }
                else if (nums[middle_index - 1] == target)
                {
                    return middle_index -1;
                }
                else
                {
                    right_index = middle_index -1;
                }
            }
            else
            {
                return middle_index;
            }
        }
        return 0;
    }
};

int main(int argc, char *argv[])
{
    Solution so;
//    cout<<so.searchInsert(ve,5)<<endl;

   std::vector<int> ve = {1,3,5};
    cout<<so.searchInsert(ve,1)<<endl;
    return 0;
}

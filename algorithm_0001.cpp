//
// Created by LQYHE on 2020/12/21.
//

/***
 * 1. 两数之和
 * 给定一个整数数组 nums 和一个目标值 target，请你在该数组中找出和为目标值的那 两个 整数，并返回他们的数组下标。

你可以假设每种输入只会对应一个答案。但是，数组中同一个元素不能使用两遍。

 

示例:

给定 nums = [2, 7, 11, 15], target = 9

因为 nums[0] + nums[1] = 2 + 7 = 9
所以返回 [0, 1]

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/two-sum
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */

#include <vector>
#include <iostream>
#include <map>
#include <unordered_map>

using namespace std;



class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        for(int i = 0;i<nums.size();++i)
        {
            int par_val = target - nums[i];
            auto iter = m_map.find(par_val);
            if(iter == m_map.end())
            {
                m_map.emplace(nums[i],i);
            }
            else
            {
                return vector<int>{iter->second,i};
            }
        }
        return vector<int>();
    }

private:
    std::unordered_map<int,int> m_map;
};



int main(int argc,char* argv[])
{
    Solution so;
//    auto ve = vector<int>{2,7,11,15};
//    auto result = so.twoSum(ve,9);
//    for(auto iter : result)
//    {
//        std::cout<<"index :"<<iter<<std::endl;
//    }

    auto ve_2 = vector<int>{3,2,4};
    auto result_2 = so.twoSum(ve_2,6);
    for(auto iter : result_2)
    {
        std::cout<<"index :"<<iter<<std::endl;
    }
    return 0;
}

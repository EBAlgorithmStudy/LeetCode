//
// Created by LQYHE on 2020/12/21.
//

#include <vector>
#include <cstring>
#include <iostream>

using namespace std;



class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int size = (target+1)/2;
        item arr[size+1][2];
        for(int i = 0;i<nums.size();++i)
        {
            if(nums[i] > target)
                continue;
            if(nums[i] < size)
            {
                if(arr[nums[i]][1].is_set)
                {
                    return vector<int>{arr[nums[i]][1].value,i};
                }
                arr[nums[i]][0].is_set = true;
                arr[nums[i]][0].value = i;
            }
            else if(nums[i] > size)
            {
                int sm_index = target - nums[i];
                if(arr[sm_index][0].is_set)
                {
                    return vector<int>{arr[sm_index][0].value,i};
                }
                arr[sm_index][1].is_set = true;
                arr[sm_index][1].value = i;
            }
            else
            {
                if(arr[nums[i]][0].is_set)
                {
                    return vector<int>{arr[nums[i]][0].value,i};
                }
                arr[nums[i]][0].is_set = true;
                arr[nums[i]][0].value = i;
            }
        }
        return vector<int>();
    }
private:
    struct item{
        int value = 0;
        bool is_set = false;
    };
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

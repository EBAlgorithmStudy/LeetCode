/***
 * 9. 回文数
判断一个整数是否是回文数。回文数是指正序（从左向右）和倒序（从右向左）读都是一样的整数。

示例 1:

输入: 121
输出: true
示例 2:

输入: -121
输出: false
解释: 从左向右读, 为 -121 。 从右向左读, 为 121- 。因此它不是一个回文数。
示例 3:

输入: 10
输出: false
解释: 从右向左读, 为 01 。因此它不是一个回文数。
 */

#include <vector>
#include <iostream>
#include <map>
#include <unordered_map>

using namespace std;

class Solution {
public:
    bool isPalindrome(int x) {
#ifdef BEFORE_SEE_SOLU
        int tmp_x = x;
        if(tmp_x<0)
        {
            return false;
        }
        if(x == 0)
        {
            return true;
        }
        if(tmp_x%10 == 0)
        {
            return false;
        }
        //判断位数
        int num = 0;
        do{
            ++num;
        }
        while ((tmp_x=tmp_x/10));

        if(num == 1)
        {
            return true;
        }

        int index = num/2;
        std::vector<int> tmp_vector;
        for(int i = 0;i<index;++i)
        {
            tmp_vector.push_back(x%10);
            x = x/10;
        }

        int double_index = 2*index;
        int j = 0;
        if(num%2 == 0)
        {
            --double_index;
            j = index;
        }
        else
        {
            j = index + 1;
            x = x/10;
        }
        for(;j<num;++j)
        {
            std::cout<<"index "<< double_index -j<<std::endl;
            if(x%10 != tmp_vector[double_index - j])
            {
                return false;
            }
            x = x/10;
        }
        return true;
#elif AFTER_SEE_SOLUTION
        if(x == 0)
        {
            return true;
        }
        if(x <0 || x%10 == 0 )
        {
            return false;
        }
        int tmp_x = 0;

        while (x > tmp_x)
        {
            tmp_x = tmp_x * 10 + x%10;
            x /= 10;
        }

        return (tmp_x == x || tmp_x == x*10 + tmp_x%10);
#else

        if(x <0 )
        {
            return false;
        }
        int tmp_x = x;
        long long tmp_xx = 0;
        while (x)
        {
            tmp_xx = tmp_xx * 10 + x%10;
            x /= 10;
        }

        return tmp_xx == tmp_x;
#endif
    }
};





int main(int argc,char* argv[])
{
    int i = 0;

    i = 10;
    Solution co;
    std::cout<<"input is "<<i<<"  ,out put is "<< co.isPalindrome(i)<<std::endl;


    return 0;
}

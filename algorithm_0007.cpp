#include <vector>
#include <queue>
#include <iostream>
#include "math.h"
/***
 * 7. 整数反转
给出一个 32 位的有符号整数，你需要将这个整数中每位上的数字进行反转。

示例 1:

输入: 123
输出: 321
 示例 2:

输入: -123
输出: -321
示例 3:

输入: 120
输出: 21
注意:

假设我们的环境只能存储得下 32 位的有符号整数，则其数值范围为 [−231,  231 − 1]。请根据这个假设，如果反转后整数溢出那么就返回 0。
*/

#define USE_MINE 0

class Solution {
public:
    int reverse(int x)
    {
#if USE_MINE
        bool flag = false;
        long long tmp_x = 0;
        if(x<0)
        {
            tmp_x = (long long)0-x;
            flag = true;
        }
        else
        {
            tmp_x = x;
        }

        std::vector<int> po;


        do {
            po.push_back(tmp_x%10);
        }
        while ((tmp_x = tmp_x/10));
        long long sub = 0;
        int num = po.size();
        for(int tmp_i = 0;tmp_i<num;++tmp_i)
        {
            long long tmp_sub = po[num-tmp_i-1]* pow(10,tmp_i);
            sub += tmp_sub;
            if(sub>2147483647)
            {
                return 0;
            }
        }
        if(flag)
        {
            return 0-sub;
        }
        return sub;
#else
        return 0;
#endif
    }
};

int main(int argc,char* argv[])
{
    Solution so;
    std::cout<<"input : -2147483648, output : "<<so.reverse(-2147483647)<< std::endl;

    return 0;
}
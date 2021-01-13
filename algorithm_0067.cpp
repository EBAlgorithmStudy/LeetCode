/**
 *67. 二进制求和
给你两个二进制字符串，返回它们的和（用二进制表示）。

输入为 非空 字符串且只包含数字 1 和 0。



示例 1:

输入: a = "11", b = "1"
输出: "100"
示例 2:

输入: a = "1010", b = "1011"
输出: "10101"


提示：

每个字符串仅由字符 '0' 或 '1' 组成。
1 <= a.length, b.length <= 10^4
字符串如果不是 "0" ，就都不含前导零。
 */

#include <string>
#include <iostream>
using namespace std;



class Solution {
public:
    string addBinary(string a, string b) {
        std::string* tmp_long = nullptr;
        std::string* tmp_short = nullptr;
        int short_len = 0;
        int long_len = 0;
        char tmp2 = 0;
        if(a.size() >= b.size())
        {
            tmp_long = &a;
            long_len = a.size();
            tmp_short = &b;
            short_len = b.size();
        }
        else
        {
            tmp_long = &b;
            long_len = b.size();
            tmp_short = &a;
            short_len = a.size();
        }
        for(int i = short_len-1,j=long_len-1;i>=0;--i,--j)
        {
            if(tmp_long->at(j)=='0' && tmp_short->at(i)=='0' && tmp2 == 0)
            {
            }
            else if(tmp_long->at(j) == '0' && tmp_short->at(i) == '0' && tmp2 ==1)
            {
                tmp_long->at(j) = '1';
                tmp2 = 0;
            }
            else if(tmp_long->at(j) == '0' && tmp_short->at(i) == '1' && tmp2 == 0)
            {
                tmp_long->at(j) = '1';
            }
            else if(tmp_long->at(j) == '0' && tmp_short->at(i) == '1' && tmp2 == 1)
            {
            }
            else if (tmp_long->at(j) == '1' && tmp_short->at(i) == '0' && tmp2 == 0)
            {

            }
            else if(tmp_long->at(j) == '1' && tmp_short->at(i) == '0' && tmp2 == 1)
            {
                tmp_long->at(j) = '0';
            }
            else if (tmp_long->at(j) == '1' && tmp_short->at(i) == '1' && tmp2 == 0)
            {
                tmp_long->at(j) = '0';
                tmp2 = 1;
            }
            else if(tmp_long->at(j) == '1' && tmp_short->at(i)== '1' && tmp2 == 1)
            {

            }
            else
            {

            }
        }
        for(int i = long_len - short_len-1;i>=0;--i)
        {
            if(tmp_long->at(i) == '0' && tmp2 ==0)
            {
                break;
            }
            else if(tmp_long->at(i) == '0' && tmp2 == 1)
            {
                tmp_long->at(i) = '1';
                tmp2 = 0;
                break;
            }
            else if (tmp_long->at(i) == '1' && tmp2 == 0)
            {
                break;
            }
            else if(tmp_long->at(i) == '1' && tmp2 == 1)
            {
                tmp_long->at(i) = '0';
                tmp2 = 1;
            }
            else
            {

            }
        }
        if(tmp2 == 1)
        {
            tmp_long->insert(tmp_long->begin(),'1');
        }
        return *tmp_long;
    }

};


int main(int argc,char* argv[])
{
    Solution so;
    std::cout << so.addBinary("11","1")<<std::endl;
    return 0;
}

/**
 * 14. 最长公共前缀
编写一个函数来查找字符串数组中的最长公共前缀。

如果不存在公共前缀，返回空字符串 ""。

示例 1:

输入: ["flower","flow","flight"]
输出: "fl"
示例 2:

输入: ["dog","racecar","car"]
输出: ""
解释: 输入不存在公共前缀。
 * @param argc
 * @param argv
 * @return
 */
#include <string>
#include <vector>
#include <iostream>
using namespace std;
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string prefix = "";
        char tmp;
        if(strs.size() == 0)
        {
            return prefix;
        }
        else if(strs.size() == 1)
        {
            return strs[0];
        }
        else
        {
            for(int i = 0;i<strs[0].size();++i)
            {
                tmp = strs[0][i];
                for(int j = 1;j<strs.size();++j)
                {
                    if(i>=strs[j].size())
                    {
                        return prefix;
                    }
                    else if(tmp != strs[j][i])
                    {
                        return prefix;
                    }
                }
                prefix.push_back(tmp);
            }
        }
        return prefix;
    }
};

int main(int argc,char* argv[])
{

    Solution so;
    vector<string> v{"flower","flow","flight"};
    cout<<"result is " <<so.longestCommonPrefix(v)<<endl;

    return 0;
}

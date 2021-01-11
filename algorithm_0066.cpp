/**
 *66. 加一
给定一个由 整数 组成的 非空 数组所表示的非负整数，在该数的基础上加一。

最高位数字存放在数组的首位， 数组中每个元素只存储单个数字。

你可以假设除了整数 0 之外，这个整数不会以零开头。



示例 1：

输入：digits = [1,2,3]
输出：[1,2,4]
解释：输入数组表示数字 123。
示例 2：

输入：digits = [4,3,2,1]
输出：[4,3,2,2]
解释：输入数组表示数字 4321。
示例 3：

输入：digits = [0]
输出：[1]


提示：

1 <= digits.length <= 100
0 <= digits[i] <= 9
 */

using namespace std;
#include <vector>

class Solution
{
public:
    vector<int> plusOne(vector<int> &digits)
    {
        if (digits.size() == 1) {
            ++digits[0];
        }
        else {
            ++digits[digits.size() - 1];
            for (int i = digits.size() - 1; i >= 1; --i) {
                if (digits[i] == 10) {
                    digits[i] = 0;
                    ++digits[i - 1];
                }
                else {
                    return digits;
                }
            }
        }
        if (digits[0] == 10) {
            digits[0] = 0;
            digits.insert(digits.begin(), 1);
        }
        return digits;
    }
};


int main(int argc, char *argv[])
{
    return 0;
}

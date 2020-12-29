/**
20. 有效的括号
给定一个只包括 '('，')'，'{'，'}'，'['，']' 的字符串，判断字符串是否有效。

有效字符串需满足：

左括号必须用相同类型的右括号闭合。
左括号必须以正确的顺序闭合。
注意空字符串可被认为是有效字符串。

示例 1:

输入: "()"
输出: true
示例 2:

输入: "()[]{}"
输出: true
示例 3:

输入: "(]"
输出: false
示例 4:

输入: "([)]"
输出: false
示例 5:

输入: "{[]}"
输出: true
 */
#include <string>
#include <stack>
#include <iostream>
using namespace std;
class Solution
{
public:
    bool isValid(string s)
    {
        std::stack<char> myStack;
        for (char tmp : s) {
            switch (tmp) {
                case '(':
                case '[':
                case '{':
                    myStack.push(tmp);
                    break;
                case ')':
                    if (!myStack.empty() && myStack.top() == '(')
                        myStack.pop();
                    else
                        return false;
                    break;
                case ']':
                    if (!myStack.empty() && myStack.top() == '[')
                        myStack.pop();
                    else
                        return false;
                    break;
                case '}':
                    if (!myStack.empty() && myStack.top() == '{')
                        myStack.pop();
                    else
                        return false;
                    break;
                default:
                    return false;
            }
        }
        return myStack.empty();

    }
};

int main(int argc, char *argv[])
{

    string s;
    Solution so;
//    s="()";
//    cout<<"string is : "<<s <<"and valid is "<<so.isValid(s)<<endl;


    s = "()[]{}";
    cout << "string is : " << s << "and valid is " << so.isValid(s) << endl;

    s = "(]";
    cout << "string is : " << s << "and valid is " << so.isValid(s) << endl;

    s = "([)]";
    cout << "string is : " << s << "and valid is " << so.isValid(s) << endl;

    s = "{[]}";
    cout << "string is : " << s << "and valid is " << so.isValid(s) << endl;
    return 0;
}

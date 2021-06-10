//数字 n 代表生成括号的对数，请你设计一个函数，用于能够生成所有可能的并且 有效的 括号组合。 
//
// 
//
// 示例 1： 
//
// 
//输入：n = 3
//输出：["((()))","(()())","(())()","()(())","()()()"]
// 
//
// 示例 2： 
//
// 
//输入：n = 1
//输出：["()"]
// 
//
// 
//
// 提示： 
//
// 
// 1 <= n <= 8 
// 
// Related Topics 字符串 回溯算法 
// 👍 1822 👎 0


using namespace std;
#include "string"
#include "vector"
//leetcode submit region begin(Prohibit modification and deletion)
class Solution
{
private:
	void generateParenthesis(int left_parenthesis, int right_parenthesis, string &str, vector<string> &res)
	{
		if (left_parenthesis == 0 && right_parenthesis == 0)
		{
			res.push_back(str);
		}
		else
		{
			if (left_parenthesis == right_parenthesis)
			{
				str.append(1, '(');
				generateParenthesis(left_parenthesis - 1, right_parenthesis, str, res);
				str.pop_back();
			}
			else
			{
				if(left_parenthesis>0)
				{
					str.append(1,'(');
					generateParenthesis(left_parenthesis - 1, right_parenthesis, str, res);
					str.pop_back();
				}
				if(right_parenthesis>0)
				{
					str.append(1,')');
					generateParenthesis(left_parenthesis, right_parenthesis-1, str, res);
					str.pop_back();
				}
			}
		}
	}
public:
	vector<string> generateParenthesis(int n)
	{
		int left_parenthesis = n, right_parenthesis = n;
		vector<string> vec;
		string str;
		generateParenthesis(left_parenthesis, right_parenthesis,str, vec);
		return vec;
	}
};
//leetcode submit region end(Prohibit modification and deletion)


#include "iostream"
int main(int argc, char *argv[])
{
	Solution sol;
	vector<string> vec = sol.generateParenthesis(3);
	for(auto iter : vec)
	{
		std::cout<<iter<<std::endl;
	}
	return 0;
}
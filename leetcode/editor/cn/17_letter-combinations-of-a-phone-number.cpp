//给定一个仅包含数字 2-9 的字符串，返回所有它能表示的字母组合。答案可以按 任意顺序 返回。 
//
// 给出数字到字母的映射如下（与电话按键相同）。注意 1 不对应任何字母。 
//
// 
//
// 
//
// 示例 1： 
//
// 
//输入：digits = "23"
//输出：["ad","ae","af","bd","be","bf","cd","ce","cf"]
// 
//
// 示例 2： 
//
// 
//输入：digits = ""
//输出：[]
// 
//
// 示例 3： 
//
// 
//输入：digits = "2"
//输出：["a","b","c"]
// 
//
// 
//
// 提示： 
//
// 
// 0 <= digits.length <= 4 
// digits[i] 是范围 ['2', '9'] 的一个数字。 
// 
// Related Topics 深度优先搜索 递归 字符串 回溯算法 
// 👍 1344 👎 0


using namespace std;
#include <string>
#include <iostream>
#include "vector"
#include "math.h"
//leetcode submit region begin(Prohibit modification and deletion)
#if 1
class Solution
{
	//vec：数组
	//diff：偏移量
	//index：解析到digits的第几位
	//digits：输入的数
	void InsertStr(vector<string> &vec, int diff, int index, const string &digits, int item_num[], int item_size, int *num, char ch[][4])
	{
		//
		int tmp = item_size - index;
		int a = digits.at(index) - '2';
		if (tmp <= 1)//小于0，说明是最后一个
		{
			for (int i = 0; i < num[a]; ++i)
			{
//				cout<<"the : " <<diff+i<<"insert : "<<ch[a][i]<<endl;
				vec[diff + i].append(1, ch[a][i]);
			}
		}
		else
		{
			int item_sum = item_num[tmp-1];
			for (int i = 0; i < num[a]; ++i)
			{
				int tmp = diff + i * item_sum;
				for (int j = 0; j < item_sum; ++j)
				{
//					cout<<"the : " <<tmp+j<<"insert : "<<ch[a][i]<<endl;
					vec.at(tmp + j).append(1, ch[a][i]);
				}
				InsertStr(vec, diff + i * item_sum, index + 1, digits, item_num, item_size, num, ch);
			}
		}
	}
public:
	vector<string> letterCombinations(string digits)
	{
		char ch[8][4] = {
			{'a', 'b', 'c', ' '},
			{'d', 'e', 'f', ' '},
			{'g', 'h', 'i', ' '},
			{'j', 'k', 'l', ' '},
			{'m', 'n', 'o', ' '},
			{'p', 'q', 'r', 's'},
			{'t', 'u', 'v', ' '},
			{'w', 'x', 'y', 'z'}
		};
		int size = digits.size();
		if (size <= 0)
		{
			return vector<string>();
		}
		int num[8] = {3, 3, 3, 3, 3, 4, 3, 4};
		int item_num[size];//在有i位确定后有多少种组合
		int sum = 1;
		for (int i = 0; i < size; ++i)
		{
			int a = digits.at(i) - '2';
			sum *= num[a];
			item_num[i] = sum;
		}
		std::vector<string> arr(sum);
		InsertStr(arr, 0, 0, digits, item_num, size, num, ch);
		return arr;
	}
};
#else
class Solution
{
	//vec：数组
	//diff：偏移量
	//index：解析到digits的第几位
	//digits：输入的数
	void InsertStr(vector<string> &vec, int diff, int index, const string &digits, int *item_num, int item_size, int *num, char ch[][4])
	{
		//
		int item_sum = 0;
		int tmp = item_size - index - 1;
		if (tmp <= 0)//小于0，说明是最后一个
		{
			item_sum = 1;
			for (int i = 0; i < num[index]; ++i)
			{
				vec[diff + i].append(1,ch[digits.at(index)-'2'][i]);
			}
		}
		else
		{
			item_sum = item_num[tmp - 1];
			for (int i = 0; i < num[index]; ++i)
			{
				int tmp = diff + i * item_sum;
				for (int j = 0; j < item_sum; ++j)
				{
					vec.at(tmp + j).append(1, ch[digits.at(index) - '2'][i]);
				}
				InsertStr(vec, diff + i * item_sum, index + 1, digits, item_num, item_size, num, ch);
			}
		}
	}
public:
	vector<string> letterCombinations(string digits)
	{
		char ch[8][4] = {
			{'a', 'b', 'c', ' '},
			{'d', 'e', 'f', ' '},
			{'g', 'h', 'i', ' '},
			{'j', 'k', 'l', ' '},
			{'m', 'n', 'o', ' '},
			{'p', 'q', 'r', 's'},
			{'t', 'u', 'v', ' '},
			{'w', 'x', 'y', 'z'}
		};
		int size = digits.size();
		if(size<=0)
		{
			return vector<string>();
		}
		int num[8] = {3, 3, 3, 3, 3, 4, 3, 4};
		int item_num[size];//在有i位确定后有多少种组合
		int sum = 1;
		for (int i = 0; i < size; ++i)
		{
			sum *= num[i];
			item_num[i] = sum;
		}
		std::vector<string> arr(sum);
		InsertStr(arr, 0, 0, digits, item_num, size, num, ch);
		return arr;
	}
};
#endif
//leetcode submit region end(Prohibit modification and deletion)


int main(int argc, char *argv[])
{
	Solution sol;
	string digits = "78";
	auto arr = sol.letterCombinations(digits);
	for (int i  = 0;i<arr.size();++i)
	{
		cout << ""<< i <<" : "<< arr[i] << endl;
	}

//	vector<string> vec;
//	vec.push_back(string());
//	auto& str = vec[0];
//	str = "aabbc";
//	cout<<vec[0]<<endl;
	return 0;
}
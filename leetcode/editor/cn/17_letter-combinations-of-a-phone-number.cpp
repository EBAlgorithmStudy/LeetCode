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
#if 0
class Solution
{
	//vec：数组
	//diff：偏移量
	//index：解析到digits的第几位
	//digits：输入的数
	void InsertStr(vector<string> &vec, int diff, int index, const string &digits, int item_num[], int item_size, int *num, char ch[][4])
	{
		//确定除本次外还剩余的数有多少个
		int remain = item_size - index - 1;
		//获取第index个数字是多少
		int a = digits.at(index) - '2';
		if (remain <= 0)//小于或者等于0，说明是最后一个
		{
			for (int i = 0; i < num[a]; ++i)
			{
//				cout<<"the : " <<diff+i<<"insert : "<<ch[a][i]<<endl;
				vec[diff + i].append(1, ch[a][i]);
			}
		}
		else
		{
			//获取当前剩余的数字能够有的组合
			int item_sum = item_num[remain];
			for (int i = 0; i < num[a]; ++i)
			{
				//当前数字上对应的字母，每一个都能够和剩余数字拥有item_sum个组合
				int tmp2 = diff + i * item_sum;
				int tmp3 = tmp2 + item_sum;
				for (int j = tmp2; j < tmp3; ++j)
				{
//					cout<<"the : " <<remain+j<<"insert : "<<ch[a][i]<<endl;
					vec.at(j).append(1, ch[a][i]);
				}
				InsertStr(vec, tmp2, index + 1, digits, item_num, item_size, num, ch);
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
		int item_num[size+1];//在有i位确定后有多少种组合
		int sum = 1;
		for (int i = 0; i < size; ++i)
		{
			int a = digits.at(size - i - 1) - '2';
			sum *= num[a];
			item_num[i+1] = sum;
		}
		std::vector<string> arr(sum);
		InsertStr(arr, 0, 0, digits, item_num, size, num, ch);
		return arr;
	}
};
#elseif 0
class Solution
{
private:
	void InsertStr(char ch[8][4], int size, string &digits, int flag, vector<string>& vec)
	{
		std::string str;
		for (int i = 0; i < size; ++i)
		{
			int a = digits.at(i) - '2';
			int tmp = (flag >> (i * 2)) & 3;
//			cout<<"===========start=============="<<endl;
//			cout<<"i                :"<<i<<endl;
//			cout<<"flag             :"<<flag<<endl;
//			cout<<"(flag >> (i * 2)):"<<(flag >> (i * 2))<<endl;
//			cout<<"tmp              :"<<tmp<<endl;
			switch (tmp)
			{
				case 0:
				case 1:
				case 2:
					str.append(1, ch[a][tmp]);
					break;
				case 3:
					if (ch[a][tmp] == ' ')
					{
//						cout<<"return return  a:"<<a<<"   tmp:"<<tmp<<endl;
						return;
					}
					str.append(1, ch[a][tmp]);
					break;
			}
		}
		vec.push_back(str);

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
		vector<string> vec;
		if(digits.size() == 0)
		{
			return vec;
		}
		for (int flag = 0; flag < pow(4,digits.size()); ++flag)
		{
			InsertStr(ch,digits.size(),digits,flag,vec);
		}
		return vec;
	}
};
#else
#include "unordered_map"
class Solution {
public:
	vector<string> letterCombinations(string digits) {
		vector<string> combinations;
		if (digits.empty()) {
			return combinations;
		}
		unordered_map<char, string> phoneMap{
			{'2', "abc"},
			{'3', "def"},
			{'4', "ghi"},
			{'5', "jkl"},
			{'6', "mno"},
			{'7', "pqrs"},
			{'8', "tuv"},
			{'9', "wxyz"}
		};
		string combination;
		backtrack(combinations, phoneMap, digits, 0, combination);
		return combinations;
	}

	void backtrack(vector<string>& combinations, const unordered_map<char, string>& phoneMap, const string& digits, int index, string& combination) {
		if (index == digits.length()) {
			combinations.push_back(combination);
		} else {
			char digit = digits[index];
			const string& letters = phoneMap.at(digit);
			for (const char& letter: letters) {
				combination.push_back(letter);
				backtrack(combinations, phoneMap, digits, index + 1, combination);
				combination.pop_back();
			}
		}
	}
};
#endif
//leetcode submit region end(Prohibit modification and deletion)


int main(int argc, char *argv[])
{
	Solution sol;
	string digits = "23";
	auto arr = sol.letterCombinations(digits);
	for (int i = 0; i < arr.size(); ++i)
	{
		cout << "" << i << " : " << arr[i] << endl;
	}

//	vector<string> vec;
//	vec.push_back(string());
//	auto& str = vec[0];
//	str = "aabbc";
//	cout<<vec[0]<<endl;
	return 0;
}
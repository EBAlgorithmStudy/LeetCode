//给定一个字符串数组 arr，字符串 s 是将 arr 某一子序列字符串连接所得的字符串，如果 s 中的每一个字符都只出现过一次，那么它就是一个可行解。 
//
// 请返回所有可行解 s 中最长长度。 
//
// 
//
// 示例 1： 
//
// 输入：arr = ["un","iq","ue"]
//输出：4
//解释：所有可能的串联组合是 "","un","iq","ue","uniq" 和 "ique"，最大长度为 4。
// 
//
// 示例 2： 
//
// 输入：arr = ["cha","r","act","ers"]
//输出：6
//解释：可能的解答有 "chaers" 和 "acters"。
// 
//
// 示例 3： 
//
// 输入：arr = ["abcdefghijklmnopqrstuvwxyz"]
//输出：26
// 
//
// 
//
// 提示： 
//
// 
// 1 <= arr.length <= 16 
// 1 <= arr[i].length <= 26 
// arr[i] 中只含有小写英文字母 
// 
// Related Topics 位运算 回溯算法 
// 👍 137 👎 0

using namespace std;
#include "string"
#include "vector"
//leetcode submit region begin(Prohibit modification and deletion)
class Solution
{
private:
	int TransToMsk(const std::string &item)
	{
		int i = 0;
		for (auto iter : item)
		{
			i = i | (1 << (iter - 'a'));
		}
		return i;
	}
public:
	//当前标记，当前位置，剩余长度
	int ChkLen(int cur_msk, int index, int remain_size, vector<int> msk_arr, vector<string> arr)
	{
		if(remain_size == 0)
		{
			return 0;
		}

	}
	int maxLength(vector<string> &arr)
	{
		vector<int> msk_arr;
		for (auto iter : arr)
		{
			msk_arr.push_back(TransToMsk(iter));
		}
		int cur_msk = 0;
		int mak_len = 0;
		for (int i = 0; i < arr.size(); ++i)
		{
			auto tmp = ChkLen(cur_msk, 0, arr.size() - i - 1, msk_arr, arr);
			if (cur_msk < tmp)
				cur_msk = tmp;
		}
	}
};
//leetcode submit region end(Prohibit modification and deletion)


int main(int argc, char *argv[])
{
	printf("--------a:%d", 'a');
	return 0;
}
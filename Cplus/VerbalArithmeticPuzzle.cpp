#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution
{
public:
	bool isSolvable(vector<string> &words, string result)
	{
		vector<int> digit(10);
		for (int i = 0; i < 10; i++)
			digit[i] = i;
		charindex.clear();
		int index = 0;
		for (auto &word : words)
		{
			for (auto &c : word)
				if (charindex.find(c) == charindex.end())
					charindex[c] = index++;
		}
		for (auto &c : result)
			if (charindex.find(c) == charindex.end())
				charindex[c] = index++;
		return permutation(digit, charindex.size(), 0, words, result);
	}

	bool permutation(vector<int> &digit, int n, int index, vector<string> &words, string &result)
	{
		if (index >= n)
			return checkValid(words, result, digit);
		for (int i = index; i < (int)digit.size(); i++)
		{
			swap(digit[index], digit[i]);
			if (permutation(digit, n, index + 1, words, result))
				return true;
			swap(digit[index], digit[i]);
		}
		return false;
	}

	bool checkValid(vector<string> &words, string &result, vector<int> &digit)
	{
		for (auto &word : words)
		{
			if (digit[charindex[word[0]]] == 0)
				return false;
		}
		if (digit[charindex[result[0]]] == 0)
			return false;
		int res = 0;
		for (auto &c : result)
			res = res * 10 + digit[charindex[c]];
		for (auto &word : words)
		{
			int tmp = 0;
			for (auto &c : word)
				tmp = tmp * 10 + digit[charindex[c]];
			res -= tmp;
			if (res < 0)
				return false;
		}
		return res == 0;
	}

private:
	unordered_map<char, int> charindex;
};

int main()
{
	Solution sol;
	vector<string> v = {"SEND", "MORE"};
	bool res = sol.isSolvable(v, "MONEY");
	return 0;
}
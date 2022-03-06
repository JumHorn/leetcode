#include <string>
#include <vector>
using namespace std;

//Fenwick tree(BIT)
class Fenwick
{
public:
	Fenwick(int size) : tree(size + 1) {}

	int sum(int index) const
	{
		int res = 0;
		for (++index; index > 0; index -= index & -index)
			res += tree[index];
		return res;
	}

	void update(int index, int delta)
	{
		int N = tree.size();
		for (++index; index < N; index += index & -index)
			tree[index] += delta;
	}

private:
	vector<int> tree;
};
/********end of Fenwick tree(BIT)********/

class Solution
{
public:
	int minMovesToMakePalindrome(string s)
	{
		int N = s.length(), res = 0;
		Fenwick bit(N);
		vector<vector<int>> pos(26);
		for (int i = N - 1; i >= 0; --i)
		{
			pos[s[i] - 'a'].push_back(i);
			bit.update(i, 1);
		}
		vector<int> seen(N);
		for (int i = N - 1; i >= 0; --i)
		{
			if (seen[i] == 1)
				continue;
			int original_index = pos[s[i] - 'a'].back();
			pos[s[i] - 'a'].pop_back();
			int current_index = bit.sum(original_index) - 1;
			if (original_index == i)
				res += current_index / 2;
			else
				res += current_index;
			bit.update(original_index, -1);
			seen[original_index] = 1;
		}
		return res;
	}
};
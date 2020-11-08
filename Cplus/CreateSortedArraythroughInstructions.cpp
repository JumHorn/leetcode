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
	int createSortedArray(vector<int> &instructions)
	{
		int N = instructions.size(), res = 0;
		Fenwick bit(1e5 + 1);
		for (int i = 0; i < N; ++i)
		{
			res = (res + min(bit.sum(instructions[i] - 1), i - bit.sum(instructions[i]))) % MOD;
			bit.update(instructions[i], 1);
		}
		return res;
	}

private:
	static const int MOD = 1e9 + 7;
};
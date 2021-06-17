#include <unordered_map>
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
	vector<int> processQueries(vector<int> &queries, int m)
	{
		int N = queries.size();
		Fenwick bit(N + m); //binary index tree
		vector<int> res;
		unordered_map<int, int> indexmap; //{val,index}
		for (int i = 0; i < m; ++i)
		{
			indexmap[i + 1] = i + N;
			bit.update(i + N, 1);
		}
		for (auto n : queries)
		{
			int index = indexmap[n];
			res.push_back(bit.sum(index) - 1);
			bit.update(index, -1);
			indexmap[n] = --N;
			bit.update(N, 1);
		}
		return res;
	}
};
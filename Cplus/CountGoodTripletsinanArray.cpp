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
	long long goodTriplets(vector<int> &nums1, vector<int> &nums2)
	{
		int N = nums1.size();
		vector<int> pos(N);
		for (int i = 0; i < N; ++i)
			pos[nums2[i]] = i;

		//number of elements on nums1[i]'s left in both A and B
		vector<int> prefix(N);
		Fenwick bit0(N);
		bit0.update(pos[nums1[0]], 1);
		for (int i = 1; i < N; ++i)
		{
			prefix[i] = bit0.sum(pos[nums1[i]]);
			bit0.update(pos[nums1[i]], 1);
		}

		//number of elements on nums1[i]'s right in both A and B
		vector<int> suffix(N);
		Fenwick bit1(N);
		bit1.update(pos[nums1[N - 1]], 1);
		for (int i = N - 2; i >= 0; --i)
		{
			suffix[i] = N - i - 1 - bit1.sum(pos[nums1[i]]);
			bit1.update(pos[nums1[i]], 1);
		}
		// calculate the result
		long long res = 0;
		for (int i = 0; i < N; ++i)
			res += (long long)prefix[i] * suffix[i];
		return res;
	}
};
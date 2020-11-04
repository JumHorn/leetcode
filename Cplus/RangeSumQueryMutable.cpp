#include <vector>
using namespace std;

class SegmentTree
{
public:
	SegmentTree(int n) : data(2 * n)
	{
	}

	SegmentTree(vector<int> &v) : data(2 * v.size())
	{
		int n = v.size();
		for (int i = 0; i < n; ++i)
			data[i + n] = v[i];
		for (int i = n - 1; i > 0; --i)
			data[i] = data[i << 1] + data[i << 1 | 1];
	}

	//update index with value val
	void update(int index, int val)
	{
		int n = data.size() / 2, delta = val - data[index + n];
		for (index += n; index > 0; index >>= 1)
			data[index] += delta;
	}

	//[start,end) query range start included and end not included
	int queryRange(int start, int end)
	{
		int n = data.size() / 2, res = 0;
		for (int l = start + n, r = end + n; l < r; l >>= 1, r >>= 1)
		{
			if (l & 1)
				res += data[l++];
			if (r & 1)
				res += data[--r];
		}
		return res;
	}

private:
	vector<int> data; //tree data with 0 index reserved
};

class NumArray
{
public:
	NumArray(vector<int> &nums) : tree(nums)
	{
	}

	void update(int i, int val)
	{
		tree.update(i, val);
	}

	int sumRange(int i, int j)
	{
		return tree.queryRange(i, j + 1);
	}

private:
	SegmentTree tree;
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(i,val);
 * int param_2 = obj->sumRange(i,j);
 */
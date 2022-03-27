#include <vector>
using namespace std;

class SegmentTree
{
public:
	SegmentTree(int size) : tree(4 * size)
	{
	}

	SegmentTree(vector<int> &data) : tree(data.size() << 2)
	{
		build_tree(data, 0, data.size(), ROOT_ID);
	}

	//update index with value val
	void update(int index, int val)
	{
		int N = tree.size() >> 2;
		update_tree(index, val, 0, N, ROOT_ID);
	}

	//[first,last) query range first included and last not included
	int queryRange(int first, int last)
	{
		int N = tree.size() >> 2;
		return query_tree(0, N, first, last, ROOT_ID);
	}

private:
	// [L,R) means data range
	void build_tree(vector<int> &data, int L, int R, int root)
	{
		if (R - L <= 1)
		{
			tree[root] = data[L];
			return;
		}
		int mid = (R - L) / 2 + L;
		int left_node = root << 1, right_node = root << 1 | 1;
		build_tree(data, L, mid, left_node);
		build_tree(data, mid, R, right_node);
		tree[root] = tree[left_node] + tree[right_node];
	}

	void update_tree(int index, int val, int L, int R, int root)
	{
		if (R - L <= 1)
		{
			tree[root] = val;
			return;
		}
		int mid = (R - L) / 2 + L;
		int left_node = root << 1, right_node = root << 1 | 1;
		if (index < mid)
			update_tree(index, val, L, mid, left_node);
		else
			update_tree(index, val, mid, R, right_node);

		tree[root] = tree[left_node] + tree[right_node];
	}

	int query_tree(int L, int R, int first, int last, int root)
	{
		if (R <= first || L >= last)
			return 0;
		if (L >= first && R <= last)
			return tree[root];
		int mid = (R - L) / 2 + L;
		int left_node = root << 1, right_node = root << 1 | 1;
		int res = 0;
		res += query_tree(L, mid, first, last, left_node);
		res += query_tree(mid, R, first, last, right_node);
		return res;
	}

private:
	vector<int> tree;			  //tree data with 0 index reserved
	static const int ROOT_ID = 1; //use 1 as the root index
};

class NumArray
{
public:
	NumArray(vector<int> &nums) : tree(nums)
	{
	}

	void update(int index, int val)
	{
		tree.update(index, val);
	}

	int sumRange(int left, int right)
	{
		return tree.queryRange(left, right + 1);
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
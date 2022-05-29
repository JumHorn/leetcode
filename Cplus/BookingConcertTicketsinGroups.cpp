#include <list>
#include <vector>
using namespace std;

//Segment Tree Template
/*
最重要的部分是如何合并两个node
合并node可以用一个函数merge，为了方便，和代码简洁，用了运算符重载
即 merge(SegmentNode1,SegmentNode2) 和 SegmentNode1+SegmentNode2 等价
*/

//user defined data
struct SegmentNode
{
	long long sum;
	int maxremain;

	SegmentNode(int all = 0, int remain = 0) : sum(all), maxremain(remain)
	{
	}

	// most important merge part
	SegmentNode operator+(SegmentNode &other)
	{
		SegmentNode res;
		res.maxremain = max(maxremain, other.maxremain);
		res.sum = sum + other.sum;
		return res;
	}
};

class SegmentTree
{
public:
	SegmentTree(int n, int m) : tree(4 * n)
	{
		build_tree(n, m, 0, n, ROOT_ID);
	}

	//update index with value val
	void update(int index, int val)
	{
		int N = tree.size() >> 2;
		update_tree(index, val, 0, N, ROOT_ID);
	}

	// dfs to remove k seats from tree
	void update_range(int k, int maxRow)
	{
		int N = tree.size() >> 2;
		update_tree_remove(0, N, 0, maxRow, ROOT_ID, k);
	}

	long long querySum(int maxRow)
	{
		int N = tree.size() >> 2;
		return query_tree_sum(0, N, 0, maxRow, ROOT_ID);
	}

	vector<int> queryMax(int k, int maxRow)
	{
		int N = tree.size() >> 2;
		return query_tree_max(0, N, 0, maxRow, ROOT_ID, k);
	}

private:
	// [L,R) means data range
	void build_tree(int n, int m, int L, int R, int root)
	{
		if (R - L <= 1)
		{
			tree[root] = SegmentNode(m, m);
			return;
		}
		int mid = (R - L) / 2 + L;
		int left_node = root << 1, right_node = root << 1 | 1;
		build_tree(n, m, L, mid, left_node);
		build_tree(n, m, mid, R, right_node);
		tree[root] = tree[left_node] + tree[right_node];
	}

	void update_tree(int index, int val, int L, int R, int root)
	{
		if (R - L <= 1)
		{
			tree[root] = SegmentNode(val, val);
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

	void update_tree_remove(int L, int R, int first, int last, int root, int &k)
	{
		if (k <= 0)
			return;
		if (R <= first || L >= last)
			return;
		if (tree[root].sum <= 0)
			return;
		if (R - L <= 1 && L >= first)
		{
			if (tree[root].sum >= k)
			{
				tree[root].sum -= k;
				tree[root].maxremain -= k;
				k = 0;
			}
			else
			{
				k -= tree[root].sum;
				tree[root].maxremain -= tree[root].sum;
				tree[root].sum = 0;
			}
			return;
		}
		int mid = (R - L) / 2 + L;
		int left_node = root << 1, right_node = root << 1 | 1;
		update_tree_remove(L, mid, first, last, left_node, k);
		update_tree_remove(mid, R, first, last, right_node, k);
		tree[root] = tree[left_node] + tree[right_node];
	}

	long long query_tree_sum(int L, int R, int first, int last, int root)
	{
		if (R <= first || L >= last)
			return 0;
		if (L >= first && R <= last)
			return tree[root].sum;
		int mid = (R - L) / 2 + L;
		int left_node = root << 1, right_node = root << 1 | 1;
		long long res = 0;
		res += query_tree_sum(L, mid, first, last, left_node);
		res += query_tree_sum(mid, R, first, last, right_node);
		return res;
	}

	vector<int> query_tree_max(int L, int R, int first, int last, int root, int k)
	{
		if (R <= first || L >= last)
			return {};
		if (R - L <= 1 && L >= first)
		{
			if (tree[root].maxremain >= k)
				return {L, tree[root].maxremain};
		}
		int mid = (R - L) / 2 + L;
		int left_node = root << 1, right_node = root << 1 | 1;
		vector<int> res;
		if (tree[left_node].maxremain >= k)
			res = query_tree_max(L, mid, first, last, left_node, k);
		if (res.empty() && tree[right_node].maxremain >= k)
			res = query_tree_max(mid, R, first, last, right_node, k);
		return res;
	}

private:
	vector<SegmentNode> tree;	  //tree data with 0 index reserved
	static const int ROOT_ID = 1; //use 1 as the root index
};
/********end of Segment Tree Template********/

class BookMyShow
{
public:
	BookMyShow(int n, int m) : sgtree(n, m)
	{
		row = n;
		col = m;
	}

	vector<int> gather(int k, int maxRow)
	{
		auto res = sgtree.queryMax(k, maxRow + 1);
		if (res.empty())
			return res;
		sgtree.update(res[0], res[1] - k);
		return {res[0], col - res[1]};
	}

	bool scatter(int k, int maxRow)
	{
		long long all = sgtree.querySum(maxRow + 1);
		if (all < k)
			return false;
		sgtree.update_range(k, maxRow + 1);
		return true;
	}

private:
	int row, col;
	SegmentTree sgtree; //store {max,sum} of each row segment
};

/**
 * Your BookMyShow object will be instantiated and called as such:
 * BookMyShow* obj = new BookMyShow(n, m);
 * vector<int> param_1 = obj->gather(k,maxRow);
 * bool param_2 = obj->scatter(k,maxRow);
 */
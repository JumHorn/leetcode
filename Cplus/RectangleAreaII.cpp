#include <algorithm>
#include <climits>
#include <set>
#include <unordered_map>
#include <vector>
using namespace std;

/*
Algorithm
Y axis line scan
improved with segment tree on x coordinate compression
*/

//user defined data
struct SegmentNode
{
	long long x_width_sum; // if count>0 x_width_sum is calculated
	int left, right;	   //range [left,right]
	int count;

	SegmentNode(int val = 0)
	{
		x_width_sum = count = left = right = 0;
	}

	// most important merge part
	// SegmentNode operator+(SegmentNode &other)
	// {
	// 	SegmentNode res;
	// 	res.x_width_sum = x_width_sum + other.x_width_sum;
	// 	return res;
	// }
};

class SegmentTree
{
public:
	SegmentTree(vector<int> &x) : tree(8 * (x.size() + 1)), x_val(x)
	{
		int N = x_val.size() - 1;
		build_tree(0, N, ROOT_ID); //build [left,right] for each node
	}

	//update index with value val
	void update(int index1, int index2, int val)
	{
		int N = x_val.size() - 1;
		update_tree(index1, index2, val, 0, N, ROOT_ID);
	}

	//[first,last] query range
	long long queryRange(int first, int last)
	{
		int N = x_val.size() - 1;
		return query_tree(0, N, first, last, ROOT_ID);
	}

	long long queryAll()
	{
		return tree[ROOT_ID].x_width_sum;
	}

private:
	// [L,R) means data range
	void build_tree(int L, int R, int root)
	{
		tree[root].left = L;
		tree[root].right = R;
		if (R - L <= 1)
			return;
		int mid = (R - L) / 2 + L;
		int left_node = root << 1, right_node = root << 1 | 1;
		build_tree(L, mid, left_node);
		build_tree(mid, R, right_node);
	}

	// [L,R] included
	void update_tree(int index1, int index2, int val, int L, int R, int root)
	{
		if (index1 >= index2)
			return;
		int left_node = root << 1, right_node = root << 1 | 1;

		if (tree[root].left == index1 && tree[root].right == index2)
			tree[root].count += val;
		else
		{
			int mid = (R - L) / 2 + L;
			update_tree(index1, min(index2, mid), val, L, mid, left_node);
			update_tree(max(index1, mid), index2, val, mid, R, right_node);
		}

		if (tree[root].count > 0)
			tree[root].x_width_sum = x_val[R] - x_val[L];
		else
			tree[root].x_width_sum = tree[left_node].x_width_sum + tree[right_node].x_width_sum;
	}

	long long query_tree(int L, int R, int first, int last, int root)
	{
		if (last >= first || R <= first || L >= last)
			return 0;
		if (L == first && R == last)
			return tree[root].x_width_sum;
		int mid = (R - L) / 2 + L;
		int left_node = root << 1, right_node = root << 1 | 1;
		long long res = 0;
		res += query_tree(L, mid, first, min(last, mid), left_node);
		res += query_tree(mid, R, max(first, mid), last, right_node);
		return res;
	}

private:
	vector<int> x_val;
	vector<SegmentNode> tree;	  //tree data with 0 index reserved
	static const int ROOT_ID = 1; //use 1 as the root index
};
/********end of Segment Tree Template********/

class Solution
{
public:
	int rectangleArea(vector<vector<int>> &rectangles)
	{
		const int OPEN = 1, CLOSE = -1;
		set<int> x;						 //unique x value
		unordered_map<int, int> x_index; //{x value,index of x in x_val}
		vector<vector<int>> rect;
		for (auto &r : rectangles)
		{
			int x1 = r[0], y1 = r[1], x2 = r[2], y2 = r[3];
			rect.push_back({y1, OPEN, x1, x2});
			rect.push_back({y2, CLOSE, x1, x2});
			x.insert(x1);
			x.insert(x2);
		}
		sort(rect.begin(), rect.end());		   //sort by y(rect[0]) values
		vector<int> x_val(x.begin(), x.end()); //set of x asix value
		for (int i = 0; i < (int)x_val.size(); ++i)
			x_index.insert({x_val[i], i});

		long long res = 0, cur_y = rect[0][0];
		SegmentTree sgtree(x_val);
		for (auto &r : rect)
		{
			int y = r[0], type = r[1], x1 = r[2], x2 = r[3];
			res = (res + sgtree.queryAll() * (y - cur_y)) % MOD;
			sgtree.update(x_index[x1], x_index[x2], type);
			cur_y = y;
		}

		return res;
	}

private:
	static const int MOD = 1e9 + 7;
};
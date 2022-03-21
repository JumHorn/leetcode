#include <map>
#include <string>
#include <vector>
using namespace std;

//user defined data
struct SegmentNode
{
	int preflen;   //longest repeating prefix length
	char prechar;  //longest repeating prefix character
	int sufflen;   //longest repeating suffix length
	char suffchar; //longest repeating suffix character
	int len;	   //size of this segment
	int maxlen;	   //longest repating character length in the segment

	SegmentNode()
	{
		preflen = sufflen = len = maxlen = 0;
		prechar = suffchar = '\0';
	}

	SegmentNode(char c)
	{
		preflen = sufflen = len = maxlen = 1;
		prechar = suffchar = c;
	}

	// most important part,do not change itself
	SegmentNode operator+(SegmentNode &other)
	{
		//to do tree node merge
		SegmentNode res;
		res.preflen = preflen;
		res.prechar = prechar;
		res.sufflen = other.sufflen;
		res.suffchar = other.suffchar;
		res.len = len + other.len;
		res.maxlen = max(maxlen, other.maxlen);
		if (suffchar == other.prechar) //same char in the middle can be merged
		{
			if (len == sufflen)
				res.preflen += other.preflen;
			if (other.len == other.preflen)
				res.sufflen += sufflen;
			res.maxlen = max(res.maxlen, sufflen + other.preflen);
		}
		return res;
	}
};

class SegmentTree
{
public:
	SegmentTree(int size) : tree(4 * size)
	{
	}

	SegmentTree(string &data) : tree(data.size() << 2)
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

	int queryAll()
	{
		return tree[ROOT_ID].maxlen;
	}

private:
	// [L,R) means data range
	void build_tree(string &data, int L, int R, int root)
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
			return tree[root].maxlen;
		int mid = (R - L) / 2 + L;
		int left_node = root << 1, right_node = root << 1 | 1;
		int res = 0;
		res = max(res, query_tree(L, mid, first, last, left_node));
		res = max(res, query_tree(mid, R, first, last, right_node));
		return res;
	}

private:
	vector<SegmentNode> tree;	  //tree data with 0 index reserved
	static const int ROOT_ID = 1; //use 1 as the root index
};

class Solution
{
public:
	vector<int> longestRepeating(string s, string queryCharacters, vector<int> &queryIndices)
	{
		SegmentTree tree(s);
		vector<int> res;
		int N = queryCharacters.length();
		for (int i = 0; i < N; ++i)
		{
			int index = queryIndices[i];
			char c = queryCharacters[i];
			tree.update(index, c);
			res.push_back(tree.queryAll());
		}
		return res;
	}
};
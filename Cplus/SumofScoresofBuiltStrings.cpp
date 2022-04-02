#include <algorithm>
#include <numeric>
#include <string>
#include <vector>
using namespace std;

//suffix array

/*
	sa[i] the ith rank's index
	rank[i] the ith index's rank

	1. sa[rank[i]]=i the i means index
	2 .rank[sa[i]]=i the i means rank

	3. lcp[i] >= lcp[i-1]-1
*/

struct SuffixArray
{
	int index;
	int currank;
	int nextrank;

	bool operator<(const SuffixArray &other) const
	{
		if (currank != other.currank)
			return currank < other.currank;
		return nextrank < other.nextrank;
	}
};

//return the ith rank's index as Suffix Array
vector<int> generateSuffixArray(string &data)
{
	int N = data.size();
	vector<SuffixArray> sa(N);
	//init
	for (int i = 0; i < N - 1; ++i)
	{
		sa[i].index = i;
		sa[i].currank = data[i];
		sa[i].nextrank = data[i + 1];
	}
	sa[N - 1].index = N - 1;
	sa[N - 1].currank = data[N - 1];
	sa[N - 1].nextrank = -1;
	sort(sa.begin(), sa.end());

	vector<int> rank(N);
	for (int k = 4; k < 2 * N; k *= 2)
	{
		int rank_count = 0;
		int pre_rank = sa[0].currank;
		sa[0].currank = rank_count;
		rank[sa[0].index] = 0;
		//update rank
		for (int i = 1; i < N; ++i)
		{
			if (sa[i].currank == pre_rank && sa[i].nextrank == sa[i - 1].nextrank)
				sa[i].currank = rank_count;
			else
			{
				pre_rank = sa[i].currank;
				sa[i].currank = ++rank_count;
			}
			rank[sa[i].index] = i;
		}
		for (int i = 0; i < N; ++i)
		{
			int nextindex = sa[i].index + k / 2;
			sa[i].nextrank = (nextindex < N) ? sa[rank[nextindex]].currank : -1;
		}
		sort(sa.begin(), sa.end());
	}

	vector<int> res;
	for (auto n : sa)
		res.push_back(n.index);
	return res;
}

// return lcp array
vector<int> generateLcpFromSuffixArray(string &str, vector<int> &sa)
{
	int N = str.length();
	//lcp[i] is lcp of sa[i] and sa[i + 1],the last one is 0
	vector<int> lcp(N), rank(N);
	for (int i = 0; i < N; ++i)
		rank[sa[i]] = i;
	for (int i = 0, k = 0; i < N; ++i)
	{
		if (rank[i] == N - 1)
			lcp[rank[i]] = k = 0;
		else
		{
			int j = sa[rank[i] + 1];
			while (i + k < N && j + k < N && str[i + k] == str[j + k])
				++k;
			lcp[rank[i]] = k;
			if (k > 0)
				--k;
		}
	}
	return lcp;
}
/********end of suffix array********/

//user defined data
struct SegmentNode
{
	int data;
	int l, r; //[l,r] of segment
	int lcp;  //value of lcp[r]

	SegmentNode()
	{
		data = l = r = lcp = 0;
	}

	SegmentNode(int val, int left, int right, int len)
	{
		data = val;
		l = left;
		r = right;
		lcp = len;
	}

	// most important merge part
	SegmentNode operator+(SegmentNode &other)
	{
		return SegmentNode(min({data, other.data, lcp}), l, other.r, other.lcp);
	}
};

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
			tree[root] = SegmentNode(data[L], L, L, data[L]);
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
			tree[root] = SegmentNode(val, L, L, val);
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
			return INT_MAX; //not exist
		if (L >= first && R <= last)
			return tree[root].data;
		int mid = (R - L) / 2 + L;
		int left_node = root << 1, right_node = root << 1 | 1;
		return min(query_tree(L, mid, first, last, left_node),
				   query_tree(mid, R, first, last, right_node));
	}

private:
	vector<SegmentNode> tree;	  //tree data with 0 index reserved
	static const int ROOT_ID = 1; //use 1 as the root index
};
/********end of Segment Tree Template********/

class Solution
{
public:
	long long sumScores(string s)
	{
		int N = s.size();
		auto sa = generateSuffixArray(s);
		//lcp[i] is lcp of sa[i] and sa[i + 1],the last one is 0
		vector<int> lcp(N), rank(N);
		for (int i = 0; i < N; ++i)
			rank[sa[i]] = i;
		for (int i = 0, k = 0; i < N; ++i)
		{
			if (rank[i] == N - 1)
				lcp[rank[i]] = k = 0;
			else
			{
				int j = sa[rank[i] + 1];
				while (i + k < N && j + k < N && s[i + k] == s[j + k])
					++k;
				lcp[rank[i]] = k;
				if (k > 0)
					--k;
			}
		}

		SegmentTree sgtree(lcp);
		long long res = 0;
		for (int i = 1; i < N; ++i)
		{
			int l = rank[0], r = rank[i];
			if (l >= r)
				swap(l, r);
			res += sgtree.queryRange(l, r);
		}
		return res + N;
	}
};
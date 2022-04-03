#include <algorithm>
#include <numeric>
#include <string>
#include <vector>
using namespace std;

//suffix array (SAIS)

/*
	sa[i] the ith rank's index
	rank[i] the ith index's rank

	1. sa[rank[i]]=i the i means index
	2 .rank[sa[i]]=i the i means rank

	3. lcp[i] >= lcp[i-1]-1
*/
class SuffixArray
{
private:
	using size_type = unsigned;
	using pointer = size_type *;
	using const_pointer = const size_type *;
	std::unique_ptr<size_type[]> data;

public:
	// suffix array
	pointer sa;
	// rank
	pointer rank;
	// longest common prefix
	pointer lcp;
	// max longest common prefix
	template <typename S>
	static bool substring_equal(const S &s, size_type p1, size_type p2, size_type len)
	{
		for (size_type i = 0; i < len; ++i)
			if (s[p1 + i] != s[p2 + i])
				return false;
		return true;
	}

	template <typename S>
	static void induced_sort(
		const S &s,
		pointer sa,
		bool *type,
		pointer pos,
		pointer lbuk,
		pointer sbuk,
		size_type n,
		size_type m,
		size_type n0)
	{
		std::fill_n(sa, n, 0);
		lbuk[0] = 0;
		for (size_type i = 1; i < m; ++i)
			lbuk[i] = sbuk[i - 1];
		for (size_type i = n0; i-- > 0;)
			sa[--sbuk[s[pos[i]]]] = pos[i];
		sbuk[m - 1] = n;
		for (size_type i = 1; i < m; ++i)
			sbuk[i - 1] = lbuk[i];
		sa[lbuk[s[n - 1]]++] = n - 1;
		for (size_type i = 0; i < n; ++i)
			if (sa[i] > 0 && !type[sa[i] - 1])
				sa[lbuk[s[sa[i] - 1]]++] = sa[i] - 1;
		lbuk[0] = 0;
		for (size_type i = 1; i < m; ++i)
			lbuk[i] = sbuk[i - 1];
		for (size_type i = n; i-- > 0;)
			if (sa[i] > 0 && type[sa[i] - 1])
				sa[--sbuk[s[sa[i] - 1]]] = sa[i] - 1;
	}

	template <typename S>
	static void sais(
		const S &s,
		pointer sa,
		bool *type,
		pointer len,
		pointer pos,
		pointer lbuk,
		pointer sbuk,
		size_type n,
		size_type m)
	{
		type[n - 1] = false;
		for (size_type i = n - 1; i-- > 0;)
			type[i] = s[i] != s[i + 1] ? s[i] < s[i + 1] : type[i + 1];
		size_type n0 = 0;
		for (size_type i = 1; i < n; ++i)
			if (!type[i - 1] && type[i])
				pos[n0++] = i;
		std::fill_n(len, n, 0);
		for (size_type p = n - 1, i = n0; i-- > 0; p = pos[i])
			len[pos[i]] = p - pos[i] + 1;
		std::fill_n(sbuk, m, 0);
		for (size_type i = 0; i < n; ++i)
			++sbuk[s[i]];
		for (size_type i = 1; i < m; ++i)
			sbuk[i] += sbuk[i - 1];
		induced_sort(s, sa, type, pos, lbuk, sbuk, n, m, n0);
		sbuk[m - 1] = n;
		for (size_type i = 1; i < m; ++i)
			sbuk[i - 1] = lbuk[i];
		size_type m0 = -1;
		size_type ppos = -1, plen = 0;
		for (size_type i = 0; i < n; ++i)
		{
			if (len[sa[i]] == 0)
				continue;
			if (len[sa[i]] != plen || !substring_equal(s, sa[i], ppos, plen))
				++m0;
			plen = len[sa[i]];
			len[sa[i]] = m0;
			ppos = sa[i];
		}
		pointer s0 = sa;
		pointer sa0 = sa + n0;
		for (size_type i = 0; i < n0; ++i)
			s0[i] = len[pos[i]];
		if (++m0 < n0)
			sais(s0, sa0, type + n, len, pos + n0, lbuk, lbuk + n0, n0, m0);
		else
			for (size_type i = 0; i < n0; ++i)
				sa0[s0[i]] = i;
		for (size_type i = 0; i < n0; ++i)
			pos[i + n0] = pos[sa0[i]];
		induced_sort(s, sa, type, pos + n0, lbuk, sbuk, n, m, n0);
	}

	SuffixArray(const std::string &s, size_type n, size_type m)
		: data(std::make_unique<size_type[]>(3 * n)), sa(data.get()), rank(sa + n), lcp(rank + n)
	// , max_lcp_pos(n)
	{
		const auto type = std::make_unique<bool[]>(2 * n);
		const auto lbuk = std::make_unique<size_type[]>(std::max(n, m));
		const auto sbuk = std::make_unique<size_type[]>(m);
		sais(s, sa, type.get(), rank, lcp, lbuk.get(), sbuk.get(), n, m);
		// kaisa
		for (size_type i = 0; i < n; ++i)
			rank[sa[i]] = i;
		for (size_type k = 0, i = 0; i < n; ++i)
		{
			if (rank[i] == 0)
				continue;
			if (k > 0)
				--k;
			size_type j = sa[rank[i] - 1];
			while (i + k < n && j + k < n && s[i + k] == s[j + k])
				++k;
			lcp[rank[i]] = k;
		}
	}
};
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
		SuffixArray sa(s, N, 128);
		//lcp[i] is lcp of sa[i] and sa[i - 1],the first one is 0
		vector<int> lcp;
		for (int i = 0; i < N; ++i)
			lcp.push_back(sa.lcp[i]);

		SegmentTree sgtree(lcp);
		long long res = 0;
		for (int i = 1; i < N; ++i)
		{
			int l = sa.rank[0], r = sa.rank[i];
			if (l >= r)
				swap(l, r);
			res += sgtree.queryRange(l + 1, r + 1);
		}
		return res + N;
	}
};
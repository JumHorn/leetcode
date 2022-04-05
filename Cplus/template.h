#include <algorithm>
#include <queue>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

//frequently used functions

int gcd(int x, int y)
{
	return x == 0 ? y : gcd(y % x, x);
}

// palindrome generator
int generatePalindrome()
{
	for (int len = 1;; ++len)
	{
		int x = pow(10, (len - 1) / 2), y = pow(10, (len + 1) / 2);
		for (int i = x; i < y; ++i)
		{
			long long val = i;
			for (int j = len % 2 == 1 ? i / 10 : i; j > 0; j /= 10)
				val = val * 10 + j % 10;
			// todo val is pandrome
		}
	}
}

// pow with mod
long long modPow(long long x, int n)
{
	static const int MOD = 1e9 + 7;
	long long res = 1;
	for (auto i = n; i > 0; i /= 2)
	{
		if (i % 2)
			res = res * x % MOD;
		x = x * x % MOD;
	}
	return res;
}

// factorial stuff
void produceFactorial(int n)
{
	static const int MOD = 1e9 + 7;
	// Pre-process fac and inverse fac.
	vector<long long> fac(n + 1, 1), ifac(n + 1, 1);
	for (int i = 2; i <= n; ++i)
	{
		fac[i] = fac[i - 1] * i % MOD;
		ifac[i] = modPow(fac[i], MOD - 2);
	}
}

//combination table
void createCombinationTable(int N)
{
	vector<vector<int>> combination(N + 1, vector<int>(N + 1));
	combination[0][0] = 1;
	for (int i = 1; i <= N; ++i)
	{
		combination[i][0] = combination[i][i] = 1;
		for (int j = 1; j <= i / 2; ++j)
			combination[i][j] = combination[i][i - j] = combination[i - 1][j] + combination[i - 1][j - 1];
	}
}

//dijkstra
vector<int> dijkstra(vector<vector<pair<int, int>>> &graph, int source)
{
	int N = graph.size();
	vector<int> distance(N, INT_MAX);
	distance[source] = 0;
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q; //{distance,node}
	q.push({0, source});
	while (!q.empty())
	{
		auto top = q.top();
		q.pop();
		if (top.first > distance[top.second])
			continue;
		for (auto [node, weight] : graph[top.second])
		{
			if (weight + top.first < distance[node])
			{
				distance[node] = weight + top.first;
				q.push({distance[node], node});
			}
		}
	}
	return distance;
}
/********end of dijkstra********/

//DSU minimum version
class DSU
{
public:
	DSU(int size) : parent(size)
	{
		for (int i = 0; i < size; ++i)
			parent[i] = i;
	}

	int Find(int x)
	{
		if (x != parent[x])
			parent[x] = Find(parent[x]);
		return parent[x];
	}

	bool Union(int x, int y)
	{
		int xp = Find(x), yp = Find(y);
		if (xp == yp)
			return false;
		parent[yp] = xp;
		return true;
	}

private:
	vector<int> parent;
};
/********end of DSU minimum version********/

//DSU string version
class DSU
{
public:
	string Find(const string &str)
	{
		if (parent.find(str) != parent.end() && str != parent[str])
			parent[str] = Find(parent[str]);
		else
			parent[str] = str;
		return parent[str];
	}

	bool Union(const string &x, const string &y)
	{
		string xp = Find(x), yp = Find(y);
		if (xp == yp)
			return false;
		parent[yp] = xp;
		return true;
	}

private:
	unordered_map<string, string> parent;
};
/********end of DSU string version********/

//divide and conquer
void merge(vector<int> &arr, vector<int> &dup, int first, int mid, int last)
{
	for (int i = first, j = mid, d = 0; i < mid || j < last;)
	{
		if (i == mid)
			dup[d++] = arr[j++];
		else if (j == last)
			dup[d++] = arr[i++];
		else
			dup[d++] = (arr[i] > arr[j]) ? arr[j++] : arr[i++];
	}
	for (int i = first, j = 0; i < last; ++i, ++j)
		arr[i] = dup[j];
}

void divide(vector<int> &arr, vector<int> &dup, int first, int last)
{
	if (last - first <= 1)
		return;
	int mid = first + (last - first) / 2;
	divide(arr, dup, first, mid);
	divide(arr, dup, mid, last);
	//to do
	merge(arr, dup, first, mid, last);
}
/********end of divide and conquer********/

//Trie
class Trie
{
	struct TreeNode
	{
		int count; //number of words ends with this node
		vector<TreeNode *> nodes;

		TreeNode() : count(0), nodes(26, nullptr) {}
	};

public:
	Trie()
	{
		root = new TreeNode();
	}

	/** Inserts a word into the trie. */
	void insert(const string &word)
	{
		TreeNode *node = root;
		for (auto c : word)
		{
			int index = c - 'a';
			if (node->nodes[index] == nullptr)
				node->nodes[index] = new TreeNode();
			node = node->nodes[index];
		}
		++node->count;
	}

	/** Returns if the word is in the trie. */
	bool search(const string &word) const
	{
		TreeNode *node = searchNode(word);
		return node != nullptr && node->count > 0;
	}

	/** Returns if there is any word in the trie that starts with the given prefix. */
	bool startsWith(const string &prefix)
	{
		TreeNode *node = searchNode(prefix);
		return node != nullptr;
	}

private:
	TreeNode *root;

	TreeNode *searchNode(const string &str) const
	{
		TreeNode *node = root;
		for (auto c : str)
		{
			int index = c - 'a';
			if (node->nodes[index] == nullptr)
				return nullptr;
			node = node->nodes[index];
		}
		return node;
	}
};
/********end of Trie********/

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

//Segment Tree
class SegmentTree
{
public:
	SegmentTree(int size) : tree(2 * size)
	{
	}

	SegmentTree(vector<int> &data) : tree(2 * data.size())
	{
		int N = data.size();
		for (int i = 0; i < N; ++i)
			tree[i + N] = data[i];
		for (int i = N - 1; i > 0; --i)
			tree[i] = tree[i << 1] + tree[i << 1 | 1];
	}

	//update index with value val
	void update(int index, int val)
	{
		int N = tree.size() >> 1, delta = val - tree[index + N];
		for (index += N; index > 0; index >>= 1)
			tree[index] += delta;
	}

	//[first,last) query range first included and last not included
	int queryRange(int first, int last)
	{
		int N = tree.size() / 2, res = 0;
		for (int l = first + N, r = last + N; l < r; l >>= 1, r >>= 1)
		{
			if (l & 1)
				res += tree[l++];
			if (r & 1)
				res += tree[--r];
		}
		return res;
	}

private:
	vector<int> tree; //tree data with 0 index reserved
};
/********end of Segment Tree********/

//Segment Tree Template
/*
最重要的部分是如何合并两个node
合并node可以用一个函数merge，为了方便，和代码简洁，用了运算符重载
即 merge(SegmentNode1,SegmentNode2) 和 SegmentNode1+SegmentNode2 等价
*/

//user defined data
struct SegmentNode
{
	int data;

	SegmentNode(int val = 0) : data(val)
	{
	}

	// most important merge part
	SegmentNode &operator+(SegmentNode &other)
	{
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
			return tree[root].data;
		int mid = (R - L) / 2 + L;
		int left_node = root << 1, right_node = root << 1 | 1;
		int res = 0;
		res += query_tree(L, mid, first, last, left_node);
		res += query_tree(mid, R, first, last, right_node);
		return res;
	}

private:
	vector<SegmentNode> tree;	  //tree data with 0 index reserved
	static const int ROOT_ID = 1; //use 1 as the root index
};
/********end of Segment Tree Template********/

//kmp next array
vector<int> createKMP(string &pattern)
{
	int N = pattern.size();
	vector<int> next(N);
	for (int i = 1, j = 0; i < N; ++i)
	{
		while (j > 0 && pattern[i] != pattern[j])
			j = next[j - 1];
		if (pattern[i] == pattern[j])
			++j;
		next[i] = j;
	}
	return next;
}
/********end of kmp next array********/

//z-function
vector<int> z_function(const string &s)
{
	int N = s.length(), start = 0; //max length prefix at start
	vector<int> z(N);
	for (int i = 1; i < N; ++i)
	{
		if (start + z[start] > i)
			z[i] = min(z[i - start], start + z[start] - i);
		while (i + z[i] < N && s[i + z[i]] == s[z[i]])
			++z[i];
		if (start + z[start] < i + z[i])
			start = i;
	}
	z[0] = N;
	return z;
}
/********end of z-function********/

//manacher
vector<int> manacher(string &s)
{
	int N = s.length();
	vector<int> radius(N, 1);
	int center = 1;	   //the center of the right most radius
	int maxradius = 1; //the right most pos of the right most radius can reach
	for (int i = 2; i < N; ++i)
	{
		if (i < maxradius)
			radius[i] = min(radius[2 * center - i], maxradius - i);
		while (s[i + radius[i]] == s[i - radius[i]]) ////with the added $,out of range avoided
			++radius[i];

		if (radius[i] + i > maxradius) //change center and the maxradius
		{
			maxradius = radius[i] + i;
			center = i;
		}
	}
	return radius;
}
/********end of manacher********/

//Fast Walsh Hadamard Transform
// https://csacademy.com/blog/fast-fourier-transform-and-variations-of-it
// Please remind that these codes are valid only when degree(P) = N = 2^k
void fwht_and(vector<int> &v, bool inverse)
{
	int N = v.size();
	for (int m = 1; 2 * m <= N; m *= 2)
	{
		for (int i = 0; i < N; i += 2 * m)
		{
			for (int j = 0; j < m; ++j)
			{
				auto x = v[i + j];
				auto y = v[i + j + m];
				if (!inverse)
				{
					v[i + j] = y;
					v[i + j + m] = x + y;
				}
				else
				{
					v[i + j] = -x + y;
					v[i + j + m] = x;
				}
			}
		}
	}
}
/********end of Fast Walsh Hadamard Transform********/

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

//max-flow (dinic algorithm)
class MaxFlow
{
public:
	MaxFlow(int n, int s, int t) : start(s), target(t)
	{
		//node numbered from 0 to n-1
		graph = vector<vector<pair<int, int>>>(n, vector<pair<int, int>>(n, {-1, -1}));
		layer = vector<int>(n);
	}

	void addEdge(int from, int to, int capacity, int flow = 0)
	{
		//residual graph we dont care about current flow
		graph[from][to] = {capacity, capacity};
		graph[to][from] = {capacity, 0};
	}

	int dinic()
	{
		int N = graph.size();
		max_flow = 0;
		while (bfs())
			max_flow += dfs(start, INT_MAX);
		return max_flow;
	}

private:
	// create layer for each node
	bool bfs()
	{
		fill(layer.begin(), layer.end(), -1);
		queue<int> q;
		q.push(start);
		layer[start] = 0;
		int l = 0, N = graph.size();
		bool res = false;
		while (!q.empty())
		{
			int size = q.size();
			++l;
			while (--size >= 0)
			{
				int at = q.front();
				q.pop();
				for (int to = 0; to < N; ++to)
				{
					if (graph[at][to].second > 0 && layer[to] == -1)
					{
						layer[to] = l;
						if (to != target)
							q.push(to);
						else
							res = true;
					}
				}
			}
		}
		return res;
	}

	//寻找增广链(augmenting path)并更新剩余图(residual graph)
	int dfs(int at, int minflow)
	{
		if (minflow == 0)
			return 0;
		if (at == target)
			return minflow;
		int N = graph.size(), res = 0;
		for (int to = 0; to < N; ++to)
		{
			if (graph[at][to].second > 0 && layer[at] + 1 == layer[to])
			{
				int flow = dfs(to, min(minflow, graph[at][to].second));

				//update residual graph
				graph[at][to].second -= flow;
				graph[to][at].second += flow;

				minflow -= flow;
				res += flow;
			}
		}
		return res;
	}

private:
	//start node
	int start;
	//target node
	int target;
	// max flow
	int max_flow;
	//adjacency matrix pair<int, int>{capacity, flow}
	vector<vector<pair<int, int>>> graph;
	//min distance from start to current node
	vector<int> layer;
};
/********end of max flow********/
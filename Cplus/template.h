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

// palinrome generator
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
/********combination table********/

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
#include <algorithm>
#include <vector>
using namespace std;

/*
sa[i] the ith rank's index
rank[i] the ith index's rank

1. sa[rank[i]]=i
2 .rank[sa[i]]=i

3. lcp[i] >= lcp[i-1]-1
此处的i下标表示原始string的下标
考虑到下标i与i+1有x长度的前缀
那么下标i+1与i+2至少有x-1长度前缀，因为除去了i与i+1的首个字符
这个问题是很简单的问题，只是概念比较复杂
*/

typedef struct
{
	int index;
	int currank;
	int nextrank;
} SuffixArray;

class Solution
{
public:
	int longestCommonSubpath(int n, vector<vector<int>> &paths)
	{
		int M = paths.size(), sentinel = 0;
		vector<int> onepath, color;
		for (auto &path : paths)
		{
			onepath.insert(onepath.end(), path.begin(), path.end());
			onepath.push_back(--sentinel);
		}
		int N = onepath.size();

		vector<SuffixArray> sa(N);
		//init
		for (int i = 0; i < N - 1; ++i)
		{
			sa[i].index = i;
			sa[i].currank = onepath[i];
			sa[i].nextrank = onepath[i + 1];
		}
		sa[N - 1].index = N - 1;
		sa[N - 1].currank = onepath[N - 1];
		sa[N - 1].nextrank = INT_MIN;
		auto f = [](const SuffixArray &lhs, const SuffixArray &rhs) {
			if (lhs.currank != rhs.currank)
				return lhs.currank < rhs.currank;
			return lhs.nextrank < rhs.nextrank;
		};
		sort(sa.begin(), sa.end(), f);

		int rank[N];
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
			sort(sa.begin(), sa.end(), f);
		}

		//calc lcp array
		int lcp[N];
		for (int i = 0; i < N; ++i)
			rank[sa[i].index] = i;
		for (int i = 0, k = 0; i < N; ++i)
		{
			if (rank[i] == N - 1)
				lcp[rank[i]] = k = 0;
			else
			{
				int j = sa[rank[i] + 1].index;
				while (i + k < N && j + k < N && onepath[i + k] == onepath[j + k])
					++k;
				lcp[rank[i]] = k;
				if (k > 0)
					--k;
			}
		}
		//calc result
		int len = lcp[0], index = 0;
		for (int i = 1; i < N; ++i)
		{
			if (lcp[i] > len)
			{
				len = lcp[i];
				index = sa[i].index;
			}
		}
		return len;
	}
};
#include <map>
#include <string>
#include <vector>
using namespace std;

class Solution
{
public:
	vector<int> longestRepeating(string s, string queryCharacters, vector<int> &queryIndices)
	{
		map<int, int> segment;	 //{index,index} of same value range 区间左闭右开
		map<int, int> sizeCount; // {segment size,count}
		int N = s.length();
		for (int i = 0, j = 0; i <= N; ++i)
		{
			if (i == N || s[i] != s[j])
			{
				segment[j] = i;
				++sizeCount[i - j];
				j = i;
			}
		}

		vector<int> res;
		for (int i = 0; i < (int)queryIndices.size(); ++i)
		{
			int index = queryIndices[i];
			char c = queryCharacters[i];
			if (s[index] == c)
			{
				res.push_back(sizeCount.rbegin()->first);
				continue;
			}
			s[index] = c;
			auto it = segment.upper_bound(index);
			if (it != segment.begin()) //must exist no need to check
				--it;
			int l = it->first, r = it->second;

			segment.erase(it);
			if (--sizeCount[r - l] == 0)
				sizeCount.erase(r - l);

			if (l < index)
			{
				segment.insert({l, index});
				++sizeCount[index - l];
			}
			if (r - 1 > index)
			{
				segment.insert({index + 1, r});
				++sizeCount[r - index - 1];
			}

			l = index, r = index + 1;
			if (index + 1 < N && s[index + 1] == c) //merge next
			{
				auto it = segment.upper_bound(index);
				r = it->second;
				if (--sizeCount[it->second - it->first] == 0)
					sizeCount.erase(it->second - it->first);
				segment.erase(it);
			}
			if (index > 0 && s[index - 1] == c) //merge pre
			{
				auto it = prev(segment.upper_bound(index));
				l = it->first;
				if (--sizeCount[it->second - it->first] == 0)
					sizeCount.erase(it->second - it->first);
				segment.erase(it);
			}
			segment[l] = r;
			++sizeCount[r - l];
			res.push_back(sizeCount.rbegin()->first);
		}
		return res;
	}
};
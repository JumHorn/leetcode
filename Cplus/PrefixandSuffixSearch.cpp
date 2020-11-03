#include <map>
#include <set>
#include <string>
#include <vector>
using namespace std;

class WordFilter
{
public:
	WordFilter(vector<string> &words)
	{
		int n = words.size();
		for (int i = 0; i < n; ++i)
			m_prefix[words[i]] = i;
	}

	int f(string prefix, string suffix)
	{
		auto iter = m_prefix.lower_bound(prefix);
		set<int> s;
		while (iter != m_prefix.end())
		{
			if (!starts_with(iter->first, prefix))
				break;
			if (ends_with(iter->first, suffix))
				s.insert(iter->second);
			++iter;
		}
		if (s.empty())
			return -1;
		return *s.rbegin();
	}

	bool starts_with(const string &s, const string &prefix)
	{
		if (prefix.empty())
			return true;
		int n = s.length(), m = prefix.length();
		int i = 0, j = 0;
		while (i < n && j < m)
		{
			if (s[i] != prefix[j])
				return false;
			++i;
			++j;
		}
		return j == m;
	}

	bool ends_with(const string &s, const string &suffix)
	{
		if (suffix.empty())
			return true;
		int n = s.length(), m = suffix.length();
		int i = n - 1, j = m - 1;
		while (i >= 0 && j >= 0)
		{
			if (s[i] != suffix[j])
				return false;
			--i;
			--j;
		}
		return j == -1;
	}

private:
	map<string, int> m_prefix;
};

/**
 * Your WordFilter object will be instantiated and called as such:
 * WordFilter* obj = new WordFilter(words);
 * int param_1 = obj->f(prefix,suffix);
 */
#include <map>
#include <string>
#include <vector>
using namespace std;

class WordFilter
{
public:
	WordFilter(vector<string> &words)
	{
		int N = words.size();
		for (int i = 0; i < N; ++i)
			m_prefix[words[i]] = i;
	}

	int f(string prefix, string suffix)
	{
		int res = -1;
		for (auto iter = m_prefix.lower_bound(prefix); iter != m_prefix.end(); ++iter)
		{
			if (!starts_with(iter->first, prefix))
				break;
			if (iter->second > res && ends_with(iter->first, suffix))
				res = iter->second;
		}
		return res;
	}

	bool starts_with(const string &s, const string &prefix)
	{
		return s.compare(0, prefix.size(), prefix) == 0;
	}

	bool ends_with(const string &s, const string &suffix)
	{
		if (suffix.length() > s.length())
			return false;
		return s.compare(s.length() - suffix.length(), suffix.length(), suffix) == 0;
	}

private:
	map<string, int> m_prefix;
};

/**
 * Your WordFilter object will be instantiated and called as such:
 * WordFilter* obj = new WordFilter(words);
 * int param_1 = obj->f(prefix,suffix);
 */
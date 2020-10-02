#include <string>
#include <unordered_set>
#include <vector>
using namespace std;

class MagicDictionary
{
public:
	/** Initialize your data structure here. */
	MagicDictionary()
	{
	}

	void buildDict(vector<string> dictionary)
	{
		for (auto &str : dictionary)
			s.insert(str);
	}

	bool search(string searchWord)
	{
		for (auto &ch : searchWord)
		{
			char old = ch;
			for (char c = 'a'; c <= 'z'; ++c)
			{
				if (c != old)
				{
					ch = c;
					if (s.find(searchWord) != s.end())
						return true;
				}
			}
			ch = old;
		}
		return false;
	}

private:
	unordered_set<string> s;
};

/**
 * Your MagicDictionary object will be instantiated and called as such:
 * MagicDictionary* obj = new MagicDictionary();
 * obj->buildDict(dictionary);
 * bool param_2 = obj->search(searchWord);
 */
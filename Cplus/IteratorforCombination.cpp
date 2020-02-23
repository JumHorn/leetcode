#include <string>
#include <vector>
using namespace std;

class CombinationIterator
{
public:
	CombinationIterator(string characters, int combinationLength)
	{
		m_index = 0;
		string tmp;
		recursive(characters, tmp, 0, combinationLength);
	}

	void recursive(const string &characters, string &tmp, int index, int len)
	{
		if ((int)tmp.size() == len)
		{
			data.push_back(tmp);
			return;
		}
		for (int i = index; i < (int)characters.size(); i++)
		{
			tmp.push_back(characters[i]);
			recursive(characters, tmp, i + 1, len);
			tmp.pop_back();
		}
	}

	string next()
	{
		if (hasNext())
			return data[m_index++];
		return "";
	}

	bool hasNext()
	{
		return m_index < (int)data.size();
	}

private:
	vector<string> data;
	int m_index;
};

/**
 * Your CombinationIterator object will be instantiated and called as such:
 * CombinationIterator* obj = new CombinationIterator(characters, combinationLength);
 * string param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */
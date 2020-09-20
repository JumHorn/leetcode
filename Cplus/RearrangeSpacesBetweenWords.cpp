#include <sstream>
#include <string>
#include <vector>
using namespace std;

class Solution
{
public:
	string reorderSpaces(string text)
	{
		int count = 0;
		for (auto c : text)
		{
			if (c == ' ')
				++count;
		}
		stringstream ss(text);
		vector<string> v;
		string word;
		while (ss >> word)
			v.push_back(word);
		int size = v.size();
		if (size == 1)
			return v[0] + string(count, ' ');
		int n = count / (size - 1);
		count %= size - 1;
		string res = v[0];
		for (int i = 1; i < size; ++i)
			res += string(n, ' ') + v[i];
		res += string(count, ' ');
		return res;
	}
};

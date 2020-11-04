#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution
{
public:
	string originalDigits(string s)
	{
		vector<int> v(10);
		vector<string> number = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
		char even[] = {'z', 'w', 'u', 'x', 'g'}; //only char 0 2 4 6 8
		char odd[] = {'o', 'h', 'f', 's'};		 //only char 1 3 5 7
		unordered_map<char, int> m;
		for (int i = 0; i < (int)s.length(); ++i)
			++m[s[i]];
		for (int i = 0; i < 5; ++i)
		{
			v[2 * i] = m[even[i]];
			for (int j = 0; j < (int)number[2 * i].length(); ++j)
				m[number[2 * i][j]] -= v[2 * i];
		}
		for (int i = 0; i < 4; ++i)
		{
			v[2 * i + 1] = m[odd[i]];
			for (int j = 0; j < (int)number[2 * i + 1].length(); ++j)
				m[number[2 * i + 1][j]] -= v[2 * i + 1];
		}
		v[9] = m['i'];
		string res;
		for (int i = 0; i < (int)v.size(); ++i)
			if (v[i] > 0)
				res += string(v[i], (char)('0' + i));
		return res;
	}
};

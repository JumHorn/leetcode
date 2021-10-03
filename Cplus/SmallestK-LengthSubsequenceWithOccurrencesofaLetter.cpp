#include <string>
using namespace std;

class Solution
{
public:
	string smallestSubsequence(string s, int k, char letter, int repetition)
	{
		int count = 0, N = s.length();
		for (auto c : s)
		{
			if (c == letter)
				++count;
		}
		string res;
		for (int i = 0; i < N; ++i)
		{
			while (!res.empty() && res.back() > s[i] && res.length() + N - i - 1 >= k)
			{
				if (res.back() != letter)
					res.pop_back();
				else if (res.back() == letter)
				{
					if (count >= repetition + 1)
					{
						++repetition;
						res.pop_back();
					}
					else
						break;
				}
			}
			if (res.length() < k)
			{
				res.push_back(s[i]);
				if (s[i] == letter)
				{
					--repetition;
					--count;
				}
			}
			else if (s[i] == letter)
			{
				--count;
				if (count < repetition)
				{
					--repetition;
					for (int j = (int)res.length() - 1; j >= 0; --j)
					{
						if (res[j] != letter)
						{
							res[j] = letter;
							break;
						}
					}
				}
			}
		}
		return res;
	}
};
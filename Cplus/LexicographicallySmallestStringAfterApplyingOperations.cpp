#include <algorithm>
#include <queue>
#include <string>
#include <unordered_set>
using namespace std;

class Solution
{
public:
	string findLexSmallestString(string s, int a, int b)
	{
		unordered_set<string> seen;
		string res = s;
		int N = s.length();
		seen.insert(s);
		queue<string> q;
		q.push(s);
		while (!q.empty())
		{
			int size = q.size();
			while (--size >= 0)
			{
				string str = q.front();
				q.pop();
				res = min(res, str);
				string added = add(str, a);
				if (seen.find(added) == seen.end())
				{
					seen.insert(added);
					q.push(added);
				}
				rotate(str, b);
				if (seen.find(str) == seen.end())
				{
					seen.insert(str);
					q.push(str);
				}
			}
		}
		return res;
	}

	string add(string str, int k)
	{
		int N = str.size(), start = 0;
		for (int j = 1; j < N; j += 2)
			str[j] = (str[j] - '0' + k) % 10 + '0';
		return str;
	}

	void rotate(string &str, int k)
	{
		int N = str.size(), start = 0;
		for (int i = 0, index = 0; i < N; ++i)
		{
			index = (index + k) % N;
			if (start == index)
				index = ++start;
			else
				swap(str[start], str[index]);
		}
	}
};
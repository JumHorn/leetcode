#include <string>
#include <stack>
#include <cctype>
using namespace std;

class Solution
{
public:
	bool isValid(string code)
	{
		if (code.empty() || code[0] != '<')
			return false;
		int index = 0, N = code.length();
		stack<string> tag;
		while (index < N)
		{
			if (code[index] == '<')
			{
				++index;
				if (index < N && code[index] == '!')
				{
					if (tag.empty())
						return false;
					++index;
					if (code.substr(index, 7) != "[CDATA[")
						return false;
					index += 7;
					while (true)
					{
						while (index < N && code[index] != ']')
							index++;
						if (index < N)
						{
							if (code.substr(index, 3) == "]]>")
								break;
						}
						else
							break;
						++index;
					}
				}
				else if (index < N && code[index] == '/')
				{
					if (tag.empty())
						return false;
					++index;
					int i = index, len;
					while (i < N && code[i] != '>')
					{
						len = i - index + 1;
						if (len > (int)tag.top().length() || code[i] != tag.top()[len - 1])
							return false;
						i++;
					}
					len = i - index;
					if (len != (int)tag.top().length())
						return false;
					tag.pop();
					index = ++i;
					if (tag.empty() && index != N)
						return false;
				}
				else
				{
					int i = index, len;
					while (i < N && code[i] != '>')
					{
						len = i - index + 1;
						if (code[i] > 'Z' || code[i] < 'A')
							return false;
						i++;
						if (len > 9)
							return false;
					}
					len = i - index;
					if (i == N || len < 1 || len > 9)
						return false;
					tag.push(code.substr(index, len));
					index = ++i;
				}
			}
			else
				++index;
		}
		return tag.empty();
	}
};
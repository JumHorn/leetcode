#include <cctype>
#include <stack>
#include <string>
using namespace std;

class Solution
{
public:
	bool isValid(string code)
	{
		if (code.empty() || code[0] != '<')
			return false;
		int N = code.length();
		stack<string> tag;
		bool valid = false;
		for (int index = 0; index + 1 < N;)
		{
			if (code[index++] != '<')
				continue;
			valid = false;
			if (code[index] == '!') //comment tag
			{
				if (tag.empty()) //[CDATA[ must be wrapped in a tag
					return false;
				if (code.compare(index + 1, 7, "[CDATA[") != 0)
					return false;
				//jump to comment
				for (index += 8; index < N; ++index)
				{
					if (code[index] == ']' && code.compare(index, 3, "]]>") == 0)
						break;
				}
				index += 3;
			}
			else if (code[index] == '/') //finish tag
			{
				if (tag.empty()) //finish tag must be matched
					return false;
				int pos = code.find(">", ++index);
				if (pos == string::npos || code.compare(index, pos - index, tag.top()) != 0)
					return false;
				tag.pop();
				index = pos + 1;
				if (index < N && tag.empty()) //all string should be wrapped in one tag
					return false;
			}
			else //start tag
			{
				int tagSize = 0;
				for (int i = index; i < N && code[i] != '>'; ++i, ++tagSize)
				{
					if (code[i] > 'Z' || code[i] < 'A') //tag only consist of uppercase letters
						return false;
				}
				if (index + tagSize == N || tagSize < 1 || tagSize > 9)
					return false;
				tag.push(code.substr(index, tagSize));
				index += tagSize + 1;
			}
			valid = true;
		}
		return valid && tag.empty();
	}
};
#include <string>
using namespace std;

class Solution
{
public:
	string interpret(string command)
	{
		string res;
		int N = command.length();
		for (int i = 0; i < N;)
		{
			if (command[i] == 'G')
			{
				i += 1;
				res.push_back('G');
			}
			else if (command[i + 1] == ')')
			{
				i += 2;
				res.push_back('o');
			}
			else
			{
				i += 4;
				res += "al";
			}
		}
		return res;
	}
};
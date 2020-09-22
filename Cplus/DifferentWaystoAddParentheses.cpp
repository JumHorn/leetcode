#include <string>
#include <vector>
using namespace std;

class Solution
{
public:
	vector<int> diffWaysToCompute(string input)
	{
		vector<int> res;
		for (int i = 0; i < (int)input.size(); ++i)
		{
			if (input[i] == '+' || input[i] == '-' || input[i] == '*')
			{
				auto left = diffWaysToCompute(input.substr(0, i));
				auto right = diffWaysToCompute(input.substr(i + 1));
				for (auto n : left)
				{
					for (auto m : right)
					{
						if (input[i] == '+')
							res.push_back(n + m);
						else if (input[i] == '-')
							res.push_back(n - m);
						else
							res.push_back(n * m);
					}
				}
			}
		}
		if (res.empty())
			res.push_back(stoi(input));
		return res;
	}
};
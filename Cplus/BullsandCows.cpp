#include <string>
#include <vector>
using namespace std;

class Solution
{
public:
	string getHint(string secret, string guess)
	{
		vector<int> hash(10);
		int bulls = 0, cows = 0;
		for (int i = 0; i < (int)secret.length(); ++i)
		{
			if (secret[i] == guess[i])
				++bulls;
			else
			{
				if (hash[secret[i] - '0']++ < 0)
					++cows;
				if (hash[guess[i] - '0']-- > 0)
					++cows;
			}
		}
		return to_string(bulls) + "A" + to_string(cows) + "B";
	}
};
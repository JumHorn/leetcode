#include <iomanip>
#include <sstream>
#include <string>
using namespace std;

class Solution
{
public:
	string discountPrices(string sentence, int discount)
	{
		stringstream ss(sentence);
		string word, res;
		while (ss >> word)
		{
			if (!check(word))
				res += word + " ";
			else
			{
				long long price = stoll(word.substr(1));
				double d = (100 - discount) / 100.0 * price;

				stringstream val;
				val << std::fixed << std::setprecision(2) << d;
				res += "$" + val.str() + " ";
			}
		}

		if (!res.empty()) //pop ' '
			res.pop_back();
		return res;
	}

	bool check(string &price)
	{
		int N = price.size();
		if (price.empty() || price[0] != '$' || price.size() <= 1)
			return false;
		for (int i = 1; i < N; ++i)
		{
			char c = price[i];
			if (c < '0' || c > '9')
				return false;
		}
		return true;
	}
};
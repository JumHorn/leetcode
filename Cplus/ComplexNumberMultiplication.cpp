#include <string>
using namespace std;

class Solution
{
public:
	string complexNumberMultiply(string a, string b)
	{
		int m1, n1, m2, n2;
		decompose(a, m1, n1);
		decompose(b, m2, n2);
		int m = m1 * m2 - n1 * n2;
		int n = m1 * n2 + m2 * n1;
		return to_string(m) + "+" + to_string(n) + "i";
	}

	void decompose(const string &c, int &m, int &n) const
	{
		size_t size;
		m = stoi(c, &size);
		string left = c.substr(size + 1);
		n = stoi(left, &size);
	}
};
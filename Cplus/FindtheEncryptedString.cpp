#include <string>
using namespace std;

class Solution
{
public:
	string getEncryptedString(string s, int k)
	{
		int N = s.size(), r = k % N;
		return s.substr(r) + s.substr(0, r);
	}
};
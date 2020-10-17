#include <string>
using namespace std;

class Solution
{
public:
	string strWithout3a3b(int A, int B)
	{
		string res;
		while (A > 0 || B > 0)
		{
			bool writeA = false;
			int size = res.length();
			if (size >= 2 && res[size - 1] == res[size - 2])
			{
				if (res[size - 1] == 'b')
					writeA = true;
			}
			else
			{
				if (A >= B)
					writeA = true;
			}

			if (writeA)
			{
				--A;
				res.push_back('a');
			}
			else
			{
				--B;
				res.push_back('b');
			}
		}
		return res;
	}
};
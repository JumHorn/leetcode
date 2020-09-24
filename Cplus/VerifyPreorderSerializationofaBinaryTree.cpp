#include <sstream>
#include <string>
using namespace std;

class Solution
{
public:
	bool isValidSerialization(string preorder)
	{
		stringstream ss(preorder);
		string token;
		int degree = 1;
		while (getline(ss, token, ','))
		{
			if (--degree < 0)
				return false;
			if (token != "#")
				degree += 2;
		}
		return degree == 0;
	}
};
#include <vector>
using namespace std;

// The rand7() API is already defined for you.
int rand7();
// @return a random integer in the range 1 to 7

//this table equals the chance of 1-10.when hit * call rand7() again
/*
   1  2  3  4  5  6  7
1  1  2  3  4  5  6  7
2  8  9  10 1  2  3  4
3  5  6  7  8  9  10 1
4  2  3  4  5  6  7  8
5  9  10 1  2  3  4  5
6  6  7  8  9  10 *  *
7  *  *  *  *  *  *  *
*/

class Solution
{

public:
	Solution() : quard(7, vector<int>(7))
	{
		for (int i = 0; i < 40; i++)
			quard[i / 7][i % 7] = i % 10 + 1;
	}

	int rand10()
	{
		int res;
		do
		{
			res = quard[rand7() - 1][rand7() - 1];
		} while (res == 0);
		return res;
	}

private:
	vector<vector<int>> quard;
};
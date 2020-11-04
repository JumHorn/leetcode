#include <vector>
using namespace std;

class Solution
{
public:
	bool validUtf8(vector<int> &data)
	{
		int i = 0, len = 0, N = data.size();
		for (int i = 0, len; i < N; i += len)
		{
			if ((data[i] & HEAD0) == 0)
				len = 1;
			else if ((data[i] & HEAD2) == HEAD1)
				len = 2;
			else if ((data[i] & HEAD3) == HEAD2)
				len = 3;
			else if ((data[i] & HEAD4) == HEAD3)
				len = 4;
			else
				return false;
			if (len + i > N)
				return false;
			for (int j = i + 1; j < len + i; ++j)
			{
				if ((data[j] & HEAD1) != HEAD0)
					return false;
			}
		}
		return true;
	}

private:
	static const int HEAD0 = 128; //(1<<7)
	static const int HEAD1 = 192; //(1<<7)|(1<<6)
	static const int HEAD2 = 224; //(1<<7)|(1<<6)|(1<<5)
	static const int HEAD3 = 240; //(1<<7)|(1<<6)|(1<<5)|(1<<4)
	static const int HEAD4 = 248; //(1<<7)|(1<<6)|(1<<5)|(1<<4)|(1<<3)
};
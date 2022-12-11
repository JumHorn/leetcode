#include <vector>
using namespace std;

class Allocator
{
public:
	Allocator(int n) : data(n)
	{
	}

	int allocate(int size, int mID)
	{
		int N = data.size();
		for (int i = 0; i < N;)
		{
			if (data[i] == 0)
			{
				int j = i + 1;
				while (j < N && data[j] == 0)
					++j;
				if (j - i >= size)
				{
					for (int k = 0; k < size; ++k)
						data[k + i] = mID;
					return i;
				}
				i = j;
			}
			else
				++i;
		}
		return -1;
	}

	int free(int mID)
	{
		int N = data.size(), res = 0;
		for (int i = 0; i < N; ++i)
		{
			if (data[i] == mID)
			{
				++res;
				data[i] = 0;
			}
		}
		return res;
	}

private:
	vector<int> data;
};

/**
 * Your Allocator object will be instantiated and called as such:
 * Allocator* obj = new Allocator(n);
 * int param_1 = obj->allocate(size,mID);
 * int param_2 = obj->free(mID);
 */
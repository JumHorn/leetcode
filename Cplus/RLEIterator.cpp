#include <vector>
using namespace std;

class RLEIterator
{
public:
	RLEIterator(vector<int> &A)
	{
		lo = iter = 0;
		for (int i = 1; i < (int)A.size(); i += 2)
		{
			if (A[i - 1] != 0)
			{
				prefix.push_back(A[i - 1]);
				value.push_back(A[i]);
			}
		}
		for (int i = 1; i < (int)prefix.size(); ++i)
			prefix[i] += prefix[i - 1];
	}

	int next(int n)
	{
		iter += n;
		if (iter > prefix.back())
			return -1;
		long hi = prefix.size() - 1, mi;
		while (lo < hi)
		{
			mi = (hi - lo) / 2 + lo;
			if (iter > prefix[mi])
				lo = mi + 1;
			else
				hi = mi;
		}
		return value[lo];
	}

private:
	vector<long> prefix;
	vector<int> value;
	long iter;
	int lo;
};

/**
 * Your RLEIterator object will be instantiated and called as such:
 * RLEIterator* obj = new RLEIterator(A);
 * int param_1 = obj->next(n);
 */
#include <vector>
using namespace std;

class RLEIterator
{
public:
	RLEIterator(vector<int> &A) : seq(A)
	{
		size = A.size();
		curIndex = 1;
		curCount = A.empty() ? 0 : A[0];
	}

	int next(int n)
	{
		while (curIndex < size)
		{
			if (curCount >= n)
			{
				curCount -= n;
				return seq[curIndex];
			}
			n -= curCount;
			curIndex += 2;
			curCount = curIndex < size ? seq[curIndex - 1] : 0;
		}
		return -1;
	}

private:
	int curIndex;
	int curCount;
	int size;
	vector<int> &seq;
};

/**
 * Your RLEIterator object will be instantiated and called as such:
 * RLEIterator* obj = new RLEIterator(A);
 * int param_1 = next(n);
 */
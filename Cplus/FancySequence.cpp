#include <vector>
using namespace std;

/*
fermat's little theorem
a^(m-1) ≡ 1 (mod m) when m is prime
*/

class Fancy
{
public:
	Fancy()
	{
		mul = 1;
		add = 0;
	}

	void append(int val)
	{
		val = ((val - add) % MOD + MOD) % MOD;
		val = (val * power(mul, MOD - 2)) % MOD;
		data.push_back(val);
	}

	void addAll(int inc)
	{
		add = (add + inc) % MOD;
	}

	void multAll(int m)
	{
		mul = (mul * m) % MOD;
		add = (add * m) % MOD;
	}

	int getIndex(int idx)
	{
		int N = data.size();
		if (idx >= N)
			return -1;
		return (data[idx] * mul + add) % MOD;
	}

	long power(long x, int y)
	{
		long res = 1;
		for (; y; y >>= 1)
		{
			if (y & 1)
				res = (res * x) % MOD;
			x = (x * x) % MOD;
		}
		return res;
	}

private:
	vector<long> data;
	long mul, add;
	static const int MOD = 1e9 + 7;
};

/**
 * Your Fancy object will be instantiated and called as such:
 * Fancy* obj = new Fancy();
 * obj->append(val);
 * obj->addAll(inc);
 * obj->multAll(m);
 * int param_4 = obj->getIndex(idx);
 */
#include <vector>
using namespace std;

class Fancy
{
public:
	Fancy()
	{
		a = 1;
		b = 0;
	}

	void append(int val)
	{
		data.push_back({val, a, b});
		a = 1;
		b = 0;
	}

	void addAll(int inc)
	{
		// for(auto& n : data)
		//     n=(n+inc)%MOD;
		b = (b + inc) % MOD;
	}

	void multAll(int m)
	{
		// for(auto& n : data)
		//     n=(n*m)%MOD;
		a = (a * m) % MOD;
		b = (b * m) % MOD;
	}

	int getIndex(int idx)
	{
		int N = data.size();
		if (idx >= N)
			return -1;
		long res = data[idx][0];
		for (int i = idx + 1; i < N; ++i)
			res = (res * data[i][1] % MOD + data[i][2]) % MOD;
		res = (res * a % MOD + b) % MOD;
		return res;
	}

private:
	vector<vector<long>> data; //{value,a,b}
	long a, b;
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
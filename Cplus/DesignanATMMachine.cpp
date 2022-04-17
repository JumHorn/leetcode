#include <vector>
using namespace std;

class ATM
{
public:
	ATM()
	{
		denominations.resize(TYPE);
		d = {20, 50, 100, 200, 500};
	}

	void deposit(vector<int> banknotesCount)
	{
		int N = banknotesCount.size();
		for (int i = 0; i < N; ++i)
			denominations[i] += banknotesCount[i];
	}

	vector<int> withdraw(int amount)
	{
		vector<int> res(TYPE);
		for (int i = TYPE - 1; i >= 0 && amount > 0; --i)
		{
			long long n = amount / d[i];
			n = min(n, denominations[i]);
			amount -= n * d[i];
			res[i] += n;
		}
		if (amount > 0)
			return {-1};
		for (int i = 0; i < TYPE; ++i)
			denominations[i] -= res[i];
		return res;
	}

private:
	vector<long long> denominations; //20, 50, 100, 200, 500
	vector<int> d;
	static const int TYPE = 5;
};

/**
 * Your ATM object will be instantiated and called as such:
 * ATM* obj = new ATM();
 * obj->deposit(banknotesCount);
 * vector<int> param_2 = obj->withdraw(amount);
 */
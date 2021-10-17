#include <vector>
using namespace std;

class Bank
{
public:
	Bank(vector<long long> &balance) : v(balance)
	{
		N = balance.size();
	}

	bool transfer(int account1, int account2, long long money)
	{
		if (account1 <= N && account2 <= N)
		{
			if (v[account1 - 1] < money)
				return false;
			v[account1 - 1] -= money;
			v[account2 - 1] += money;
			return true;
		}
		return false;
	}

	bool deposit(int account, long long money)
	{
		if (account <= N)
		{
			v[account - 1] += money;
			return true;
		}
		return false;
	}

	bool withdraw(int account, long long money)
	{
		if (account <= N && v[account - 1] >= money)
		{
			v[account - 1] -= money;
			return true;
		}
		return false;
	}

private:
	vector<long long> v;
	int N;
};

/**
 * Your Bank object will be instantiated and called as such:
 * Bank* obj = new Bank(balance);
 * bool param_1 = obj->transfer(account1,account2,money);
 * bool param_2 = obj->deposit(account,money);
 * bool param_3 = obj->withdraw(account,money);
 */
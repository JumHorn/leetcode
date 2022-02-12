#include <string>
using namespace std;

class Bitset
{
public:
	Bitset(int size) : data(size, '0')
	{
		ones = 0;
		N = size;
		flag = false;
	}

	void fix(int idx)
	{
		if (flag)
		{
			if (data[idx] == '1')
				++ones;
			data[idx] = '0';
		}
		else
		{
			if (data[idx] == '0')
				++ones;
			data[idx] = '1';
		}
	}

	void unfix(int idx)
	{
		if (flag)
		{
			if (data[idx] == '0')
				--ones;
			data[idx] = '1';
		}
		else
		{
			if (data[idx] == '1')
				--ones;
			data[idx] = '0';
		}
	}

	void flip()
	{
		flag = !flag;
		ones = N - ones;
	}

	bool all()
	{
		return ones == N;
	}

	bool one()
	{
		return ones != 0;
	}

	int count()
	{
		return ones;
	}

	string toString()
	{
		if (flag)
		{
			for (auto &c : data)
				c = '0' + '1' - c;
		}
		flag = false;
		return data;
	}

private:
	string data;
	int ones, N;
	bool flag;
};

/**
 * Your Bitset object will be instantiated and called as such:
 * Bitset* obj = new Bitset(size);
 * obj->fix(idx);
 * obj->unfix(idx);
 * obj->flip();
 * bool param_4 = obj->all();
 * bool param_5 = obj->one();
 * int param_6 = obj->count();
 * string param_7 = obj->toString();
 */
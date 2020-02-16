#include <vector>
using namespace std;

class ProductOfNumbers
{
public:
	ProductOfNumbers()
	{
	}

	void add(int num)
	{
		if (num == 0)
		{
			prefix.clear();
			return;
		}
		if (prefix.empty())
			prefix.push_back(num);
		else
			prefix.push_back(prefix.back() * num);
	}

	int getProduct(int k)
	{
		if (k > (int)prefix.size())
			return 0;
		if (k == (int)prefix.size())
			return prefix.back();
		return prefix.back() / prefix[prefix.size() - k - 1];
	}

private:
	vector<int> prefix;
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */

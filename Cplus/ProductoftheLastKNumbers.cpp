#include <vector>
using namespace std;

class ProductOfNumbers
{
public:
	ProductOfNumbers()
	{
		prefix.push_back(1);
	}

	void add(int num)
	{
		if (num == 0)
			prefix = {1};
		else
			prefix.push_back(prefix.back() * num);
	}

	int getProduct(int k)
	{
		int N = prefix.size();
		return k >= N ? 0 : prefix[N - 1] / prefix[N - k - 1];
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
#include <unordered_map>
#include <vector>
using namespace std;

class Cashier
{
public:
	Cashier(int n, int discount, vector<int>& products, vector<int>& prices)
	{
		m_count = 0;
		m_n = n;
		m_discount = discount;
		for (int i = 0; i < (int)products.size(); i++)
			productprices[products[i]] = prices[i];
	}

	double getBill(vector<int> product, vector<int> amount)
	{
		double res = 0.0;
		for (int i = 0; i < (int)product.size(); i++)
			res += productprices[product[i]] * amount[i];
		if (++m_count == m_n)
		{
			m_count = 0;
			res = res - (res * m_discount) / 100;
		}
		return res;
	}

private:
	int m_count;
	int m_n;
	int m_discount;
	unordered_map<int, int> productprices;
};

/**
 * Your Cashier object will be instantiated and called as such:
 * Cashier* obj = new Cashier(n, discount, products, prices);
 * double param_1 = obj->getBill(product,amount);
 */

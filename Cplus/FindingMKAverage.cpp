#include <queue>
#include <set>
using namespace std;

class MKAverage
{
public:
	MKAverage(int m, int k)
	{
		m_m = m;
		m_k = k;
		sum = 0;
		sum_smaller = 0;
		sum_bigger = 0;
	}

	void addElement(int num)
	{
		q.push(num);
		sum += num;
		// add
		if (smaller.size() < m_k)
		{
			smaller.insert(num);
			sum_smaller += num;
		}
		else if (bigger.size() < m_k)
		{
			bigger.insert(num);
			sum_bigger += num;
		}
		else
			middle.insert(num);

		// erase
		if (q.size() > m_m)
		{
			int val = q.front();
			q.pop();
			sum -= val;
			auto iter = middle.find(val);
			if (iter != middle.end())
				middle.erase(iter);
			else
			{
				iter = smaller.find(val);
				if (iter != smaller.end())
				{
					smaller.erase(iter);
					int n = *middle.begin();
					smaller.insert(n);
					sum_smaller += n - val;
					middle.erase(middle.begin());
				}
				else
				{
					bigger.erase(bigger.find(val));
					int n = *middle.rbegin();
					bigger.insert(n);
					sum_bigger += n - val;
					middle.erase(middle.find(n));
				}
			}
		}

		if (middle.empty())
		{
			if (!bigger.empty())
			{
				int diff = swapValue(smaller, bigger);
				sum_smaller -= diff;
				sum_bigger += diff;
			}
		}
		else
		{
			int diff = swapValue(smaller, middle);
			sum_smaller -= diff;
			diff = swapValue(middle, bigger);
			sum_bigger += diff;
		}
	}

	int swapValue(multiset<int> &lhs, multiset<int> &rhs)
	{
		int l = *lhs.rbegin(), r = *rhs.begin();
		if (l <= r)
			return 0;
		lhs.erase(lhs.find(l));
		rhs.erase(rhs.find(r));
		lhs.insert(r);
		rhs.insert(l);
		return l - r;
	}

	int calculateMKAverage()
	{
		if (q.size() < m_m)
			return -1;
		return (sum - sum_smaller - sum_bigger) / (m_m - 2 * m_k);
	}

private:
	queue<int> q;
	int m_m;
	int m_k;
	multiset<int> smaller, bigger, middle;
	long sum, sum_smaller, sum_bigger;
};

/**
 * Your MKAverage object will be instantiated and called as such:
 * MKAverage* obj = new MKAverage(m, k);
 * obj->addElement(num);
 * int param_2 = obj->calculateMKAverage();
 */
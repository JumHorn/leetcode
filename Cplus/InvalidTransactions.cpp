#include <algorithm>
#include <sstream>
#include <string>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution
{
private:
	struct trans
	{
		string name;
		int time;
		int amount;
		string city;
		int index;
	};

public:
	vector<string> invalidTransactions(vector<string> &transactions)
	{
		vector<trans> v;
		unordered_set<int> seen; //{index}
		int N = transactions.size();
		for (int i = 0; i < N; ++i)
		{
			trans s = split(transactions[i]);
			s.index = i;
			if (s.amount >= 1000)
				seen.insert(i);
			v.push_back(s);
		}
		sort(v.begin(), v.end(), *this);
		for (int i = 0; i < N - 1; ++i)
		{
			for (int j = i + 1; j < N; ++j)
			{
				if (v[j].name != v[i].name)
					break;
				if (v[j].time - v[i].time > 60)
					break;
				if (v[j].city != v[i].city)
				{
					seen.insert(v[i].index);
					seen.insert(v[j].index);
				}
			}
		}
		vector<string> res;
		for (auto n : seen)
			res.push_back(transactions[n]);
		return res;
	}

	trans split(const string &tran)
	{
		stringstream ss(tran);
		trans res;
		char comma;
		getline(ss, res.name, ',');
		ss >> res.time;
		ss >> comma;
		ss >> res.amount;
		ss >> comma;
		ss >> res.city;
		return res;
	}

	bool operator()(const trans &lhs, const trans &rhs)
	{
		if (lhs.name != rhs.name)
			return lhs.name < rhs.name;
		if (lhs.time != rhs.time)
			return lhs.time < rhs.time;
		if (lhs.amount != rhs.amount)
			return lhs.amount < rhs.amount;
		return lhs.city < rhs.city;
	}
};
#include <algorithm>
#include <string>
#include <vector>
#include <unordered_set>
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
		unordered_set<int> seen;
		for (int i = 0; i < (int)transactions.size(); i++)
		{
			trans s = split(transactions[i]);
			s.index = i;
			if (s.amount >= 1000)
				seen.insert(i);
			v.push_back(s);
		}
		sort(v.begin(), v.end(), *this);
		for (int i = 0; i < (int)v.size() - 1; i++)
		{
			for (int j = i + 1; j < (int)v.size(); j++)
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
		vector<string> res(seen.size());
		int i = 0;
		for (auto n : seen)
			res[i++] = transactions[n];
		return res;
	}

	trans split(const string &tran)
	{
		trans res;
		int i = 0, j = 0;
		while (tran[j] != ',')
			j++;
		res.name = tran.substr(i, j - i);
		i = ++j;
		while (tran[j] != ',')
			j++;
		res.time = stoi(tran.substr(i, j - i));
		i = ++j;
		while (tran[j] != ',')
			j++;
		res.amount = stoi(tran.substr(i, j - i));
		res.city = tran.substr(j + 1);
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
		if (lhs.city != rhs.city)
			return lhs.city < rhs.city;
		return false;
	}
};

int main()
{
	vector<string> v = {
		"bob,627,1973,amsterdam", "alex,387,885,bangkok", "alex,355,1029,barcelona", "alex,587,402,bangkok", "chalicefy,973,830,barcelona", "alex,932,86,bangkok", "bob,188,989,amsterdam"};
	Solution sol;
	sol.invalidTransactions(v);
	return 0;
}
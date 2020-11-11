#include <cstdlib> //for rand
#include <unordered_map>
#include <vector>
using namespace std;

class RandomizedCollection
{
public:
	/** Initialize your data structure here. */
	RandomizedCollection()
	{
	}

	/** Inserts a value to the collection. Returns true if the collection did not already contain the specified element. */
	bool insert(int val)
	{
		bool res = m.find(val) != m.end();
		m[val].push_back(randaccess.size());
		randaccess.push_back({val, (int)m[val].size() - 1});
		return res;
	}

	/** Removes a value from the collection. Returns true if the collection contained the specified element. */
	bool remove(int val)
	{
		if (m.find(val) == m.end())
			return false;
		auto last = randaccess.back();
		m[last.first][last.second] = m[val].back();
		randaccess[m[val].back()] = last;
		m[val].pop_back();
		if (m[val].empty())
			m.erase(val);
		randaccess.pop_back();
		return true;
	}

	/** Get a random element from the collection. */
	int getRandom()
	{
		return randaccess[rand() % randaccess.size()].first;
	}

private:
	vector<pair<int, int>> randaccess; //{value,index in m}
	unordered_map<int, vector<int>> m; //{value,index in randaccess}
};

/**
 * Your RandomizedCollection object will be instantiated and called as such:
 * RandomizedCollection* obj = new RandomizedCollection();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */
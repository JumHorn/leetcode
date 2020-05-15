#include <vector>
#include <cstdlib>
#include <unordered_map>
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
		bool res = true;
		if (modify.find(val) != modify.end())
			res = false;
		randaccess.push_back(val);
		modify.insert({val, randaccess.size() - 1});
		return res;
	}

	/** Removes a value from the collection. Returns true if the collection contained the specified element. */
	bool remove(int val)
	{
		unordered_multimap<int, int>::iterator iter = modify.find(val);
		if (iter == modify.end())
			return false;
		unordered_multimap<int, int>::iterator iter1 = modify.find(randaccess.back());
		int n = modify.count(randaccess.back());
		for (int i = 0; i < n; ++i, ++iter1)
		{
			if (iter1->second == randaccess.size() - 1)
				break;
		}
		iter1->second = iter->second;
		randaccess[iter->second] = randaccess.back();
		randaccess.pop_back();
		modify.erase(iter);
		return true;
	}

	/** Get a random element from the collection. */
	int getRandom()
	{
		return randaccess[rand() % randaccess.size()];
	}

private:
	vector<int> randaccess;
	unordered_multimap<int, int> modify;
};

/**
 * Your RandomizedCollection object will be instantiated and called as such:
 * RandomizedCollection* obj = new RandomizedCollection();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */
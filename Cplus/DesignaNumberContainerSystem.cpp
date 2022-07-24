#include <set>
#include <unordered_map>
using namespace std;

class NumberContainers
{
public:
	NumberContainers()
	{
	}

	void change(int index, int number)
	{
		auto it = indextonum.find(index);
		if (it != indextonum.end())
		{
			numtoindex[it->second].erase(index);
			it->second = number;
		}
		else
			indextonum[index] = number;
		numtoindex[number].insert(index);
	}

	int find(int number)
	{
		auto it = numtoindex.find(number);
		if (it == numtoindex.end())
			return -1;
		if (it->second.empty())
			return -1;
		return *it->second.begin();
	}

private:
	unordered_map<int, int> indextonum; //{index,num}
	unordered_map<int, set<int>> numtoindex;
};

/**
 * Your NumberContainers object will be instantiated and called as such:
 * NumberContainers* obj = new NumberContainers();
 * obj->change(index,number);
 * int param_2 = obj->find(number);
 */
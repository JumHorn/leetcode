#include <set>
using namespace std;

class SmallestInfiniteSet
{
public:
	SmallestInfiniteSet()
	{
		smallest = 1;
	}

	int popSmallest()
	{
		if (s.empty())
			return smallest++;
		int res = *s.begin();
		s.erase(res);
		return res;
	}

	void addBack(int num)
	{
		if (num >= smallest)
			return;
		s.insert(num);
	}

private:
	set<int> s;
	int smallest;
};

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */
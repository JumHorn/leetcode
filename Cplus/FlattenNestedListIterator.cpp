#include <stack>
#include <vector>
using namespace std;

// This is the interface that allows for creating nested lists.
// You should not implement it, or speculate about its implementation
class NestedInteger
{
public:
	// Return true if this NestedInteger holds a single integer, rather than a nested list.
	bool isInteger() const;
	// Return the single integer that this NestedInteger holds, if it holds a single integer
	// The result is undefined if this NestedInteger holds a nested list
	int getInteger() const;
	// Return the nested list that this NestedInteger holds, if it holds a nested list
	// The result is undefined if this NestedInteger holds a single integer
	vector<NestedInteger> &getList() const;
};

class NestedIterator
{
public:
	NestedIterator(vector<NestedInteger> &nestedList)
	{
		s.push({nestedList.begin(), nestedList.end()});
	}

	int next()
	{
		hasNext();
		int res = s.top().first->getInteger();
		++s.top().first;
		return res;
	}

	bool hasNext()
	{
		while (!s.empty())
		{
			if (s.top().first == s.top().second)
				s.pop();
			else
			{
				auto iter = s.top().first;
				if (iter->isInteger())
					return true;
				++s.top().first;
				s.push({iter->getList().begin(), iter->getList().end()});
			}
		}
		return false;
	}

private:
	stack<pair<vector<NestedInteger>::iterator, vector<NestedInteger>::iterator>> s;
};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */
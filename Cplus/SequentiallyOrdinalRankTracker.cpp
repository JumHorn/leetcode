#include <algorithm>
#include <queue>
#include <string>
#include <vector>
using namespace std;

class CBig
{
public:
	bool operator()(pair<string, int> &lhs, pair<string, int> &rhs)
	{
		if (lhs.second != rhs.second)
			return lhs.second > rhs.second;
		return lhs.first < rhs.first;
	}
};

class CSmall
{
public:
	bool operator()(pair<string, int> &lhs, pair<string, int> &rhs)
	{
		if (lhs.second != rhs.second)
			return lhs.second < rhs.second;
		return lhs.first > rhs.first;
	}
};

class SORTracker
{
public:
	SORTracker()
	{
	}

	void add(string name, int score)
	{
		q1.push({name, score});
		q2.push(q1.top());
		q1.pop();
	}

	string get()
	{
		q1.push(q2.top());
		q2.pop();
		return q1.top().first;
	}

private:
	priority_queue<pair<string, int>, vector<pair<string, int>>, CBig> q1;
	priority_queue<pair<string, int>, vector<pair<string, int>>, CSmall> q2;
};
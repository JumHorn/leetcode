#include <map>
#include <string>
#include <vector>
using namespace std;

class OrderedStream
{
public:
	OrderedStream(int n)
	{
		ptr = 1;
	}

	vector<string> insert(int id, string value)
	{
		m[id] = value;
		vector<string> res;
		for (; m.find(ptr) != m.end(); ++ptr)
			res.push_back(m[ptr]);
		return res;
	}

private:
	map<int, string> m;
	int ptr;
};

/**
 * Your OrderedStream object will be instantiated and called as such:
 * OrderedStream* obj = new OrderedStream(n);
 * vector<string> param_1 = obj->insert(id,value);
 */
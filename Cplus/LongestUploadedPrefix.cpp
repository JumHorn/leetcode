#include <vector>
using namespace std;

class LUPrefix
{
public:
	LUPrefix(int n) : mask(n), ready(0)
	{
	}

	void upload(int video)
	{
		mask[video - 1] = 1;
	}

	int longest()
	{
		while (ready < mask.size() && mask[ready] == 1)
			++ready;
		return ready;
	}

private:
	vector<int> mask;
	int ready;
};

/**
 * Your LUPrefix object will be instantiated and called as such:
 * LUPrefix* obj = new LUPrefix(n);
 * obj->upload(video);
 * int param_2 = obj->longest();
 */
#include <unordered_map>
#include <vector>
using namespace std;

class FrequencyTracker
{
public:
	FrequencyTracker() : freq(SIZE)
	{
	}

	void add(int number)
	{
		--freq[m[number]];
		++m[number];
		++freq[m[number]];
	}

	void deleteOne(int number)
	{
		auto it = m.find(number);
		if (it == m.end())
			return;
		--freq[it->second];
		if (--it->second == 0)
			m.erase(it);
		else
			++freq[it->second];
	}

	bool hasFrequency(int frequency)
	{
		return freq[frequency] > 0;
	}

private:
	vector<int> freq;
	unordered_map<int, int> m; //{val,freq}
	static const int SIZE = 1e5 + 1;
};

/**
 * Your FrequencyTracker object will be instantiated and called as such:
 * FrequencyTracker* obj = new FrequencyTracker();
 * obj->add(number);
 * obj->deleteOne(number);
 * bool param_3 = obj->hasFrequency(frequency);
 */
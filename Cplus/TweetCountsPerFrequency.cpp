#include <algorithm>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

class TweetCounts
{
public:
	TweetCounts()
	{
		m_delta["minute"] = 60;
		m_delta["hour"] = 60 * 60;
		m_delta["day"] = 24 * 60 * 60;
	}

	void recordTweet(string tweetName, int time)
	{
		m[tweetName].push_back(time);
	}

	vector<int> getTweetCountsPerFrequency(string freq, string tweetName, int startTime, int endTime)
	{
		int delta = m_delta[freq];
		vector<int> res((endTime - startTime) / delta + 1);
		for (auto &time : m[tweetName])
		{
			if (time >= startTime && time <= endTime)
			{
				int index = (time - startTime) / delta;
				++res[index];
			}
		}
		return res;
	}

private:
	unordered_map<string, vector<int>> m;
	unordered_map<string, int> m_delta;
};

/**
 * Your TweetCounts object will be instantiated and called as such:
 * TweetCounts* obj = new TweetCounts();
 * obj->recordTweet(tweetName,time);
 * vector<int> param_2 = obj->getTweetCountsPerFrequency(freq,tweetName,startTime,endTime);
 */
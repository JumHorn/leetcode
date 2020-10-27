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
		vector<int> res, &time = m[tweetName];
		sort(time.begin(), time.end());
		int delta = m_delta[freq], count = 0, start = startTime, end = min(startTime + delta, endTime + 1), n = 1;
		for (int i = 0; i <= (int)time.size() && start <= endTime; ++i)
		{
			if (i == (int)time.size())
			{
				res.push_back(count);
				break;
			}
			if (time[i] < start)
				continue;
			if (time[i] < end)
				++count;
			else
			{
				--i;
				res.push_back(count);
				count = 0;
				start = startTime + delta * n++;
				end = min(start + delta, endTime + 1);
			}
		}
		while (start + delta <= endTime)
		{
			res.push_back(0);
			start += delta;
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
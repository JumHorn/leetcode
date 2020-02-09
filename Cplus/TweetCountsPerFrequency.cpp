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
		sort(m[tweetName].begin(), m[tweetName].end());
		vector<int> res;
		int delta = m_delta[freq], count = 0, start = startTime, end = min(startTime + delta, endTime + 1), n = 1;
		//cout<<start<<" "<<end<<endl;
		for (int i = 0; i < (int)m[tweetName].size(); i++)
		{
			if (m[tweetName][i] < start)
				continue;
			if (m[tweetName][i] < end)
			{
				count++;
				if (i != (int)m[tweetName].size() - 1)
					continue;
			}
			if (count > 0)
				res.push_back(count);
			if (i == (int)m[tweetName].size() - 1)
			{
				if (m[tweetName][i] >= end)
					i--;
			}
			else
				i--;
			start = startTime + delta * n;
			if (start > endTime)
				break;
			end = min(start + delta, endTime + 1);
			//cout<<start<<" "<<end<<endl;
			count = 0;
			n++;
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

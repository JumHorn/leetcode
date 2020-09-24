#include <list>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

typedef pair<list<int>::iterator, list<int>::iterator> TwiterContent;

class Twitter
{
public:
	/** Initialize your data structure here. */
	Twitter()
	{
	}

	/** Compose a new tweet. */
	void postTweet(int userId, int tweetId)
	{
		twitters.push_back(tweetId);
		newsfeed[userId].push_front(twitters.size() - 1);
	}

	/** Retrieve the 10 most recent tweet ids in the user's news feed. Each item in the news feed must be posted by users who the user followed or by the user herself. Tweets must be ordered from most recent to least recent. */
	vector<int> getNewsFeed(int userId)
	{
		auto f = [=](TwiterContent &lhs, TwiterContent &rhs) { return *lhs.first < *rhs.first; };
		priority_queue<TwiterContent, vector<TwiterContent>, decltype(f)> q(f);
		followermanager[userId].insert(userId);
		for (auto &user : followermanager[userId])
		{
			if (!newsfeed[user].empty())
				q.push({newsfeed[user].begin(), newsfeed[user].end()});
		}
		vector<int> res;
		while (res.size() < 10 && !q.empty())
		{
			auto content = q.top();
			q.pop();
			res.push_back(twitters[*content.first++]);
			if (content.first != content.second)
				q.push(content);
		}
		return res;
	}

	/** Follower follows a followee. If the operation is invalid, it should be a no-op. */
	void follow(int followerId, int followeeId)
	{
		if (followerId == followeeId)
			return;
		followermanager[followerId].insert(followeeId);
	}

	/** Follower unfollows a followee. If the operation is invalid, it should be a no-op. */
	void unfollow(int followerId, int followeeId)
	{
		if (followerId == followeeId)
			return;
		followermanager[followerId].erase(followeeId);
	}

private:
	vector<int> twitters;									//twitters ordered by post time
	unordered_map<int, list<int>> newsfeed;					//{userid,twiters index}
	unordered_map<int, unordered_set<int>> followermanager; //{userid,following userid}
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter* obj = new Twitter();
 * obj->postTweet(userId,tweetId);
 * vector<int> param_2 = obj->getNewsFeed(userId);
 * obj->follow(followerId,followeeId);
 * obj->unfollow(followerId,followeeId);
 */
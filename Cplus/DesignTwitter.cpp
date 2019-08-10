#include<unordered_map>
#include<list>
#include<vector>
#include<unordered_set>
using namespace std;

class Twitter {
private:
	vector<int> twitters;
	unordered_map<int,list<int>> newsfeed;
	unordered_map<int,unordered_set<int>> followermanager;
	unordered_map<int,unordered_set<int>> followeemanager;
	unordered_map<int,int> twittertouser;

    void updateNewsFeed(int userId)
    {
        newsfeed[userId].clear();
		for(int i=twitters.size()-1;i>=0;i--)
		{
			if(followeemanager[userId].find(twittertouser[twitters[i]])!=followeemanager[userId].end())
				newsfeed[userId].push_back(twitters[i]);
			if(newsfeed[userId].size()>=10)
				break;
		}
    }

public:
    /** Initialize your data structure here. */
    Twitter() {
        
    }
    
    /** Compose a new tweet. */
    void postTweet(int userId, int tweetId) {
		twitters.push_back(tweetId);
		twittertouser[tweetId]=userId;
        followermanager[userId].insert(userId);
        followeemanager[userId].insert(userId);
		for(unordered_set<int>::iterator iter=followermanager[userId].begin();iter!=followermanager[userId].end();++iter)
		{
			newsfeed[*iter].push_front(tweetId);
			if(newsfeed[*iter].size()>10)
				newsfeed[*iter].pop_back();
		}
    }
    
    /** Retrieve the 10 most recent tweet ids in the user's news feed. Each item in the news feed must be posted by users who the user followed or by the user herself. Tweets must be ordered from most recent to least recent. */
    vector<int> getNewsFeed(int userId) {
        return vector<int>(newsfeed[userId].begin(),newsfeed[userId].end());
    }
    
    /** Follower follows a followee. If the operation is invalid, it should be a no-op. */
    void follow(int followerId, int followeeId) {
        followermanager[followerId].insert(followerId);
        followeemanager[followerId].insert(followerId);
		if(followerId==followeeId)
			return;
		if(followermanager[followeeId].find(followerId)!=followermanager[followeeId].end())
			return;
        followermanager[followeeId].insert(followerId);
        followeemanager[followerId].insert(followeeId);
        updateNewsFeed(followerId);
    }
    
    /** Follower unfollows a followee. If the operation is invalid, it should be a no-op. */
    void unfollow(int followerId, int followeeId) {
        followermanager[followerId].insert(followerId);
        followeemanager[followerId].insert(followerId);
		if(followeeId==followerId)
			return;
		if(followermanager[followeeId].find(followerId)==followermanager[followeeId].end())
			return;
        followermanager[followeeId].erase(followerId);
        followeemanager[followerId].erase(followeeId);
        updateNewsFeed(followerId);
    }
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter* obj = new Twitter();
 * obj->postTweet(userId,tweetId);
 * vector<int> param_2 = obj->getNewsFeed(userId);
 * obj->follow(followerId,followeeId);
 * obj->unfollow(followerId,followeeId);
 */

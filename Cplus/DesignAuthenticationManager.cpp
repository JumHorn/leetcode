#include <string>
#include <unordered_map>
using namespace std;

class AuthenticationManager
{
public:
	AuthenticationManager(int timeToLive)
	{
		livetime = timeToLive;
	}

	void generate(string tokenId, int currentTime)
	{
		m[tokenId] = currentTime + livetime;
	}

	void renew(string tokenId, int currentTime)
	{
		if (m.find(tokenId) == m.end() || m[tokenId] <= currentTime)
			return;
		m[tokenId] = currentTime + livetime;
	}

	int countUnexpiredTokens(int currentTime)
	{
		int res = 0;
		for (auto [token, time] : m)
		{
			if (time > currentTime)
				++res;
		}
		return res;
	}

private:
	int livetime;
	unordered_map<string, int> m; //{token,expire time}
};

/**
 * Your AuthenticationManager object will be instantiated and called as such:
 * AuthenticationManager* obj = new AuthenticationManager(timeToLive);
 * obj->generate(tokenId,currentTime);
 * obj->renew(tokenId,currentTime);
 * int param_3 = obj->countUnexpiredTokens(currentTime);
 */
#include <string>
#include <vector>
using namespace std;

class Solution
{
public:
	// Encodes a URL to a shortened URL.
	string encode(string longUrl)
	{
		data.push_back(longUrl);
		return to_string(data.size() - 1);
	}

	// Decodes a shortened URL to its original URL.
	string decode(string shortUrl)
	{
		return data[stoi(shortUrl)];
	}

private:
	vector<string> data;
};

// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));
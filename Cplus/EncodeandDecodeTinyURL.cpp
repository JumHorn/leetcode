#include<string>
#include<vector>
using namespace std;

class Solution {
	vector<string> v;
public:

    // Encodes a URL to a shortened URL.
    string encode(string longUrl) {
        v.push_back(longUrl);
		return to_string(v.size()-1);
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
        return v[stoi(shortUrl)];
    }
};

// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));

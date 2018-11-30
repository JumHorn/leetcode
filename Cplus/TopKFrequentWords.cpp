#include<vector>
#include<string>
#include<map>
using namespace std;

class Solution {
public:
	map<string,int> freq;
    vector<string> topKFrequent(vector<string>& words, int k) {
		freq.clear();
		for(vector<string>::iterator iter=words.begin();iter!=words.end();iter++)
			freq[*iter]++;
		vector<string> tmp;
		for(map<string,int>::iterator iter=freq.begin();iter!=freq.end();iter++)
			tmp.push_back(iter->first);
		make_heap(tmp.begin(),tmp.end(),*this);
		vector<string> res;
		for(int i=0;i<k;i++)
		{
			pop_heap(tmp.begin(),tmp.end()-i,*this);
			res.push_back(*(tmp.end()-i-1));
		}
		return res;
    }

	bool operator()(const string& s1,const string& s2)
	{
		if(freq[s1]<freq[s2])
			return true;
		else if(freq[s1]>freq[s2])
			return false;
		if(s1>s2)
			return true;
		return false;
	}
};

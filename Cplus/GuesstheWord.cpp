#include<string>
#include<vector>
#include<set>
using namespace std;
/**
 * // This is the Master's API interface.
 * // You should not implement it, or speculate about its implementation
 */

class Master {
  public:
    int guess(string word);
};

class Solution {
public:
    void findSecretWord(vector<string>& wordlist, Master& master) {
        set<string> possible(wordlist.begin(),wordlist.end());
		int diff=master.guess(*possible.begin());
		while(diff<(int)wordlist.front().length())
		{
			wordlistReduce(possible,diff);
			diff=master.guess(*possible.begin());
		}
    }

	void wordlistReduce(set<string>& possible,int diff)
	{
		set<string>::iterator iter=possible.begin();
		string guessed=*iter;
		set<string> tmp;
		for(++iter;iter!=possible.end();++iter)
		{
			if(strdiff(guessed,*iter)==diff)
				tmp.insert(*iter);
		}
		possible=tmp;
	}

	int strdiff(const string& lhs,const string& rhs)
	{
		int res=0;
		for(int i=0;i<(int)lhs.length();i++)
			if(lhs[i]==rhs[i])
				res++;
		return res;
	}
};

#include<vector>
#include<string>
#include<unordered_map>
#include<unordered_set>
using namespace std;

class Solution {
public:
    vector<string> uncommonFromSentences(string A, string B) {
        unordered_map<string,int> s;
		for(int i=0;i<(int)A.size();i++)
		{
			int j=i;
			while(j<(int)A.size()&&A[j]==' ')
				j++;
			i=j;
			while(j<(int)A.size()&&A[j]!=' ')
				j++;
			++s[A.substr(i,j-i)];
			i=j;
		}
        unordered_map<string,int> t;
		for(int i=0;i<(int)B.size();i++)
		{
			int j=i;
			while(j<(int)B.size()&&B[j]==' ')
				j++;
			i=j;
			while(j<(int)B.size()&&B[j]!=' ')
				j++;
			++t[B.substr(i,j-i)];
			i=j;
		}
		unordered_set<string> res;
		for(unordered_map<string,int>::iterator iter=s.begin();iter!=s.end();++iter)
		{
			if(s[iter->first]+t[iter->first]==1)
				res.insert(iter->first);
		}
		for(unordered_map<string,int>::iterator iter=t.begin();iter!=t.end();++iter)
		{
			if(s[iter->first]+t[iter->first]==1)
				res.insert(iter->first);
		}
		return vector<string>(res.begin(),res.end());
    }
};

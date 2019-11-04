#include<string>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
	struct SuffixArray
	{
		int index;
		int currank;
		int nextrank;
	};
public:
    string longestDupSubstring(string S) {
		struct SuffixArray sa[S.length()];
		int n=S.length();
		//init
		for(int i=0;i<n-1;i++)
		{
			sa[i].index=i;
			sa[i].currank=S[i]-'a';
			sa[i].nextrank=S[i+1]-'a';
		}
		sa[n-1].index=n-1;
		sa[n-1].currank=S[n-1]-'a';
		sa[n-1].nextrank=-1;
		sort(sa,sa+n,*this);

		vector<int> index(n);
		for(int k=4;k<2*n;k*=2)
		{
			int rank=0;
			int pre_rank=sa[0].currank;
			sa[0].currank=rank;
			index[sa[0].index]=0;
			//update rank
			for(int i=1;i<n;i++)
			{
				if(sa[i].currank==pre_rank&&sa[i].nextrank==sa[i-1].nextrank)
					sa[i].currank=rank;
				else
				{
					pre_rank=sa[i].currank;
					sa[i].currank=++rank;
				}
				index[sa[i].index]=i;
			}
			for(int i=0;i<n;i++)
			{
				int nextindex=sa[i].index+k/2;
				sa[i].nextrank=(nextindex<n)?sa[index[nextindex]].currank:-1;
			}
			sort(sa,sa+n,*this);
		}
		//calc lcp array
		vector<int> inverseSuffix(n);
		vector<int> lcp(n);
		for(int i=0;i<n;i++)
		{
			inverseSuffix[sa[i].index]=i;
		}
		int k=0;
		for(int i=0;i<n;i++)
		{
			if(inverseSuffix[i]==n-1)
			{
				k=0;
				continue;
			}
			int j=sa[inverseSuffix[i]+1].index;
			while(i+k<n&&j+k<n&&S[i+k]==S[j+k])
				k++;
			lcp[inverseSuffix[i]]=k;
			if(k>0)
				k--;
		}
		//calc result
		int len=lcp[0];
		k=0;
		for(int i=1;i<n;i++)
			if(lcp[i]>len)
			{
				len=lcp[i];
				k=sa[i].index;
			}
		return S.substr(k,len);
    }

	bool operator()(const SuffixArray& lhs,const SuffixArray& rhs)
	{
		if(lhs.currank!=rhs.currank)
			return lhs.currank<rhs.currank;
		return lhs.nextrank<rhs.nextrank;
	}
};


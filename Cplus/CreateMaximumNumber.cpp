#include<vector>
#include<numeric>
#include<algorithm>
using namespace std;

class Solution {
public:
    vector<int> maxNumber(vector<int>& nums1, vector<int>& nums2, int k) {
		vector<int> res(k);
        int m_i=0,m_j=0,m_k=0;
        while(m_k<k)
		    twoVectorMaxNumber(nums1,m_i,nums1.size(),nums2,m_j,nums2.size(),res,m_k,k);
		return res;
    }

	void twoVectorMaxNumber(vector<int>& nums1,int& m_i,int M,vector<int>& nums2,int& m_j,int N,vector<int>& res,int& m_k,int K)
	{
		if(m_k==K)
			return;
		if(m_i>=M)
            return oneVectorMaxNumber(nums2,m_j,N,res,m_k,K);
		if(m_j>=N)
            return oneVectorMaxNumber(nums1,m_i,M,res,m_k,K);
        
        int tmp=(K-m_k-1)-(N-m_j);
        if(tmp>0)
            tmp=M-tmp;
        else
            tmp=M;
		vector<int>::iterator iter1=max_element(nums1.begin()+m_i,nums1.begin()+tmp);
        tmp=(K-m_k-1)-(M-m_i);
        if(tmp>0)
            tmp=N-tmp;
        else
            tmp=N;
		vector<int>::iterator iter2=max_element(nums2.begin()+m_j,nums2.begin()+tmp);

		if(*iter1>*iter2)
		{
			m_i=distance(nums1.begin(),iter1)+1;
			res[m_k++]=*iter1;
		}
		else if(*iter1<*iter2)
		{
            m_j=distance(nums2.begin(),iter2)+1;
			res[m_k++]=*iter2;
        }
        else
        {
            res[m_k++]=*iter1;
            vector<int> v1(iter1+1,nums1.end());
            vector<int> v2(nums2.begin()+m_j,nums2.end());
            vector<int> res1=maxNumber(v1,v2,K-m_k);
            vector<int> v3(nums1.begin()+m_i,nums1.end());
            vector<int> v4(iter2+1,nums2.end());
            vector<int> res2=maxNumber(v3,v4,K-m_k);
            if(res1>=res2)
                copy(res1.begin(),res1.end(),res.begin()+m_k);
            else
                copy(res2.begin(),res2.end(),res.begin()+m_k);
            m_k=K;
        }
        
	}

	void oneVectorMaxNumber(vector<int>& v,int i,int M,vector<int>& res,int& m_k,int K)
	{
		if(m_k>=K)
			return;
		vector<int>::iterator iter=max_element(v.begin()+i,v.begin()+M-(K-m_k)+1);
		int index=distance(v.begin(),iter)+1;
		res[m_k++]=*iter;
        oneVectorMaxNumber(v,index,M,res,m_k,K);
	}
};
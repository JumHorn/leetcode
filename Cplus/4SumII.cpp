#include<vector>
#include<map>
using namespace std;

class Solution {
public:
    int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
		int res=0;
		map<int,int> hashtable;
		for(int i=0;i<A.size();i++)
			for(int j=0;j<B.size();j++)
			{
				hashtable[A[i]+B[j]]++;
			}
		for(int k=0;k<C.size();k++)
			for(int l=0;l<D.size();l++)
			{
				res+=hashtable[-(C[k]+D[l])];
			}
		return res;
    }
};

//this one is better

//class Solution {
//public:
//    int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
//		int res=0;
//		vector<int> E;
//		vector<int> F;
//		for(int i=0;i<A.size();i++)
//			for(int j=0;j<B.size();j++)
//			{
//				E.push_back(A[i]+B[j]);
//			}
//		for(int k=0;k<C.size();k++)
//			for(int l=0;l<D.size();l++)
//			{
//				F.push_back(C[k]+D[l]);
//			}
//		for(int m=0;m<E.size();m++)
//			for(int n=0;n<F.size();n++)
//			{
//				if(E[m]+F[n]==0)
//					res++;
//			}
//		return res;
//    }
//};

//the easist way but time limit exceeded

//class Solution {
//public:
//    int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
//		int res=0;
//		for(int i=0;i<A.size();i++)
//			for(int j=0;j<B.size();j++)
//				for(int k=0;k<C.size();k++)
//					for(int l=0;l<D.size();l++)
//					{
//						if(A[i]+B[j]+C[k]+D[l]==0)
//						{
//							res++;
//						}
//					}
//		return res;
//    }
//};

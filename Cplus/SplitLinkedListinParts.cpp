#include<vector>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    vector<ListNode*> splitListToParts(ListNode* root, int k) {
		int len=0;
		ListNode* tmp=root;
		while(tmp)
		{
			len++;
			tmp=tmp->next;
		}
		vector<ListNode*> res;
		tmp=root;
		if(len<=k)
		{
			while(tmp)
			{
				res.push_back(tmp);
				tmp=advance(tmp,1);
			}
			for(int i=0;i<k-len;i++)
			{
				res.push_back(NULL);
			}
		}
		else
		{
			int remain=len%k;
			int step=len/k;
			for(int i=0;i<remain;i++)
			{
				res.push_back(tmp);
				tmp=advance(tmp,step+1);
			}
			res.push_back(tmp);
			for(int i=0;i<k-remain-1;i++)
			{
				tmp=advance(tmp,step);
				res.push_back(tmp);
			}
		}
		return res;
    }

	ListNode* advance(ListNode* l,int n)
	{
		ListNode* t=l;
		l=l->next;
		for(int i=1;i<n;i++)
		{
			t=t->next;
			l=l->next;
		}
		t->next=NULL;
		return l;
	}
};

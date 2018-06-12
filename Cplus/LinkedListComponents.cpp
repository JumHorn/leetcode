#include<iostream>
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
    int numComponents(ListNode* head, vector<int>& G) {
        vector<int> v;
		while(head!=NULL)
		{
			v.push_back(head->val);
			head=head->next;
		}
		for(int i=0;i<G.size();i++)
		{
			for(int j=0;j<v.size();j++)
			{
				if(G[i]==v[j])
				{
					v[j]=-1;
					break;
				}
			}
		}
		int res=0;
		for(int i=0;i<v.size();i++)
		{
			if(v[i]==-1)
			{
				res++;
				do
				{
					i++;
				}
				while(i<v.size()&&v[i]==-1);
			}
		}	
		return res;
    }
};

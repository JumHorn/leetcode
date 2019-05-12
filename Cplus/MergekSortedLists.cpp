#include<vector>
#include<queue>
using namespace std;

//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode* res=NULL,*tmp=NULL;
        if(lists.empty())
            return res;
        priority_queue<pair<int,ListNode*> > q;
		for(int i=0;i<(int)lists.size();i++)
            if(lists[i]!=NULL)
			    q.push({-lists[i]->val,lists[i]});
        if(q.empty())
            return res;
		res=q.top().second;
		q.pop();
		if(res->next!=NULL)
			q.push({-res->next->val,res->next});
		tmp=res;
		while(!q.empty())
		{
			tmp->next=q.top().second;
			tmp=tmp->next;
			q.pop();
			if(tmp->next!=NULL)
				q.push({-tmp->next->val,tmp->next});
		}
		return res;
    }
};



#include<unordered_map>
#include<vector>
using namespace std;
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node() {}

    Node(int _val, Node* _next, Node* _random) {
        val = _val;
        next = _next;
        random = _random;
    }
};

class Solution {
public:
    Node* copyRandomList(Node* head) {
        unordered_map<Node*,int> nodetoindex;//src node list
		unordered_map<int,Node*> indextonode;//dst node list
		vector<pair<int,int>> random;
		int index=0;
		Node* tmp=head;
		Node* res=new Node(0,NULL,NULL);//dumzy node
		Node* tmpnew=res;
		while(tmp!=NULL)
		{
			nodetoindex[tmp]=index;
			tmpnew->next=new Node(tmp->val,NULL,NULL);
			tmpnew=tmpnew->next;
			indextonode[index]=tmpnew;
			tmp=tmp->next;
			index++;
		}
		tmp=head;
		while(tmp!=NULL)
		{
			if(tmp->random!=NULL)
				random.push_back({nodetoindex[tmp],nodetoindex[tmp->random]});
			tmp=tmp->next;
		}
		for(int i=0;i<(int)random.size();i++)
			indextonode[random[i].first]->random=indextonode[random[i].second];
		return res->next;
    }
};

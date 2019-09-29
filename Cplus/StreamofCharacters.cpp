#include<vector>
#include<string>
using namespace std;

class StreamChecker {
	struct TreeNode
	{
		int count;
		TreeNode* node[26];
		TreeNode():count(0),node({NULL}){}
	};

	TreeNode* root;

	void insert(const string& str)
	{
		TreeNode* tmp=root;
		for(int i=str.length()-1;i>=0;i--)
		{
            if(tmp->node[str[i]-'a']==NULL)
			    tmp->node[str[i]-'a']=new TreeNode();
			tmp=tmp->node[str[i]-'a'];
		}
		++tmp->count;
	}

	bool search()
	{
		TreeNode* tmp=root;
		for(int i=v.size()-1;i>=0;i--)
		{
			tmp=tmp->node[v[i]-'a'];
			if(tmp==NULL)
				return false;
			if(tmp->count>0)
				return true;
		}
		return false;
	}
	
	vector<char> v;
public:
    StreamChecker(vector<string>& words) {
		v.clear();
        root=new TreeNode();
		for(int i=0;i<(int)words.size();i++)
			insert(words[i]);
    }
    
    bool query(char letter) {
        v.push_back(letter);
		return search();
    }
};

/**
 * Your StreamChecker object will be instantiated and called as such:
 * StreamChecker* obj = new StreamChecker(words);
 * bool param_1 = obj->query(letter);
 */
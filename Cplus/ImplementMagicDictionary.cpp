#include<iostream>
#include<vector>
#include<string>
using namespace std;

class MagicDictionary {
public:
	vector<string> dict;
    /** Initialize your data structure here. */
    MagicDictionary() {
        
    }
    
    /** Build a dictionary through a list of words */
    void buildDict(vector<string> dict) {
        this->dict=dict;
    }
    
    /** Returns if there is any word in the trie that equals to the given word after modifying exactly one character */
    bool search(string word) {
       for(vector<string>::iterator iter=dict.begin();iter!=dict.end();iter++)
	   {
		   if(iter->length()==word.length())
		   {
			   int diff=0;
			   for(int i=0;i<iter->length();i++)
			   {
				   if((*iter)[i]!=word[i])
				   {
					   diff++;
					   if(diff>=2)
					   	   break;
				   }
			   }
			   if(diff==1)
			   {
				   return true;
			   }
		   }
	   }
	   return false;
    }
};

/**
 * Your MagicDictionary object will be instantiated and called as such:
 * MagicDictionary obj = new MagicDictionary();
 * obj.buildDict(dict);
 * bool param_2 = obj.search(word);
 */

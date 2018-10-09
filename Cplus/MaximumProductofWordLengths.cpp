#include<vector>
#include<string>
#include<algorithm>
using namespace std;

class Solution {
public:
    int maxProduct(vector<string>& words) {
		int res=0;
		sort(words.begin(),words.end(),comp);
		for(vector<string>::iterator iter=words.begin();iter!=words.end();iter++)
		{
			for(vector<string>::iterator it=iter+1;it!=words.end();it++)
			{
				int tmp=iter->length()*it->length();
				if(res>=tmp)
				{
					break;
				}
				if(diff(*iter,*it))
				{
					res=res>tmp?res:tmp;
				}
			}
		}
		return res;
    }
	static bool comp(const string& s1,const string& s2)
	{
		return s1.length()>s2.length();
	}

	bool diff(const string& s1,const string& s2) const
	{
		char hasharray[26]={0};
		for(string::const_iterator iter=s1.begin();iter!=s1.end();iter++)
		{
			hasharray[*iter-'a']=1;
		}
		for(string::const_iterator iter=s2.begin();iter!=s2.end();iter++)
		{
			if(hasharray[*iter-'a']==1)
			{
				return false;
			}
		}
		return true;
	}
};


//public class Solution {
//    public int maxProduct(String[] words) {
//        int max = 0;
//
//        Arrays.sort(words, new Comparator<String>(){
//            public int compare(String a, String b){
//                return b.length() - a.length();
//            }
//        });
//
//        int[] masks = new int[words.length]; // alphabet masks
//
//        for(int i = 0; i < masks.length; i++){
//            for(char c: words[i].toCharArray()){
//                masks[i] |= 1 << (c - 'a');
//            }
//        }
//
//        for(int i = 0; i < masks.length; i++){
//            if(words[i].length() * words[i].length() <= max) break; //prunning
//            for(int j = i + 1; j < masks.length; j++){
//                if((masks[i] & masks[j]) == 0){
//                    max = Math.max(max, words[i].length() * words[j].length());
//                    break; //prunning
//                }
//            }
//        }
//
//        return max;
//    }
//}

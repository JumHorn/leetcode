#include <vector>
using namespace std;

class Solution
{
public:
	bool validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild)
	{
		vector<int> in(n);
		for (int i = 0; i < n; i++)
		{
			if (leftChild[i] != -1)
				in[leftChild[i]]++;
			if (rightChild[i] != -1)
				in[rightChild[i]]++;
		}
		int count = 0;
		for (int i = 0; i < n; i++)
		{
			if (in[i] != 1)
			{
				if (in[i] != 0)
					return false;
				count++;
			}
		}
		return count == 1;
	}
};

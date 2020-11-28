#include <algorithm>
#include <vector>
using namespace std;

class Solution
{
public:
	int kthSmallest(vector<vector<int>> &mat, int k)
	{
		vector<int> v(k), heap(k);
		int vsize = 1, heapsize = 0;
		for (auto &m : mat)
		{
			for (auto n : m)
			{
				for (int l = 0; l < vsize; ++l)
				{
					int val = n + v[l];
					if (heapsize >= k)
					{
						if (val < heap[0])
						{
							pop_heap(heap.begin(), heap.begin() + heapsize--);
							heap[heapsize++] = val;
							push_heap(heap.begin(), heap.begin() + heapsize);
						}
					}
					else
					{
						heap[heapsize++] = val;
						push_heap(heap.begin(), heap.begin() + heapsize);
					}
				}
			}
			copy(heap.begin(), heap.begin() + heapsize, v.begin());
			vsize = heapsize;
			heapsize = 0;
		}
		return heap[0];
	}
};
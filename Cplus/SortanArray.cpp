#include <algorithm>
#include <vector>
using namespace std;

class Solution
{
public:
	vector<int> sortArray(vector<int> &nums)
	{
		//merge sort
		//vector<int> dup(nums.size());
		//divide(nums, dup, 0, nums.size());

		// quick sort
		quickSort(nums.begin(), nums.end());
		//library quick sort
		//sort(nums.begin(), nums.end());

		//radix sort(negative number fault)
		//radixSort(nums);
		return nums;
	}

	//quick sort
	void quickSort(vector<int>::iterator first, vector<int>::iterator last)
	{
		if (distance(first, last) <= 1)
			return;
		vector<int>::iterator left = first, right = last - 1;
		int pivot = *first;
		while (distance(left, right) > 0)
		{
			while (distance(left, right) > 0 && *right >= pivot)
				--right;
			*left = *right;
			while (distance(left, right) > 0 && *left <= pivot)
				++left;
			*right = *left;
		}
		*left = pivot;
		quickSort(first, left);
		quickSort(left + 1, last);
	}
	/********end of quick sort********/

	//divide and conquer
	void merge(vector<int> &arr, vector<int> &dup, int first, int mid, int last)
	{
		for (int i = first, j = mid, d = 0; i < mid || j < last;)
		{
			if (i == mid)
				dup[d++] = arr[j++];
			else if (j == last)
				dup[d++] = arr[i++];
			else
				dup[d++] = (arr[i] > arr[j]) ? arr[j++] : arr[i++];
		}
		for (int i = first, j = 0; i < last; ++i, ++j)
			arr[i] = dup[j];
	}

	void divide(vector<int> &arr, vector<int> &dup, int first, int last)
	{
		if (last - first <= 1)
			return;
		int mid = first + (last - first) / 2;
		divide(arr, dup, first, mid);
		divide(arr, dup, mid, last);
		//to do
		merge(arr, dup, first, mid, last);
	}
	/********end of divide and conquer********/

	//radix sort 10 based system
	void radixSort(vector<int> &data, int first, int last, bool ascending = true)
	{
		int maxval = *max_element(data.begin(), data.end());
		int exp = 1;	//1, 10, 100 ...
		int radix = 10; //10 based system
		int size = last - first;
		vector<int> aux(size);

		/* LSD Radix Sort */
		while (maxval / exp > 0) //go through all digits from LSD to MSD
		{
			vector<int> count(radix);
			for (int i = first; i < last; ++i)
				++count[data[i] / exp % radix];
			if (ascending)
			{
				for (int i = 1; i < radix; ++i)
					count[i] += count[i - 1];
			}
			else
			{
				for (int i = radix - 2; i >= 0; --i)
					count[i] += count[i + 1];
			}
			for (int i = last - 1; i >= first; --i)
				aux[--count[data[i] / exp % radix]] = data[i];
			for (int i = first; i < last; ++i)
				data[i] = aux[i - first];
			exp *= 10;
		}
	}

	void radixSort(vector<int> &data)
	{
		int N = data.size();
		int i = 0;
		for (int j = N - 1; i < j;)
		{
			if (data[i] < 0)
				++i;
			else if (data[j] >= 0)
				--j;
			else
				swap(data[i++], data[--j]);
		}
		radixSort(data, 0, i, false);
		radixSort(data, i, N);
	}
	/********end of radix sort 10 based system********/
};
#include <string>
#include <vector>
using namespace std;

class Solution
{
public:
	string decodeCiphertext(string encodedText, int rows)
	{
		int N = encodedText.length(), cols = N / rows;
		vector<vector<char>> matrix(rows, vector<char>(cols));
		int i = 0, j = 0;
		for (auto c : encodedText)
		{
			if (j == cols)
				++i, j = 0;
			matrix[i][j++] = c;
		}
		int prej = 0;
		string res;
		for (i = 0, j = 0;; ++i, ++j)
		{
			if (i >= rows || j >= cols)
				i = 0, j = ++prej;
			if (j >= cols)
				break;
			res.push_back(matrix[i][j]);
		}
		while (!res.empty() && res.back() == ' ')
			res.pop_back();
		return res;
	}
};
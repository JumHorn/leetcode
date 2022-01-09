#include <string>
using namespace std;

class Solution
{
public:
	string capitalizeTitle(string title)
	{
		int N = title.size();
		for (int i = 0, j = 0; i < N; ++i)
		{
			if (title[i] == ' ')
				continue;
			j = i;
			for (; i < N; ++i)
			{
				if (title[i] == ' ')
					break;
				title[i] = tolower(title[i]);
			}

			if (i - j > 2)
				title[j] = toupper(title[j]);
		}
		return title;
	}
};
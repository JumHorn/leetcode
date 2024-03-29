#include <vector>
using namespace std;

class Solution
{
public:
	int minNumberOfHours(int initialEnergy, int initialExperience, vector<int> &energy, vector<int> &experience)
	{
		int res = 0, N = energy.size();
		for (int i = 0; i < N; ++i)
		{
			if (initialEnergy <= energy[i])
			{
				res += energy[i] - initialEnergy + 1;
				initialEnergy = energy[i] + 1;
			}
			if (initialExperience <= experience[i])
			{
				res += experience[i] - initialExperience + 1;
				initialExperience = experience[i] + 1;
			}
			initialEnergy -= energy[i];
			initialExperience += experience[i];
		}
		return res;
	}
};
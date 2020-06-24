#include <map>
#include <string>
using namespace std;

class Solution
{
public:
	string countOfAtoms(string formula)
	{
		map<string, int> atoms = recursion(formula, 0, formula.length());
		string res;
		for (auto &n : atoms)
			res += n.first + (n.second <= 1 ? "" : to_string(n.second));
		return res;
	}

	map<string, int> recursion(const string &formula, int start, int end)
	{
		map<string, int> atoms;
		if (start >= end)
			return atoms;
		int i = start, j = start;
		while (i < end)
		{
			if (formula[i] == '(')
			{
				//match parenthesis
				j = i + 1;
				int parenthesis = 1;
				while (j < end)
				{
					if (formula[j] == '(')
						parenthesis++;
					else if (formula[j] == ')')
						parenthesis--;
					if (parenthesis == 0)
						break;
					j++;
				}

				map<string, int> subatoms = recursion(formula, i + 1, j);
				j++;
				i = j;
				while (j < end && isdigit(formula[j]))
					j++;
				if (j > i)
				{
					int subscript = stoi(formula.substr(i, j - i));
					enlargMap(subatoms, subscript);
					i = j;
				}
				mergeMap(atoms, subatoms);
			}
			else
			{
				j = i + 1;
				while (j < end && islower(formula[j]))
					j++;
				string atomstr = formula.substr(i, j - i);
				i = j;
				while (j < end && isdigit(formula[j]))
					j++;
				int subscript = 1;
				if (j > i)
				{
					subscript = stoi(formula.substr(i, j - i));
					i = j;
				}
				atoms[atomstr] += subscript;
			}
		}
		return atoms;
	}

	void mergeMap(map<string, int> &atoms, map<string, int> &subatoms)
	{
		for (auto &n : subatoms)
			atoms[n.first] += n.second;
	}

	void enlargMap(map<string, int> &atoms, int subscript)
	{
		for (auto &n : atoms)
			n.second *= subscript;
	}
};
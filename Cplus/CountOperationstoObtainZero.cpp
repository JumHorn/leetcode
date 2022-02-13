class Solution
{
public:
	int countOperations(int num1, int num2)
	{
		if (num1 <= 0)
			return 0;
		return countOperations(num2 % num1, num1) + num2 / num1;
	}
};
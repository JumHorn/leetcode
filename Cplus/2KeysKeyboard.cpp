class Solution {
public:
    int minSteps(int n) {
    	if(n==1)
			return 0;
		int m=n;
		for(int i=2;i*i<=n;i++)
		{
			if(n%i==0)
			{
				int tmp=i+minSteps(n/i);
				if(m>tmp)
					m=tmp;
			}

		}
		return m;
    }
};




int minAddToMakeValid(char * S){
	int left=0,res=0;
	while(*S)
	{
		if(*S=='(')
			left++;
		else if(*S==')')
		{
			if(left>0)
				left--;
			else
				res++;
		}
		++S;
	}
	return res+left;
}




char * removeOuterParentheses(char * S){
	char* p1=S,*p2=S;
	int count=0;
	while(*p2)
	{
		if(*p2=='(')
		{
			if(count!=0)
				*p1++=*p2;
			count++;
		}
		else if(*p2==')')
		{
			count--;
			if(count!=0)
				*p1++=*p2;
		}
		p2++;
	}
	*p1='\0';
	return S;
}
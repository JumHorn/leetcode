char * removeDuplicates(char * S){
	char *p,*q;
	p=S;
	q=S+1;
	while(*q)
	{
		if(*p=='0')
		{
			*p=*q;
		}
		else
		{
			if(*p==*q)
			{
				if(p==S)
					*p='0';
				else
					p--;
			}
			else
			{
				p++;
				*p=*q;
			}
		}
		q++;
	}
	if(*p!='0')
		p++;
	*p='\0';
	return S;
}

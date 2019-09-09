char * removeDuplicates(char * S){
	char *p,*q;
	bool flag=true;
	while(flag)
	{
		p=S;
		q=S;
        flag=false;
		while(*p&&*p=='0')
			p++;
        if(!*p)
            break;
		q=p+1;
		while(*q)
		{
			while(*q&&*q=='0')
				q++;
			if(*q&&*p==*q)
			{
				*p='0';
				*q='0';
				flag=true;
				break;
			}
			if(*q&&*p!=*q)
			{
				p=q;
				q++;
			}
		}
	}
	p=S;
	q=S;
	while(*q)
	{
		if(*q!='0')
			*p++=*q;
		q++;
	}
	*p='\0';
	return S;
}



char * removeDuplicates(char * s, int k){
	char* p=s,*top=s;
	while(*p)
	{
		int count=0;
		char c=*p;
		char *q=top;
		while(q!=s)
		{
			--q;
			if(*q==c)
				count++;
			else
				break;
			if(count==k)
				break;
		}
		char *p1=p;
		while(*p1&&*p1==c&&count!=k)
		{
			p1++;
			count++;
		}
		if(count<k)
		{
			if(p!=top)
			{
				while(p!=p1)
					*top++=*p++;
			}
			else
				top=p1;
		}
		else
		{
			if(q==s&&*s==c)
				top=q;
			else
				top=q+1;
		}
		
		p=p1;
	}
	*top='\0';
	return s;
}
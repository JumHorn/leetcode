

bool isLongPressedName(char * name, char * typed){
	char *p=name,*q=typed;
	while(*p&&*q)
	{
		if(*p==*q)
		{
			p++;
			q++;
		}
		else
		{
			if(p!=name&&*q==*(p-1))
				q++;
			else
				break;
		}
	}
	while(!*p&&*q&&p!=name&&*q==*(p-1))
		q++;
	return !*p&&!*q;
}

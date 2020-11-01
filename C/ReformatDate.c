#include <stdio.h>
#include <string.h>

#define ARRAY_SIZE(x) (sizeof(x) / sizeof((x)[0]))

int getMonth(char *mon)
{
	char *month[] = {"Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"};
	for (int i = 0; i < ARRAY_SIZE(month); ++i)
	{
		if (strcmp(month[i], mon) == 0)
			return i + 1;
	}
	return 0;
}

char *reformatDate(char *date)
{
	char day[10], month[10], year[10];
	sscanf(date, "%s %s %s", day, month, year);
	int mon = getMonth(month);
	int d = day[0] - '0';
	if (day[1] >= '0' && day[1] <= '9')
		d = d * 10 + day[1] - '0';
	sprintf(date, "%s-%02d-%02d", year, mon, d);
	return date;
}
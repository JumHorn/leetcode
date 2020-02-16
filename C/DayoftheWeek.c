
char* dayOfTheWeek(int day, int month, int year)
{
	char* week[] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};
	int mon[13] = {0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334, 365};
	int y = 1971, w = 4, diff = 0;
	diff += (year - y) * 365;
	//case not considered
	//hundred year may not a leap year
	if (year > 1972)
	{
		diff += (year - 1972) / 4;
		if (year % 4 == 0)
			--diff;
	}
	if (year % 4 == 0 && month > 2)
		diff++;
	diff += mon[month - 1];
	diff += day;
	diff += w;
	diff %= 7;
	return week[diff];
}


#include <sstream>
#include <string>
using namespace std;

class Solution
{
public:
	string validIPAddress(string IP)
	{
		int ip = checkIPversion(IP);
		if (ip == 4)
		{
			if (checkV4(IP))
				return "IPv4";
		}
		else if (ip == 6)
		{
			if (checkV6(IP))
				return "IPv6";
		}
		return "Neither";
	}

	bool checkV4(const string &ip)
	{
		stringstream ss(ip);
		string segment;
		char dot;
		int size = 0;
		while (getline(ss, segment, '.'))
		{
			++size;
			if (segment.empty())
				return false;
			for (auto c : segment)
			{
				if (c < '0' || c > '9')
					return false;
			}
			int val = stoi(segment);
			if (val < 0 || val > 255 || to_string(val) != segment)
				return false;
		}
		return size == 4 && ip.back() != '.';
	}

	bool checkV6(const string &ip)
	{
		stringstream ss(ip);
		string segment;
		char dot;
		int size = 0;
		while (getline(ss, segment, ':'))
		{
			++size;
			if (segment.empty() || segment.size() > 4)
				return false;
			for (auto c : segment)
			{
				c = toupper(c);
				if (!((c >= '0' && c <= '9') || (c >= 'A' && c <= 'F')))
					return false;
			}
		}
		return size == 8 && ip.back() != ':';
	}

	int checkIPversion(const string &ip)
	{
		int count = 0;
		for (auto c : ip)
		{
			if (c == '.')
				return 4;
			if (c == ':')
				return 6;
			++count;
			if (count >= 5)
				break;
		}
		return -1;
	}
};
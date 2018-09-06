#include<iostream>
#include<string>
using namespace std;

// Symbol       Value
// I             1
// V             5
// X             10
// L             50
// C             100
// D             500
// M             1000

class Solution {
public:
    string intToRoman(int num) {
		string roman;
		int t=num/1000;
		for(int i=0;i<t;i++)
		{
			roman+="M";
		}	
		num=num%1000;	
		roman+=makeRoman(num/100,"M","D","C");
		num=num%100;	
		roman+=makeRoman(num/10,"C","L","X");
		num=num%10;	
		roman+=makeRoman(num,"X","V","I");
		return roman;
    }

	string makeRoman(int num,const string& big,const string& middle,const string& small)
	{
		string roman;
		switch(num)
		{
		case 1:
			roman=small;
		break;
		case 2:
			roman=small+small;
		break;
		case 3:
			roman=small+small+small;
		break;
		case 4:
			roman=small+middle;
		break;
		case 5:
			roman=middle;
		break;
		case 6:
			roman=middle+small;
		break;
		case 7:
			roman=middle+small+small;
		break;
		case 8:
			roman=middle+small+small+small;
		break;
		case 9:
			roman=small+big;
		break;
		}
		return roman;
	}
};
